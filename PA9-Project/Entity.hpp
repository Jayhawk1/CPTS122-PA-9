#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "EntityList.hpp"

//TODO: Find way to associate entities with their related entityList, currently, Entity has support for this, but cannot find EntityList in any manner.

class Entity {
protected:
    sf::CircleShape shape;
    int entityNum;
    bool enabled;
    EntityList<Entity>* parentList;
public:
    Entity();

    virtual void update() = 0; 

    virtual void draw(sf::RenderWindow& window);

    sf::CircleShape& getShape();

    int getEntityNum() {
        return entityNum;
    }
    void setEntityNum(int nNum) {
        this->entityNum = nNum;
    }

    void setParentList(EntityList<Entity>* nList) {
        this->parentList = nList;
    }

    void setEnabled(bool nVal);
    bool getEnabled();

    //Takes typeid(class).name()
    Entity* getNearestEntityOfType(const char* typeName);

    virtual ~Entity() {}
};