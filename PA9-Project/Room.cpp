#include "Room.hpp"

void Room::buildWalls() {

	obstacles.reserve(4);
	// Obstacle(int mShape ,float posX, float posY, float sizeX, float sizeY, sf::Color outline, sf::Color fill) // 1 = CIRCLE, 2 = RECTANGLE

	NWall = obstacles.emplace_back(2, 10.f, 15.f, 1250.f, 10.f, toSFMLColor(NONE), toSFMLColor(NONE));
	SWall = obstacles.emplace_back(2, 10.f, 690.f, 1260.f, 10.f, toSFMLColor(NONE), toSFMLColor(NONE));
	WWall = obstacles.emplace_back(2, 10.f, 15.f, 10.f, 680.f, toSFMLColor(NONE), toSFMLColor(NONE));
	EWall = obstacles.emplace_back(2, 1260.f, 15.f, 10.f, 680.f, toSFMLColor(NONE), toSFMLColor(NONE));

	Entities.push_back(&NWall);
	Entities.push_back(&WWall);
	Entities.push_back(&SWall);
	Entities.push_back(&EWall);
}

void Room::drawWalls(sf::RenderWindow& window) {
	NWall.draw(window, NWall.getIsRec());
	SWall.draw(window, SWall.getIsRec());
	WWall.draw(window, WWall.getIsRec());
	EWall.draw(window, EWall.getIsRec());



	for (auto& b : obstacles) {
		b.draw(window, b.getIsRec());
	}

	for (auto& p : paint) {
		p.draw(window);
	}

	for (auto& e : Enemies) {
		e.draw(window);
	}
}

void Room::buildRoom1() {
	float spacer = 0.f;
	// Obstacle(int mShape ,float posX, float posY, float sizeX, float sizeY, sf::Color outline, sf::Color fill) // 1 = CIRCLE, 2 = RECTANGLE
	for (int i = 0; i < 5; i++) {
		Obstacle& newObstacle = obstacles.emplace_back(2, 200.f, (200.f + spacer), 50.f, 50.f, toSFMLColor(NONE), toSFMLColor(MAGENTA));
		Entities.push_back(&newObstacle);

		spacer += 70.f;
	}

	//Pickup(ColorType c, sf::Vector2f pos);

	paint.emplace_back(RED, sf::Vector2f(1200.f, 600.f));

	
}

void Room::buildRoom2() {
	float spacer = 0.f;

	for (int i = 0; i < 4; i++) {

	}
	paint.emplace_back(RED, sf::Vector2f(1200.f, 200.f));
	paint.emplace_back(YELLOW, sf::Vector2f(1200.f, 600.f));
	spacer += 70.f;
}

void Room::buildRoom3() {

	obstacles.reserve(2);

	Entities.emplace_back(&obstacles.emplace_back(2, 400.f, 20.f, 10.f, 680.f, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.emplace_back(&obstacles.emplace_back(2, 800.f, 20.f, 10.f, 680.f, toSFMLColor(NONE), toSFMLColor(NONE)));
	paint.emplace_back(RED, sf::Vector2f(450.f, 200.f));
	paint.emplace_back(BLUE, sf::Vector2f(750.f, 600.f));
	paint.emplace_back(YELLOW, sf::Vector2f(600.f, 400.f));
	paint.emplace_back(NONE, sf::Vector2f(420.f, 350.f));
}

void Room::buildRoom4() {
	obstacles.reserve(15);

	// Obstacle(int mShape ,float posX, float posY, float sizeX, float sizeY, sf::Color outline, sf::Color fill) // 1 = CIRCLE, 2 = RECTANGLE
	Entities.push_back(&obstacles.emplace_back(2, 15.0f, 200.0f, 150.0f, 10.0f, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(&obstacles.emplace_back(2, 200.0f, 200.0f, 150.0f, 10.0f, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(&obstacles.emplace_back(2, 400.0f, 200.0f, 150.0f, 10.0f, toSFMLColor(NONE), toSFMLColor(NONE)));

	Entities.push_back(&obstacles.emplace_back(2, 15.0f, 400.0f, 150.0f, 10.0f, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(&obstacles.emplace_back(2, 200.0f, 400.0f, 150.0f, 10.0f, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(&obstacles.emplace_back(2, 400.0f, 400.0f, 150.0f, 10.0f, toSFMLColor(NONE), toSFMLColor(NONE)));

	Entities.push_back(&obstacles.emplace_back(2, 400.0f, 15.0f, 10.0f, 190.0f, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(&obstacles.emplace_back(2, 340.0f, 15.0f, 10.0f, 190.0f, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(&obstacles.emplace_back(2, 200.0f, 15.0f, 10.0f, 190.0f, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(&obstacles.emplace_back(2, 155.0f, 15.0f, 10.0f, 190.0f, toSFMLColor(NONE), toSFMLColor(NONE)));

	Entities.push_back(&obstacles.emplace_back(2, 400.0f, 400.0f, 10.0f, 300.0f, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(&obstacles.emplace_back(2, 200.0f, 400.0f, 10.0f, 300.0f, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(&obstacles.emplace_back(2, 200.0f, 400.0f, 10.0f, 300.0f, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(&obstacles.emplace_back(2, 165.0f, 400.0f, 10.0f, 300.0f, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(&obstacles.emplace_back(2, 350.0f, 400.0f, 10.0f, 300.0f, toSFMLColor(NONE), toSFMLColor(NONE)));

	paint.emplace_back(RED, sf::Vector2f(1200.f, 200.f));
	paint.emplace_back(YELLOW, sf::Vector2f(1200.f, 600.f));

}



