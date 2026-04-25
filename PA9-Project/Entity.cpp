#include "Entity.hpp"

Entity::Entity() {
    
}

void Entity::draw(sf::RenderWindow& window) {

    window.draw(shape);
}

sf::CircleShape& Entity::getShape() {

    return shape;
}