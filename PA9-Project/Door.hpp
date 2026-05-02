#pragma once
#include "Obstacle.hpp"
#include "Trigger.hpp"


class Door : public Obstacle {
protected:
	bool mOpen;
	bool mTransitioning;
	Trigger levelTrigger;

public:
	
	bool getIsOpen() {
		return mOpen;
	}


	bool getIsTransitioning() {
		return mTransitioning;
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