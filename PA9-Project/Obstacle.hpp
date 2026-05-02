#pragma once
#include "Entity.hpp"

class Obstacle : public Entity {
protected:
	sf::Vector2f mPosition;
	sf::Color mOutline;
	sf::Color mFill;
	sf::Vector2f mSize;
	sf::RectangleShape mRec;
	sf::CircleShape shape;
	int ShapeType;
	bool isRec;

public:

	Obstacle() {
	mPosition = sf::Vector2f(0, 0);
		mOutline = sf::Color::White;
		mFill = sf::Color::White;
		mSize = sf::Vector2f(1, 1);
		isRec = false;
		ShapeType = 0;
	}


	Obstacle(int mShape ,float posX, float posY, float sizeX, float sizeY, sf::Color outline, sf::Color fill) {  // 1 = CIRCLE, 2 = RECTANGLE



		mPosition.x = posX;
		mPosition.y = posY;

		mSize.x = sizeX;
		mSize.y = sizeY;

		mOutline = outline;
		mFill = fill;
		ShapeType = mShape;

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



	virtual void draw(sf::RenderWindow& window, const bool& isRec);
	


	virtual ~Obstacle() {

	}

	sf::Shape& getShape() override {
		if (isRec) return mRec; 
		return shape;           
	}

	sf::Vector2f getPosition() {
		return mPosition;
	}

	sf::Color getOutline() {
		return mOutline;
	}

	sf::Color getFill() {
		return mFill;
	}

	sf::Vector2f getSize() {
		return mSize;
	}

	bool getIsRec() const{
		return isRec;
	}

	int getShapeType() {
		return ShapeType;
	}
	

	//////////

	void setPosition(sf::Vector2f pos) {
		mPosition = pos;
		if (isRec) {
			mRec.setPosition(mPosition);
		}
		else {
			shape.setPosition(mPosition);
		}
	}

	void setPosition(float posX, float posY) {
		mPosition.x = posX;
		mPosition.y = posY;

		if (isRec) {
			mRec.setPosition(mPosition);
		}
		else {
			shape.setPosition(mPosition);
		}
	}


	void setOutline(sf::Color outline) {
		mOutline = outline;

		if (isRec) {
			mRec.setOutlineColor(mOutline);
		}
		else {
			shape.setOutlineColor(mOutline);
		}
	}

	void setFill(sf::Color fill) {
		mFill = fill;
		if (isRec) {
			mRec.setFillColor(mFill);
		}
		else {
			shape.setFillColor(mFill);
		}
	}

	void setSize(sf::Vector2f size) {
		mSize = size;

		if (isRec) {
			mRec.setSize(mSize);
		}
		else {
			shape.setRadius(mSize.y);
		}
	}

	void setSize(float sizeX, float sizeY) {
		mSize.x = sizeX;
		mSize.y = sizeY;

		if (isRec) {
			mRec.setSize(mSize);
		}
		else {
			shape.setScale(mSize);
		}
	}

	void setShapeType(int mShape) {
		ShapeType = mShape;

		if (mShape == 2) {
			isRec = true;
		}
		else if (mShape == 1) {
			isRec = false;
		}
	}

	void getObstShape() {
		if (isRec) {
			returnRec();
		}
		else {
			getShape();
		}
	}


	sf::RectangleShape& returnRec() {
		return mRec;
	}


};

