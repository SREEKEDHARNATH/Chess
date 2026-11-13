#include "app.hpp"
#include "SDL.h"
#include "SDL_error.h"
#include "SDL_events.h"
#include "SDL_keycode.h"
#include "SDL_render.h"
#include "SDL_video.h"
#include "SDL_image.h"
#include "api.hpp"
#include "listeners.hpp"
#include <iostream>
#include <utility>

std::pair<bool, const char*> init();

void c2Run(){
    {
        auto initres = init();
        if (!initres.first){
            std::cerr << initres.second << "\n";
            return;
        }
    }
    
    SDL_Event e;
    bool running=true;
    float fps=60;

    SDL_ShowWindow(c2GetWindow());
    while (running){
        while (SDL_PollEvent(&e)){
            switch (e.type) {
                case SDL_QUIT:
                    running=false;
                    break;
                case SDL_KEYUP:
                case SDL_KEYDOWN:
                    c2KReg(e.key);
                    break;
            }
        }

        if (c2KIsPressed(SDLK_ESCAPE)){
            running=false;
        }
        SDL_RenderClear(c2GetRenderer());
        SDL_RenderPresent(c2GetRenderer());
        
        c2KUpdate();
        SDL_Delay(1000/fps);
    }
}


std::pair<bool, const char*> init(){
    int img_flags=IMG_INIT_PNG;
    if (SDL_Init(SDL_INIT_EVERYTHING)){
        return {false, SDL_GetError()};
    }
    if ((IMG_Init(img_flags) & img_flags) != img_flags){
        return {false, IMG_GetError()};
    }
    c2GetWindow()=SDL_CreateWindow(c2GetTitle(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,c2GetD().first,c2GetD().second,SDL_WINDOW_HIDDEN);
    if (!c2GetWindow()){
        return {false, SDL_GetError()};
    }
    c2GetRenderer()=SDL_CreateRenderer(c2GetWindow(), -1,0);
    if (!c2GetRenderer()){
        return {false, SDL_GetError()};
    }
    return {true, ""};
}
void c2Quit(){
    if (c2GetWindow()){
        SDL_DestroyWindow(c2GetWindow());
    }
    if (c2GetRenderer()){
        SDL_DestroyRenderer(c2GetRenderer());
    }
    IMG_Quit();
    SDL_Quit();
}
SDL_Window*& c2GetWindow(){
    static SDL_Window* ptr=nullptr;
    return ptr;
}
SDL_Renderer*& c2GetRenderer(){
    static SDL_Renderer* ptr=nullptr;
    return ptr;
}
std::pair<int, int> c2GetD(){
    return {1024,768};
}
const char* c2GetTitle(){
    return "Chess";
}