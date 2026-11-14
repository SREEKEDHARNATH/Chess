#include "board.hpp"
#include "SDL_render.h"
#include "api.hpp"
#include "app.hpp"
#include "black.hpp"
#include "listeners.hpp"
#include "white.hpp"

square squares[8][8];
white w;
black b;

void offload(){
    SDL_MouseButtonEvent b;
    b.button=SDL_BUTTON_LEFT;
    b.state=SDL_RELEASED;
    c2MReg(b);
}
void move(square& s, int& clicks){
    auto mouse = c2MGetRect();
    SDL_Rect r= c2BGetSquare(s.p, s.i).getR();
    if (SDL_HasIntersection(&mouse, &r)){
        if (c2MIsPressed(SDL_BUTTON_LEFT)){
            if (clicks==1){
                clicks=0;
            }
            else {
                clicks=1;
            }
            offload();
        }
    }
    if (clicks==1){
        if (c2MIsPressed(SDL_BUTTON_LEFT)){
            s.p=(pos)(c2MGetX()/96);
            s.i=(ind)(c2MGetY()/96);
            clicks=0;
            offload();
        }
    }
}
bool square::operator==(const square& s){
    return ((int)p == (int)s.p) && ((int)i == (int)s.i);
}
SDL_Rect square::getR(){
    if (ispiece){
        return {p*96,i*96,90,90};
    }
    else {
        return {p*96,i*96,96,96};
    }
}
void c2BInit(){
    c2Image black("assets/images/black-tile.png");
    c2Image white("assets/images/white-tile.png");
    for (int p=0;p<8;p++){
        for (int i=0;i<8;i++){
            square s;
            s.ispiece=false;
            if (p%2){
                s.isblack=(i%2 == 0);
            }
            else {
                s.isblack=(i%2 == 1);
            }
            if (s.isblack){
                s.ptr=black.get();
            }
            else {
                s.ptr=white.get();
            }
            s.p=(pos)p;
            s.i=(ind)i;
            squares[p][i]=s;
        }
    }
    w.init();
    b.init();
}
square c2BGetSquare(pos p, ind i){
    return squares[p][i];
}
void c2BDraw(){
    for (int p=0;p<8;p++){
        for (int i=0;i<8;i++){
            SDL_Rect r = c2BGetSquare((pos)p, (ind)i).getR();
            SDL_RenderCopy(c2GetRenderer(), squares[p][i].ptr.get(), NULL, &r);
        }
    }
    w.draw();
    b.draw();
}