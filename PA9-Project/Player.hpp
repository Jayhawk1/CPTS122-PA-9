#pragma once
#include <SFML/Graphics.hpp>
#include "Color.hpp"
#include "Entity.hpp"
#include "Projectil.hpp"


class Player : public Entity {
private:
    ColorType color1, color2;
    bool usingFirst;
    float health;
    std::vector<Projectile> projectiles;
    sf::Vector2f lastDirection;

public:
    Player();
    void draw(sf::RenderWindow& window);
    void updateProjectiles();
    void update() override;
    void swapColor();
    void newColor(ColorType newColor);
    ColorType getCurrentColor();
    void takeDamage(ColorType enemyColor);
    void projectile(ColorType projectilColor);
};