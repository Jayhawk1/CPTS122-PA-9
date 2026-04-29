#pragma once
#include "Obstacle.hpp"
#include "Door.hpp"


class Room {
protected:
	Obstacle NWall;

public:



	// Obstacle(int mShape, float posX, float posY, float sizeX, float sizeY, sf::Color outline, sf::Color fill)

	//2, 10, 10, 800, 50, sf::Color::White, sf::Color::White); // 1 = CIRCLE, 2 = RECTANGLE

	Room(int mShape, float posX, float posY, float sizeX, float sizeY, sf::Color outline, sf::Color fill) {
		
		NWall.setShapeType(mShape);
		NWall.setFill(fill);
		NWall.setOutline(outline);
		NWall.setPosition(posX, posY);
		NWall.setSize(sizeX, sizeY);
		
		
	}

	void drawWalls(sf::RenderWindow& window) {
		NWall.draw(window, NWall.getIsRec());
	}

	virtual ~Room() {

	}

	Obstacle getNWall() {
		return NWall;
	}

	template <typename P>
	bool Collision(P& player) {
		if (player.getShape().getGlobalBounds().findIntersection(NWall.returnRec().getGlobalBounds())) {
			std::cout << "Collision detected!" << std::endl;
			return true;
		}
	}

};