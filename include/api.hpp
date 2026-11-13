#pragma once

#include "SDL_render.h"
#include <memory>
class c2Image{
    std::shared_ptr<SDL_Texture> ptr;
    public:
        SDL_Rect r={0,0,0,0};
        c2Image(const char* name,bool load=true,bool aset=true);
        c2Image(SDL_Texture* tex);
        c2Image(Uint8 r,Uint8 g,Uint8 b, Uint16 w=32,Uint16 h=32);
        void set(const char* name,bool aset=true);
        void set(SDL_Texture* tex);
        void set(Uint8 r,Uint8 g,Uint8 b, Uint16 w=32,Uint16 h=32);
        void draw();
        void autoset();
        std::shared_ptr<SDL_Texture> get();
};
