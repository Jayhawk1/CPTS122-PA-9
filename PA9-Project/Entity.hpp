#pragma once
#include <SFML/Graphics.hpp>
#include"Color.hpp"
#include <iostream>
#include "EntityList.hpp"

//TODO: Find way to associate entities with their related entityList, currently, Entity has support for this, but cannot find EntityList in any manner.

class Entity {
protected:
    sf::CircleShape shape;
    int entityNum;
    EntityList<Entity>* parentList;
    bool iFrames;
    bool enabled;
public:

    /*
    Entity() {
        this->entityNum = -1;
        this->parentList = nullptr;
    }
    */
    virtual void draw(sf::RenderWindow& window);

    sf::CircleShape& getShape();

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
        if (getShape().getGlobalBounds().findIntersection(entity->getShape().getGlobalBounds())) {
            std::cout << "Collision detected!" << std::endl;
            return true;
        }
    }

    template <typename E>
    bool Collision(E& entity) {
        if (getShape().getGlobalBounds().findIntersection(entity.getShape().getGlobalBounds())) {
            std::cout << "Collision detected!" << std::endl;
            return true;
        }
    }

    void setIFrames(bool TF) {
        iFrames = TF;
    }

    bool getIFrames() {
        return iFrames;
    }
};
