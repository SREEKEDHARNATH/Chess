#pragma once

#include "board.hpp"
struct c2Piece{
    square s;
    int clicks=0;
    void draw();
};
struct c2Pawn : public c2Piece{
    bool firstmove=true;
};
struct c2Rook : public c2Piece{};
struct c2Knight : public c2Piece{};
struct c2Bishop : public c2Piece{};
struct c2Queen : public c2Piece{};
struct c2King : public c2Piece{};