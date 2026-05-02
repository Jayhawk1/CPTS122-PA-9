#include "Entity.hpp"

void Entity::draw(sf::RenderWindow& window) {

    window.draw(shape);
}

sf::CircleShape& Entity::getShape() {

    return shape;
}

void Entity::setEnabled(bool nVal)
{
	this->enabled = nVal;
}

bool Entity::getEnabled()
{
	return this->enabled;
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
				double distLength = (currEntity->shape.getPosition() - this->shape.getPosition()).length();

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
