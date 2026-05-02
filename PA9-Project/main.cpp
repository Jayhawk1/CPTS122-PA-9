#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Pickup.hpp"
#include "Entity.hpp"
#include "Room.hpp"
#include "Walker.hpp"
#include "GameState.hpp"
#include <SFML/Audio.hpp>

// ---------------- FONT LOADING ----------------
std::vector<char> fontBuffer;

sf::Font loadFontSafely(const std::filesystem::path& path) {
    sf::Font font;

    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cout << "File failed to open\n";
        return font;
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    fontBuffer.resize(size);

    if (!file.read(fontBuffer.data(), size)) {
        std::cout << "File read failed\n";
        return font;
    }

    if (!font.openFromMemory(fontBuffer.data(), fontBuffer.size())) {
        std::cout << "Font failed to load from memory\n";
    }

    return font;
}

// ---------------- MUSIC LOADING ----------------
std::vector<char> musicBuffer;

bool loadMusicSafely(sf::Music& music, const std::filesystem::path& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "Music file failed to open\n";
        return false;
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    musicBuffer.resize(size);
    if (!file.read(musicBuffer.data(), size)) return false;

    if (!music.openFromMemory(musicBuffer.data(), musicBuffer.size())) {
        std::cerr << "Music failed to load from memory\n";
        return false;
    }

    return true;
}

// ---------------- MAIN ----------------
int main() {
    EntityList<Entity> Entities = EntityList<Entity>();

    // MUSIC
    sf::Music backgroundMusic;
    std::filesystem::path musicPath =
        R"(C:\Users\andre\source\repos\mainrollbackdownload\audio.ogg)";

    if (loadMusicSafely(backgroundMusic, musicPath)) {
        backgroundMusic.setLooping(true);
        backgroundMusic.setVolume(100.f);
        backgroundMusic.play();
    }

    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Game");

    // FONT
    std::filesystem::path fontPath =
        R"(C:\Users\andre\source\repos\mainrollbackdownload\PA9-Project\static\Roboto-Regular.ttf)";

    sf::Font font = loadFontSafely(fontPath);

    if (font.getInfo().family == "") {
        std::cout << "FAILED FONT LOAD\n";
        return -1;
    }

    // TEXT UI
    sf::Text title(font);
    title.setString("Welcome to Paint Blaster");
    title.setCharacterSize(80);
    title.setFillColor(sf::Color::White);
    title.setPosition({ 175.f, 100.f });

    sf::Text playText(font);
    playText.setString("Press ENTER - Play");
    playText.setCharacterSize(40);
    playText.setFillColor(sf::Color::White);
    playText.setPosition({ 450.f, 300.f });

    sf::Text exitText(font);
    exitText.setString("Press ENTER - Exit");
    exitText.setCharacterSize(40);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition({ 450.f, 400.f });

    // SELECTOR
    sf::RectangleShape selector({ 400.f, 60.f });
    selector.setFillColor(sf::Color::Transparent);
    selector.setOutlineThickness(5.f);
    selector.setOutlineColor(sf::Color::Yellow);

    int menuIndex = 0;
    GameState state = GameState::Menu;

    // GAME OBJECTS
    EntityList<Entity> Entities;
    Player player;

    Pickup paint(RED, { 700, 500 });
    Pickup paint1(YELLOW, { 200, 600 });
    bool shot = false;
    WalkerEnemy enemy(BLUE, { 300, 200 });
    // Obstacle(int mShape, float posX, float posY, float sizeX, float sizeY, sf::Color outline, sf::Color fill)
    Room testRoom;

    Entities.insertEntity(player);
    Entities.insertEntity(enemy);

    Entities.insertEntity(player);
    Entities.insertEntity(enemy);

    bool iFrames = false;
    bool shot = false;

    // ---------------- GAME LOOP ----------------
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>())
                window.close();

            // ---------------- MENU ----------------
            if (state == GameState::Menu) {
                if (event->is<sf::Event::KeyPressed>()) {
                    auto key = event->getIf<sf::Event::KeyPressed>()->code;

                    if (key == sf::Keyboard::Key::Up) menuIndex = 0;
                    if (key == sf::Keyboard::Key::Down) menuIndex = 1;

                    if (key == sf::Keyboard::Key::Enter) {
                        if (menuIndex == 0) state = GameState::Playing;
                        if (menuIndex == 1) window.close();
                    }
                }
            }

            // ---------------- PLAYING ----------------
            if (state == GameState::Playing && event->is<sf::Event::KeyPressed>()) {
                auto key = event->getIf<sf::Event::KeyPressed>()->code;

        //        if (!player.getShape().getGlobalBounds().findIntersection(enemy.getShape().getGlobalBounds())) {
          //          player.setIFrames(false);
      
    //}

                                // RETURN TO MENU (NEW FEATURE)
                if (key == sf::Keyboard::Key::Escape ||
                    key == sf::Keyboard::Key::Q)
                {
                    title.setString("-Paused-");
                    title.setPosition({ 485.f, 100.f });
                    state = GameState::Menu;
                }

                // GAME ACTION
                if (key == sf::Keyboard::Key::R)
                    player.swapColor();
            }
        }


        player.update(enemy); // Current passthrough allows check for Collision
        player.update(testRoom);
        player.update(paint);
		player.update(paint1);
        enemy.update();

        for (int i = 0; i < Entities.getEntityCount(); i++) {
            Entities.getEntity(i)->update();
        }


        // ---------------- LOGIC ----------------
        if (state == GameState::Playing) {
            for (int i = 0; i < Entities.getEntityCount(); i++)
                Entities.getEntity(i)->update();

            player.update();
            enemy.update();
        }

            for (int i = 0; i < Entities.getEntityCount(); i++)
                Entities.getEntity(i)->update();

           /* if (player.getShape().getGlobalBounds()
                .findIntersection(enemy.getShape().getGlobalBounds()) && !iFrames)
            {
                player.takeDamage(enemy.getColor());
                iFrames = true;
            }
            

            if (!player.getShape().getGlobalBounds()
                .findIntersection(enemy.getShape().getGlobalBounds()))
            {
                iFrames = false;
            }

            // Pick-Up Collision
            if (player.getShape().getGlobalBounds()
                .findIntersection(paint.getShape().getGlobalBounds()))
            {
                player.newColor(paint.getColor());
                player.swapColor();
                player.swapColor();
            }

            if (player.getShape().getGlobalBounds()
                .findIntersection(paint1.getShape().getGlobalBounds()))
            {
                player.newColor(paint1.getColor());
                player.swapColor();
                player.swapColor();
            }
            */
            
       /*     // Pickup collison
        if (player.getShape().getGlobalBounds().findIntersection(paint.getShape().getGlobalBounds())) {
            std::cout << "Collision detected!" << std::endl;
            player.newColor(paint.getColor());
            
        }
        if (player.getShape().getGlobalBounds().findIntersection(paint1.getShape().getGlobalBounds())) {
            std::cout << "Collision detected!" << std::endl;
            player.newColor(paint1.getColor());

        }
        */


        window.clear();

        if (player.alive()) {
            player.draw(window);
        }

        if (enemy.alive()) {
            enemy.draw(window);
        }

        // SHOOTING
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !shot) {
 
            player.projectile(player.getCurrentColor(), { 0.f, -1.f }, enemy.getColor());
            shot = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !shot) {
            player.projectile(player.getCurrentColor(), { 0.f, 1.f }, enemy.getColor());
            shot = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !shot) {
            player.projectile(player.getCurrentColor(), { -1.f, 0.f }, enemy.getColor());
            shot = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !shot) {
            player.projectile(player.getCurrentColor(), { 1.f, 0.f },enemy.getColor());
            shot = true;
        }


        // do not allow a shooting more than once per key press
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            shot = false;
        }

        // ---------------- RENDER ----------------
        window.clear(sf::Color::Black);

        if (state == GameState::Menu) {
            selector.setPosition(
                menuIndex == 0 ?
                sf::Vector2f(435.f, 310.f) :
                sf::Vector2f(435.f, 390.f)
            );
            
            window.draw(title);
            window.draw(playText);
            window.draw(exitText);
            window.draw(selector);
            
        }
        else {
            if (player.alive()) player.draw(window);
            if (enemy.alive()) enemy.draw(window);
            paint.draw(window);
            paint1.draw(window);
        }

        testRoom.drawWalls(window);

        window.display();
    }

    return 0;
}