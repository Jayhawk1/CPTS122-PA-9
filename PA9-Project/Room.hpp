#pragma once
#include "Obstacle.hpp"
#include "Door.hpp"
#include "Pickup.hpp"
#include "Color.hpp"



class Room {
protected:
	Obstacle NWall;
	Obstacle SWall;
	Obstacle EWall;
	Obstacle WWall;

public:



	// Obstacle(int mShape, float posX, float posY, float sizeX, float sizeY, sf::Color outline, sf::Color fill)

	//2, 10, 10, 800, 50, sf::Color::White, sf::Color::White); // 1 = CIRCLE, 2 = RECTANGLE

	Room() {
		buildWalls();
	}


	void drawWalls(sf::RenderWindow& window);

	void buildWalls();

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
		else if (player.getShape().getGlobalBounds().findIntersection(SWall.returnRec().getGlobalBounds())) {
			std::cout << "Collision detected!" << std::endl;
			return true;
		}
		else if (player.getShape().getGlobalBounds().findIntersection(WWall.returnRec().getGlobalBounds())) {
			std::cout << "Collision detected!" << std::endl;
			return true;
		}
		else if (player.getShape().getGlobalBounds().findIntersection(EWall.returnRec().getGlobalBounds())) {
			std::cout << "Collision detected!" << std::endl;
			return true;
		}
	}

};