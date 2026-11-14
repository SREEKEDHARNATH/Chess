#include "pieces.hpp"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "app.hpp"
#include <memory>

void c2Piece::draw(){
    if (s.ptr.get()){
        SDL_Rect r= {(((int)s.p)*96),(((int)s.i)*96),90,90};
        SDL_RenderCopy(c2GetRenderer(), s.ptr.get(), NULL,&r);
    }
}
