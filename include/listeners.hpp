#pragma once
#include "SDL_events.h"

void c2KReg(SDL_KeyboardEvent k);
bool c2KIsPressed(SDL_KeyCode k);
bool c2KIsPressed(SDL_Scancode sc);
bool c2KIsDown(SDL_KeyCode k);
bool c2KIsDown(SDL_Scancode sc);
void c2KUpdate();