#pragma once
#include "Logic.hpp"

Room spinRoom() {
	int random_num = (rand() % 4);

	if (random_num == 0) {
		return Room(ROOM1);
	}
	else if (random_num == 1) {
		return Room(ROOM2);
	}
	else if (random_num == 2) {
		return Room(ROOM3);
	}
	else {
		return Room(ROOM4);
	}
}

ColorType spinColor() {
	int random_num = (rand() % 6);

	if (random_num == 0) {
		return RED;
	}
	else if (random_num == 2) {
		return YELLOW;
	}
	else if (random_num == 3) {
		return CYAN;
	}
	else if (random_num == 4) {
		return BLUE;
	}
	else {
		return NONE;
	}

}