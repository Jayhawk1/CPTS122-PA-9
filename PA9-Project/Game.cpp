#include "Game.hpp"
#include <iostream>
#include <fstream>

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

Game::Game()
    : window(sf::VideoMode({ 1280, 720 }), "Game"),
    menuIndex(0),
    state(GameState::Menu),
    enemy(BLUE, { 300, 200 }),
    paint(RED, { 700, 500 }),
    paint1(YELLOW, { 200, 600 }),
    iFrames(false),
    shot(false)
{
    std::filesystem::path musicPath = R"(.\audio.ogg)";
    if (loadMusicSafely(backgroundMusic, musicPath)) {
        backgroundMusic.setLooping(true);
        backgroundMusic.setVolume(100.f);
        backgroundMusic.play();
    }

    std::filesystem::path fontPath = R"(.\static\Roboto-Regular.ttf)";
    font = loadFontSafely(fontPath);

    if (font.getInfo().family == "") {
        std::cout << "FAILED FONT LOAD\n";
        std::exit(-1);
    }

    title = std::make_unique<sf::Text>(font);
    title->setString("Welcome to Paint Blaster");
    title->setCharacterSize(80);
    title->setFillColor(sf::Color::White);
    title->setPosition({ 175.f, 100.f });

    playText = std::make_unique<sf::Text>(font);
    playText->setString("Press ENTER - Play");
    playText->setCharacterSize(40);
    playText->setFillColor(sf::Color::White);
    playText->setPosition({ 450.f, 300.f });

    exitText = std::make_unique<sf::Text>(font);
    exitText->setString("Press ENTER - Exit");
    exitText->setCharacterSize(40);
    exitText->setFillColor(sf::Color::White);
    exitText->setPosition({ 450.f, 400.f });

    selector = sf::RectangleShape({ 400.f, 60.f });
    selector.setFillColor(sf::Color::Transparent);
    selector.setOutlineThickness(5.f);
    selector.setOutlineColor(sf::Color::Yellow);

    Entities.insertEntity(player);
    Entities.insertEntity(enemy);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    while (auto event = window.pollEvent()) {

        if (event->is<sf::Event::Closed>())
            window.close();

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

        if (state == GameState::Playing && event->is<sf::Event::KeyPressed>()) {
            auto key = event->getIf<sf::Event::KeyPressed>()->code;

            if (key == sf::Keyboard::Key::Escape ||
                key == sf::Keyboard::Key::Q)
            {
                title->setString("-Paused-");
                title->setPosition({ 485.f, 100.f });
                state = GameState::Menu;
            }

            if (key == sf::Keyboard::Key::R)
                player.swapColor();
        }
    }
}

void Game::update() {
    if (state == GameState::Playing && player.alive()) {

        for (int i = 0; i < Entities.getEntityCount(); i++)
            Entities.getEntity(i)->update();

        if (player.getShape().getGlobalBounds()
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !shot) {
            player.projectile(player.getCurrentColor(), { 0.f, -1.f });
            shot = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !shot) {
            player.projectile(player.getCurrentColor(), { 0.f, 1.f });
            shot = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !shot) {
            player.projectile(player.getCurrentColor(), { -1.f, 0.f });
            shot = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !shot) {
            player.projectile(player.getCurrentColor(), { 1.f, 0.f });
            shot = true;
        }

        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            shot = false;
        }
    }
    else {
        if (state == GameState::Playing) {
            title->setString("Game Over");
            title->setPosition({ 425.f, 100.f });
            state = GameState::Menu;
        }
    }
}

void Game::render() {
    window.clear(sf::Color::Black);

    if (state == GameState::Menu) {
        selector.setPosition(
            menuIndex == 0 ?
            sf::Vector2f(435.f, 310.f) :
            sf::Vector2f(435.f, 390.f)
        );

        window.draw(*title);
        window.draw(*playText);
        window.draw(*exitText);
        window.draw(selector);
    }
    else {
        if (player.alive()) player.draw(window);
        if (enemy.alive()) enemy.draw(window);
        paint.draw(window);
        paint1.draw(window);
    }

    window.display();
}
