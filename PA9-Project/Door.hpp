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

	void setIsTransitioning(bool newTransitioning) {
		mTransitioning = newTransitioning;
	}

	void startNextLevel() {
		if (levelTrigger.getIsColliding()) {
			
		}
	}


};