#pragma once

#include "SDL_render.h"
#include <memory>
enum pos{
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H
};
enum ind{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT
};

struct square{
    bool isblack=false;
    std::shared_ptr<SDL_Texture> ptr;
    pos p;
    ind i;
};

void c2BInit();
square c2BGetSquare(pos p, ind i);
void c2BDraw();