#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <filesystem>
#include <vector>
#include <memory>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Pickup.hpp"
#include "Entity.hpp"
#include "Walker.hpp"
#include "GameState.hpp"

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;

    sf::Font font;
    std::unique_ptr<sf::Text> title;
    std::unique_ptr<sf::Text> playText;
    std::unique_ptr<sf::Text> exitText;

    sf::RectangleShape selector;

    int menuIndex;
    GameState state;

    EntityList<Entity> Entities;
    Player player;
    WalkerEnemy enemy;

    Pickup paint;
    Pickup paint1;

    bool iFrames;
    bool shot;

    sf::Music backgroundMusic;

    void processEvents();
    void update();
    void render();
};
