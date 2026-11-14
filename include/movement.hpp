#pragma once

#include "black.hpp"
#include "board.hpp"
#include "white.hpp"
void offload();
void move(square& s, int& clicks);
void takepiece(square& s, white& w, black& b);
bool amiok(square& s, white& w, black& b);