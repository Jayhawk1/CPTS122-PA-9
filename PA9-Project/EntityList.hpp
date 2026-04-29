#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

template <class ListType>
class EntityList {
public:
    EntityList<ListType>();
    ~EntityList<ListType>();

    int getEntityCount();
    ListType** getEntities();
    ListType* getEntity(int pos);

    void insertEntity(ListType& nEntity); //Inserts at end of list

    void removeEntity(ListType& nEntity); //Removes based off entitys' index number
    void removeEntity(int nNum);

    bool isListClear();
    void clearList();

private:
    int entityCount;
    ListType** entities; //Pointer to an array of entities
};

#define entityLimit 512;

template <class ListType>
EntityList<ListType>::EntityList() {
	this->entities = new ListType*[512];
	this->entityCount = 0;

	std::cout << "Entity count: " << this->entityCount << std::endl;
}

template<class ListType>
EntityList<ListType>::~EntityList()
{
	this->clearList();

	delete[] this->entities;
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
ListType* EntityList<ListType>::getEntity(int pos)
{
	if (pos <= 512) {
		return (this->entities[pos]);
	}
	return nullptr;
}

template<class ListType>
void EntityList<ListType>::insertEntity(ListType& nEntity)
{
	this->entityCount = ++(this->entityCount);
	nEntity.setEntityNum(this->entityCount);

	this->entities[this->entityCount - 1] = &nEntity;

	nEntity.setParentList(this);

	std::cout << "Entity count: " << this->entityCount << std::endl;
}

template<class ListType>
void EntityList<ListType>::removeEntity(ListType& nEntity)
{
	/*if (nEntity) {
		std::cout << "Warning: Tried to remove invalid entity" << std::endl;
	}*/
	//Remove from entity list
	this->entities[nEntity.getEntityNum() - 1] = nullptr;
	this->entityCount--;

	//If there's more entities, then shift the last one in the list to the position of the currently deleted one
	if (this->entityCount > 0) {
		this->entities[nEntity.getEntityNum() - 1] = this->entities[this->entityCount + 1];
		this->entities[this->entityCount + 1] = nullptr;
	}
}

template<class ListType>
void EntityList<ListType>::removeEntity(int nNum)
{
	if (nNum < 0 || nNum > 512) {
		std::cout << "Warning: Attempted to remove entity in invalid index range: " << nNum << std::endl;
	}
	this->removeEntity(*(this->entities[nNum]));
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
			this->removeEntity(*(this->entities[i]));
		}
	}
}