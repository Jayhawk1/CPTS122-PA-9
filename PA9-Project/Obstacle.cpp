#include "Obstacle.hpp"


void Obstacle::draw(sf::RenderWindow& window, const bool& isRec) {

	if (isRec) {
        window.draw(mRec);
    }
    else {
        window.draw(shape);
    }
}