#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity {
protected:
    sf::CircleShape shape;
    bool iFrames;

 
public:
    virtual void draw(sf::RenderWindow& window);

    sf::CircleShape& getShape();


    virtual ~Entity() {}

	template <typename E>
    bool Collision(E& entity) {
        if (getShape().getGlobalBounds().findIntersection(entity.getShape().getGlobalBounds())) {
            std::cout << "Collision detected!" << std::endl;
            return true;
        }
    }

    void setIFrames(bool TF) {
        iFrames = TF;
    }

    bool getIFrames() {
        return iFrames;
    }
};
