#include "EntityList.hpp"

int entityLimit = 512;

template <class ListType>
EntityList<ListType>::EntityList() {
	entities = malloc(sizeof(ListType) * entityLimit);;
	entityCount = 0;

	std::cout << "Entity count: " << entityCount << std::endl;
}

template<class ListType>
EntityList<ListType>::~EntityList()
{
	this->clearList();

	free(this->entities);
}

template<class ListType>
int EntityList<ListType>::getEntityCount()
{
	return this->entityCount;
}

template<class ListType>
ListType** EntityList<ListType>::getEntities()
{
	return this->entities;
}

template<class ListType>
void EntityList<ListType>::insertEntity(ListType& nEntity)
{
	nEntity.entityNum = ++(this->entityCount);

	this->entities[nEntity.entityNum - 1] = &nEntity;

	std::cout << "Entity count: " << this->entityCount << std::endl;
}

template<class ListType>
void EntityList<ListType>::removeEntity(ListType& nEntity)
{
	if (nEntity == NULL) {
		std::cout << "Warning: Tried to remove invalid entity" << std::endl;
	}
	//Remove from entity list
	this->entities[nEntity.entityNum - 1] = nullptr;
	this->entityCount--;

	//If there's more entities, then shift the last one in the list to the position of the currently deleted one
	if (this->entityCount > 0) {
		this->entities[nEntity.entityNum - 1] = this->entities[this->entityCount + 1];
		this->entities[this->entityCount + 1] = nullptr;
	}

	delete nEntity;
}

template<class ListType>
void EntityList<ListType>::removeEntity(int nNum)
{
	if (nNum < 0 || nNum > 512) {
		std::cout << "Warning: Attempted to remove entity in invalid index range: " << nNum << std::endl;
	}
	this->removeEntity(this->entities[nNum]);
}

template<class ListType>
bool EntityList<ListType>::isListClear()
{
	return this->entityCount == 0;
}

template<class ListType>
void EntityList<ListType>::clearList()
{
	for (int i = 0; i < entityCount; i++) {
		if (this->entities[i] != nullptr) {
			this->removeEntity(this->entities[i]);
		}
	}
}

