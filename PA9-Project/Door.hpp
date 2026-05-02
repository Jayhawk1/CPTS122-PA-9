#pragma once
#include "Obstacle.hpp"


class Door : public Obstacle {
protected:
	bool mOpen;
	bool isColliding = false;

public:
	Door() {

	}

	Door(int mShape, float posX, float posY, float sizeX, float sizeY, sf::Color outline, sf::Color fill, bool isOpen) {  // 1 = CIRCLE, 2 = RECTANGLE



		mPosition.x = posX;
		mPosition.y = posY;

		mSize.x = sizeX;
		mSize.y = sizeY;

		mOutline = outline;
		mFill = fill;
		ShapeType = mShape;
		mOpen = isOpen;

		if (ShapeType == 1) {
			shape.setOrigin(mPosition);
			shape.setOutlineColor(mOutline);
			shape.setFillColor(mFill);
			shape.setRadius(mSize.y);
			isRec = false;
		}
		else if (ShapeType == 2) {
			mRec.setPosition(mPosition);
			mRec.setOutlineColor(mOutline);
			mRec.setFillColor(mFill);
			mRec.setSize(mSize);
			isRec = true;
		}

	}

	bool getIsOpen() const {
		return mOpen;
	}


	void setIsOpen(bool newOpen) {
		mOpen = newOpen;
	}

	void setIsColliding(bool TF) {
		isColliding = TF;
	}

	bool& getIsColliding(){
		return isColliding;
	}

	void startNextLevel();

};