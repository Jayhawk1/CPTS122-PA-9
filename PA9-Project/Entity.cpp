#include "Entity.hpp"

void Entity::draw(sf::RenderWindow& window) {

	window.draw(getShape());
}


Entity* Entity::getNearestEntityOfType(const char* typeName)
{
	double nearestDist = 99999;
	Entity* nearestEntity = nullptr;

	if (this->parentList != nullptr) {
		//Calculate nearest player
		for (int i = 0; i < this->parentList->getEntityCount(); i++) {
			double currDist = 99999;
			Entity* currEntity = this->parentList->getEntity(i);
			//std::cout << typeid(*currEntity).name() << std::endl;
			if (typeid(*currEntity).name() == typeName) {
				double distLength = (currEntity->getShape().getPosition() - this->getShape().getPosition()).length();

				if (nearestEntity == nullptr || distLength < nearestDist) {
					//std::cout << "FOUND ENTITY " << distLength << std::endl;
					nearestDist = distLength;
					nearestEntity = currEntity;
				}
			}
		}

		return nearestEntity;
	}
	return nullptr;
}



