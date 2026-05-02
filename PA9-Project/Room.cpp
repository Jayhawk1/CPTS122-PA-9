#include "Room.hpp"

void Room::buildWalls(){

		NWall.setShapeType(2);
		NWall.setFill(sf::Color::White);
		NWall.setOutline(sf::Color::White);
		NWall.setPosition(0.0f, 15.0f);
		NWall.setSize(1260.0f, 10.0f);


		SWall.setShapeType(2);
		SWall.setFill(sf::Color::White);
		SWall.setOutline(sf::Color::White);
		SWall.setPosition(0.0f, 690.0f);
		SWall.setSize(1260.0f, 10.0f);


		WWall.setShapeType(2);
		WWall.setFill(sf::Color::White);
		WWall.setOutline(sf::Color::White);
		WWall.setPosition(0.0f, 15.0f);
		WWall.setSize(10.0f, 680.0f);

		EWall.setShapeType(2);
		EWall.setFill(sf::Color::White);
		EWall.setOutline(sf::Color::White);
		EWall.setPosition(1250.0f, 15.0f);
		EWall.setSize(10.0f, 680.0f);
}

void Room::drawWalls(sf::RenderWindow& window) {
	NWall.draw(window, NWall.getIsRec());
	SWall.draw(window, SWall.getIsRec());
	WWall.draw(window, WWall.getIsRec());
	EWall.draw(window, EWall.getIsRec());
}

