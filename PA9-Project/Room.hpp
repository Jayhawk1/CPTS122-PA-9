#pragma once
#include "Obstacle.hpp"
#include "Door.hpp"
#include "Pickup.hpp"
#include "Color.hpp"
#include "RoomEnum.hpp"
#include "Walker.hpp"

class Room {
protected:
	Obstacle NWall;
	Obstacle SWall;
	Obstacle EWall;
	Obstacle WWall;
	//EntityList<Entity> Entities;
	//EntityList<Obstacle> obstacles;
	//EntityList<Pickup> Entities;
	std::vector<Entity*> Entities;
	std::vector<Enemy> Enemies;
	std::vector<WalkerEnemy> Walkers;
	std::vector<Obstacle> obstacles;
	std::vector<Pickup> paint;




public:

	std::vector<Entity*>& getEntities() {
		return (this->Entities);
	}

	std::vector<Enemy>& getEnemies() {
		return Enemies;
	}

	std::vector<WalkerEnemy>& getWalkers() {
		return Walkers;
	}

	std::vector<Obstacle>& getObstacles() {
		return obstacles;
	}

	std::vector<Pickup>& getPickups() {
		return paint;
	}



	// Obstacle(int mShape, float posX, float posY, float sizeX, float sizeY, sf::Color outline, sf::Color fill)

	//2, 10, 10, 800, 50, sf::Color::White, sf::Color::White); // 1 = CIRCLE, 2 = RECTANGLE

	Room() {
		buildWalls();
	}

	void deleteRoom() {
		Entities.clear();
		Enemies.clear();
		Walkers.clear();
		obstacles.clear();
		paint.clear();

		Entities.shrink_to_fit();
		Enemies.shrink_to_fit();
		Walkers.shrink_to_fit();
		obstacles.shrink_to_fit();
		paint.shrink_to_fit();
	}

	Room(RoomEnum roomType) {

		buildWalls();

		if (roomType == ROOM1) {
			buildRoom1();
		}
		else if (roomType == ROOM2) {
			buildRoom2();
		}
		else if (roomType == ROOM3) {
			buildRoom3();
		}
		else if (roomType == ROOM4) {
			buildRoom4();
		}
		else if (roomType == ROOM5) {
			//buildRoom5();
		}
		else if (roomType == ROOM6) {
			//buildRoom6();
		}
		else if (roomType == ROOM7) {
			//buildRoom7();
		}
		else if (roomType == ROOM8) {
			//buildRoom8();
		}
		else if (roomType == ROOM9) {
			//buildRoom9();
		}
		else if (roomType == ROOM10) {
			//buildRoom10();
		}

	}

	void drawWalls(sf::RenderWindow& window);

	void buildWalls();

	void buildRoom1();

	void buildRoom2();

	void buildRoom3();

	void buildRoom4();

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


	bool checkEnemyCollisions(Enemy* e, std::vector<Obstacle>& obstacles) {
		if (e == nullptr) return false;

		// Use the same math that worked for the player
		sf::FloatRect eBounds = e->getShape().getGlobalBounds();

		for (Obstacle& wall : obstacles) {
			sf::FloatRect wBounds = wall.getShape().getGlobalBounds();

			// Perform the AABB overlap check
			if (eBounds.position.x < wBounds.position.x + wBounds.size.x &&
				eBounds.position.x + eBounds.size.x > wBounds.position.x &&
				eBounds.position.y < wBounds.position.y + wBounds.size.y &&
				eBounds.position.y + eBounds.size.y > wBounds.position.y)
			{
				return true; // Hit a wall!
			}
		}
		return false;
	}

};