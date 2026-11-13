#include "board.hpp"
#include "SDL_render.h"
#include "api.hpp"
#include "app.hpp"

square squares[8][8];

void c2BInit(){
    c2Image black("assets/images/black-tile.png");
    c2Image white("assets/images/white-tile.png");
    for (int p=0;p<8;p++){
        for (int i=0;i<8;i++){
            square s;
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
}
square c2BGetSquare(pos p, ind i){
    return squares[p][i];
}
void c2BDraw(){
    for (int p=0;p<8;p++){
        for (int i=0;i<8;i++){
            SDL_Rect r = {p*96,i*96,96,96};
            SDL_RenderCopy(c2GetRenderer(), squares[p][i].ptr.get(), NULL, &r);
        }
    }   
}