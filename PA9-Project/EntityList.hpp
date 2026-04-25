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

    void insertEntity(ListType& nEntity); //Inserts at end of list

    void removeEntity(ListType& nEntity); //Removes based off entitys' index number
    void removeEntity(int nNum);

    bool isListClear();
    void clearList();

private:
    int entityCount;
    ListType** entities; //Pointer to an array of entities
};
