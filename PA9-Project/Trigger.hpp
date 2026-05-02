#pragma once
#include "Entity.hpp"


class Trigger : public Obstacle {
protected:
	bool mColliding;

public:

	Trigger() {
		mColliding = false;
		getShape().setFillColor(sf::Color::Transparent);
	}

	bool getIsColliding() {
		return mColliding;
	}
	void setIsColliding(bool newColliding) {
		mColliding = newColliding;
	}

	void update();



};
