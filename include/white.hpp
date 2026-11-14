#pragma once
#include "pieces.hpp"
struct white{
    c2Rook Rook[2];
    c2Knight Knight[2];
    c2Bishop Bishop[2];
    c2Queen Queen;
    c2King King;
    c2Pawn Pawn[8];

    void init();
    void draw();
};