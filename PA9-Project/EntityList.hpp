#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

template <class ListType>
class EntityList {
public:
    EntityList<ListType>();
    ~EntityList<ListType>();

    int getEntityCount() const;
    ListType** getEntities();
    ListType* getEntity(int pos) const;

    void insertEntity(ListType& nEntity); //Inserts at end of list
	void insertEntity(ListType* nEntity); //Inserts at end of list but with POINTER!

    void removeEntity(ListType& nEntity); //Removes based off entitys' index number
    void removeEntity(int nNum);

    bool isListClear() const;
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
int EntityList<ListType>::getEntityCount() const
{
	return this->entityCount;
}

template<class ListType>
ListType** EntityList<ListType>::getEntities()
{
	return this->entities;
}

template<class ListType>
ListType* EntityList<ListType>::getEntity(int pos) const
{
	if (pos < this->entityCount) {
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
void EntityList<ListType>::insertEntity(ListType* nEntity) {
	this->insertEntity(*nEntity);
}

template<class ListType>
void EntityList<ListType>::removeEntity(ListType& nEntity)
{
	if (this == nullptr) {
		std::cout << "Removing from nonexistent entityList" << std::endl;
		return;
	}
	//if (nEntity) {
	//	std::cout << "Warning: Tried to remove invalid entity" << std::endl;
	//}
	//Remove from entity list
	int index = nEntity.getEntityNum() - 1;
	this->entities[index] = nullptr;

	//Shift all to the left
	for (int i = index; i < this->entityCount; i++) {
		this->entities[i] = this->entities[i + 1];
		this->entities[i + 1] = nullptr;
	}

	this->entityCount--;

	//std::cout << this << std::endl;
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
bool EntityList<ListType>::isListClear() const
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

template<class ListType>
std::ostream& operator<<(std::ostream& lhs, const EntityList<ListType>& rhs) {
	for (int i = 0; i < 32; i++) {
		ListType* currEntity = rhs.getEntity(i);
		if (currEntity == nullptr) {
			//std::cout << "NULL" << std::endl;
		}
		else {
			std::cout << currEntity->getEntityNum() << std::endl;
		}
	}
	return lhs;
}

template<class ListType>
std::ostream& operator<<(std::ostream& lhs, const EntityList<ListType>* rhs) {
	std::cout << (*rhs);
	return lhs;
}