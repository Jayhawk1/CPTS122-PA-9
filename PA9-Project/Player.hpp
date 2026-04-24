#pragma once
#include <SFML/Graphics.hpp>
#include "Color.hpp"
#include "Entity.hpp"

class Player : public Entity {
private:
    ColorType color1, color2;
    bool usingFirst;

public:
    Player();

    void update() override;
    void swapColor();
    ColorType getCurrentColor();
};