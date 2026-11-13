#pragma once
#include "SDL_render.h"
#include "SDL_video.h"
#include <utility>

void c2Run();
void c2Quit();
SDL_Window*& c2GetWindow();
SDL_Renderer*& c2GetRenderer();
std::pair<int, int> c2GetD();
const char* c2GetTitle();