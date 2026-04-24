#pragma once
#include <SFML/Graphics.hpp>
#include"Entity.hpp"
#include"Color.hpp"

class Bullet : public Entity {
private:
    sf::Vector2f velocity;
    ColorType color;

public:
    Bullet(sf::Vector2f pos, ColorType c, sf::Vector2f dir);

    void update() override;
    ColorType getColor();
};