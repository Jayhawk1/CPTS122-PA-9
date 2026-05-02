#pragma once
#include <SFML/Graphics.hpp>
#include"Color.hpp"
#include <iostream>
#include "EntityList.hpp"

//TODO: Find way to associate entities with their related entityList, currently, Entity has support for this, but cannot find EntityList in any manner.

class Entity {
protected:
    int entityNum;
    EntityList<Entity>* parentList;
    bool iFrames;
    bool enabled;
    bool isAlive = true;

    
public:

    /*
    Entity() {
        this->entityNum = -1;
        this->parentList = nullptr;
    }
    */

    virtual sf::Shape& getShape() = 0;

    virtual void draw(sf::RenderWindow& window);

    int getEntityNum() {
        return entityNum;
    }

    void update() {

    }

    void setEntityNum(int nNum) {
        this->entityNum = nNum;
    }

    void setParentList(EntityList<Entity>* nList) {
        this->parentList = nList;
    }

    //Takes typeid(class).name()
    Entity* getNearestEntityOfType(const char* typeName);

    int getEntityNum() const {
        return this->entityNum;
    }

    void setEnabled(bool nVal);
    bool getEnabled();

    virtual ~Entity() {}

    template <typename E>
    bool CollisionP(E* entity) {
        // 1. Safety check: Is the pointer itself null?
        if (!this->getIsAlive()) return false;

        if (entity == nullptr || !entity->getIsAlive()) return false;

        sf::FloatRect r1 = getShape().getGlobalBounds();
        sf::FloatRect r2 = entity->getShape().getGlobalBounds();

        if (r1.position.x < r2.position.x + r2.size.x &&
            r1.position.x + r1.size.x > r2.position.x &&
            r1.position.y < r2.position.y + r2.size.y &&
            r1.position.y + r1.size.y > r2.position.y)
        {
            return true;
        }
        return false;
    }

    template <typename E>
    bool Collision(E& entity) {
        sf::FloatRect r1 = getShape().getGlobalBounds();
        sf::FloatRect r2 = entity.getShape().getGlobalBounds();

        return (r1.position.x < r2.position.x + r2.size.x &&
            r1.position.x + r1.size.x > r2.position.x &&
            r1.position.y < r2.position.y + r2.size.y &&
            r1.position.y + r1.size.y > r2.position.y);
    }

    void setIFrames(bool TF) {
        iFrames = TF;
    }

    bool getIFrames() {
        return iFrames;
    }

    void kill() { 
        isAlive = false; 
    }
    bool getIsAlive() const { 
        return isAlive; 
    }

};
