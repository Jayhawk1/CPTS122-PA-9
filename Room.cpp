#include "Room.hpp"

void Room::buildWalls() {

	NWall.setShapeType(2);
	NWall.setFill(sf::Color::White);
	NWall.setOutline(sf::Color::White);
	NWall.setPosition(10.0f, 15.0f);
	NWall.setSize(1250.0f, 10.0f);


	SWall.setShapeType(2);
	SWall.setFill(sf::Color::White);
	SWall.setOutline(sf::Color::White);
	SWall.setPosition(10.0f, 690.0f);
	SWall.setSize(1260.0f, 10.0f);


	WWall.setShapeType(2);
	WWall.setFill(sf::Color::White);
	WWall.setOutline(sf::Color::White);
	WWall.setPosition(10.0f, 15.0f);
	WWall.setSize(10.0f, 680.0f);

	EWall.setShapeType(2);
	EWall.setFill(sf::Color::White);
	EWall.setOutline(sf::Color::White);
	EWall.setPosition(1260.0f, 15.0f);
	EWall.setSize(10.0f, 680.0f);

	Entities.push_back(obstacles.emplace_back(NWall));
	Entities.push_back(obstacles.emplace_back(WWall));
	Entities.push_back(obstacles.emplace_back(SWall));
	Entities.push_back(obstacles.emplace_back(EWall));

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
	int spacer = 0;
	// Obstacle(int mShape ,float posX, float posY, float sizeX, float sizeY, sf::Color outline, sf::Color fill) // 1 = CIRCLE, 2 = RECTANGLE
	for (int i = 0; i < 5; i++) {
		Entities.push_back(obstacles.emplace_back(2, 200, (200 + spacer), 50, 50, toSFMLColor(NONE), toSFMLColor(MAGENTA)));
		spacer += 70;
	}

	//Pickup(ColorType c, sf::Vector2f pos);

	paint.emplace_back(RED, sf::Vector2f(1200, 600));
}

void Room::buildRoom2() {
	int spacer = 0;

	for (int i = 0; i < 4; i++) {
		
	}
	paint.emplace_back(RED, sf::Vector2f(1200, 200));
	paint.emplace_back(YELLOW, sf::Vector2f(1200, 600));
	spacer += 70;
}

void Room::buildRoom3() {
	Entities.push_back(obstacles.emplace_back(2, 400, 20, 10, 680, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(obstacles.emplace_back(2, 800, 20, 10, 680, toSFMLColor(NONE), toSFMLColor(NONE)));
	paint.emplace_back(RED, sf::Vector2f(450, 200));
	paint.emplace_back(BLUE, sf::Vector2f(750, 600));
	paint.emplace_back(YELLOW, sf::Vector2f(600, 400));
	paint.emplace_back(NONE, sf::Vector2f(420, 350));
}

void Room::buildRoom4() {
	Entities.push_back(obstacles.emplace_back(2, 15, 200, 150, 10, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(obstacles.emplace_back(2, 200, 200, 150, 10, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(obstacles.emplace_back(2, 400, 200, 150, 10, toSFMLColor(NONE), toSFMLColor(NONE)));

	Entities.push_back(obstacles.emplace_back(2, 15, 400, 150, 10, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(obstacles.emplace_back(2, 200, 400, 150, 10, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(obstacles.emplace_back(2, 400, 400, 150, 10, toSFMLColor(NONE), toSFMLColor(NONE)));

	Entities.push_back(obstacles.emplace_back(2, 400, 15, 10, 190, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(obstacles.emplace_back(2, 340, 15, 10, 190, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(obstacles.emplace_back(2, 200, 15, 10, 190, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(obstacles.emplace_back(2, 155, 15, 10, 190, toSFMLColor(NONE), toSFMLColor(NONE)));



	Entities.push_back(obstacles.emplace_back(2, 400, 400, 10, 300, toSFMLColor(NONE), toSFMLColor(NONE)));

	Entities.push_back(obstacles.emplace_back(2, 200, 400, 10, 300, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(obstacles.emplace_back(2, 200, 400, 10, 300, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(obstacles.emplace_back(2, 165, 400, 10, 300, toSFMLColor(NONE), toSFMLColor(NONE)));
	Entities.push_back(obstacles.emplace_back(2, 350, 400, 10, 300, toSFMLColor(NONE), toSFMLColor(NONE)));

	paint.emplace_back(RED, sf::Vector2f(1200, 200));
	paint.emplace_back(YELLOW, sf::Vector2f(1200, 600));

}



