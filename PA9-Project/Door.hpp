#pragma once
#include "Obstacle.hpp"
#include "Trigger.hpp"


class Door : public Obstacle {
protected:
	bool mOpen;
	bool mTransitioning;
	Trigger levelTrigger;
	bool isEntry;

public:
	
	bool getIsOpen() {
		return mOpen;
	}

	bool getIsEntry() {
		return isEntry;
	}

	bool getIsTransitioning() {
		return mTransitioning;
	}

	void setIsOpen(bool newOpen) {
		mOpen = newOpen;
	}

	void setIsEntry(bool newEntry) {
		isEntry = newEntry;
	}

	void setIsTransitioning(bool newTransitioning) {
		mTransitioning = newTransitioning;
	}

	void startNextLevel();


};