#pragma once
#include "SDL_events.h"

void c2KReg(SDL_KeyboardEvent k);
bool c2KIsPressed(SDL_KeyCode k);
bool c2KIsPressed(SDL_Scancode sc);
bool c2KIsDown(SDL_KeyCode k);
bool c2KIsDown(SDL_Scancode sc);
void c2KUpdate();

void c2MReg(SDL_MouseMotionEvent m);
void c2MReg(SDL_MouseButtonEvent b);
void c2MReg(SDL_MouseWheelEvent w);
bool c2MIsPressed(int b);
bool c2MIsDown(int b);
int c2MGetX();
int c2MGetY();
float c2MGetScrlX();
float c2MGetScrlY();
void c2MUpdate();
SDL_Rect c2MGetRect();