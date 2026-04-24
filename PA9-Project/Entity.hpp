#pragma once
#include <SFML/Graphics.hpp>

class Entity {
protected:
    sf::CircleShape shape;

public:
    virtual void update() = 0; 

    virtual void draw(sf::RenderWindow& window);

    sf::CircleShape& getShape();

    virtual ~Entity() {}
};