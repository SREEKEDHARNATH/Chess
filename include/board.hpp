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
    ONE=7,
    TWO=6,
    THREE=5,
    FOUR=4,
    FIVE=3,
    SIX=2,
    SEVEN=1,
    EIGHT=0
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