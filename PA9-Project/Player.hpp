#pragma once
#include <SFML/Graphics.hpp>
#include "Color.hpp"
#include "Entity.hpp"

class Player : public Entity {
private:
    ColorType color1, color2;
    bool usingFirst;
    float health;

public:
    Player();

    void update() override;
    void swapColor();
    void newColor(ColorType newColor);
    ColorType getCurrentColor();
    void takeDamage(ColorType enemyColor);
};