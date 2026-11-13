#include "api.hpp"

#include "SDL_image.h"
#include "SDL_pixels.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "app.hpp"
#include <iostream>
#include <memory>

c2Image::c2Image(const char* name,bool load,bool aset){
    if (load){
        set(name,aset);
    }
}
c2Image::c2Image(SDL_Texture* tex){
    set(tex);
}
c2Image::c2Image(Uint8 r,Uint8 g,Uint8 b, Uint16 w,Uint16 h){
    set(r,g,b,w,h);
}
void c2Image::set(const char* name,bool aset){
    auto tex = IMG_LoadTexture(c2GetRenderer(), name);
    if (!tex){
        std::cerr << IMG_GetError() << "\n";
        return;
    }
    ptr.reset(tex, SDL_DestroyTexture);
    if (aset){
        autoset();
    }
}
void c2Image::set(SDL_Texture* tex){
    if (tex){
        ptr.reset(tex, SDL_DestroyTexture);
        autoset();
    }
}
void c2Image::set(Uint8 r,Uint8 g,Uint8 b, Uint16 w,Uint16 h){
    auto surf = SDL_CreateRGBSurface(0, w, h, 32, 0,0,0,0);
    if (!surf){
        std::cerr << SDL_GetError() << "\n";
        return;
    }
    auto colour = SDL_MapRGB(surf->format, r, g, b);
    SDL_FillRect(surf,NULL,colour);
    auto tex = SDL_CreateTextureFromSurface(c2GetRenderer(), surf);
    SDL_FreeSurface(surf);
    if (!tex){
        std::cerr << SDL_GetError() << "\n";
        return;
    }
    ptr.reset(tex, SDL_DestroyTexture);
    autoset();
}
void c2Image::draw(){
    if (ptr.get()){
        if (r.w < 1 || r.h < 1){
            SDL_RenderCopy(c2GetRenderer(), ptr.get(), NULL,NULL);
        }
        else {
            SDL_RenderCopy(c2GetRenderer(), ptr.get(), NULL,&r);
        }
    }
}
void c2Image::autoset(){
    if (ptr.get()){
        SDL_QueryTexture(ptr.get(), NULL,NULL,&r.w,&r.h);
    }
}
std::shared_ptr<SDL_Texture> c2Image::get(){
    return ptr;
}