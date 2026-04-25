#pragma once
#include "Entity.hpp"


class Trigger : public Entity {
protected:
	bool mColliding;

public:

	Trigger() {
		mColliding = false;
		shape.setFillColor(sf::Color::Transparent);
	}

	bool getIsColliding() {
		return mColliding;
	}
	void setIsColliding(bool newColliding) {
		mColliding = newColliding;
	}

	void update() override {

	}



};
