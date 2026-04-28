#include "Entity.hpp"

void Entity::draw(sf::RenderWindow& window) {

    window.draw(shape);
}

sf::CircleShape& Entity::getShape() {

    return shape;
}

