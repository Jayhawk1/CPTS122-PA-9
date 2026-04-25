#pragma once
#include "Entity.hpp"


class Obstacle : protected Entity {
protected:
	sf::Vector2f mPosition;
	sf::Color mOutline;
	sf::Color mFill;

public:

	/*Obstacle() {
		shape.setPosition(mPosition);
		shape.setOutlineColor(mOutline);
		shape.setFillColor(mFill);
	}
	*/


	virtual ~Obstacle() {

	}

	/*Obstacle(sf::Vector2f pos, sf::Color outline, sf::Color fill) {
		mPosition = pos;
		mOutline = outline;
		mFill = fill;

		shape.setPosition(mPosition);
		shape.setOutlineColor(mOutline);
		shape.setFillColor(mFill);
	}
	*/


	sf::Vector2f getPosition() {
		return mPosition;
	}

	sf::Color getOutline() {
		return mOutline;
	}

	sf::Color getFill() {
		return mFill;
	}

	void setPosition(sf::Vector2f pos) {
		mPosition = pos;
		shape.setPosition(mPosition);
	}

	void setOutline(sf::Color outline) {
		mOutline = outline;
		shape.setOutlineColor(mOutline);
	}

	void setFill(sf::Color fill) {
		mFill = fill;
		shape.setFillColor(mFill);
	}

	virtual bool IsColliding();

	 void update() override {

	}
};

