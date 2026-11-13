#include "board.hpp"
#include "SDL_render.h"
#include "api.hpp"
#include "app.hpp"
#include "pieces.hpp"
#include <iostream>

square squares[8][8];
c2King King[2];
c2Queen Queen[2];
c2Bishop Bishop[4];
c2Knight Knight[4];
c2Rook Rook[4];
c2Pawn Pawn[16];

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

    c2Image bpawn("assets/images/black-pawn.png");
    c2Image wpawn("assets/images/white-pawn.png");
    
    c2Image brook("assets/images/black-rook.png");
    c2Image wrook("assets/images/white-rook.png");
    
    c2Image bknight("assets/images/black-knight.png");
    c2Image wknight("assets/images/white-knight.png");
    
    c2Image bbishop("assets/images/black-bishop.png");
    c2Image wbishop("assets/images/white-bishop.png");
    
    c2Image bqueen("assets/images/black-queen.png");
    c2Image wqueen("assets/images/white-queen.png");
    
    c2Image bking("assets/images/black-king.png");
    c2Image wking("assets/images/white-king.png");

    pos cup=pos::A;
    ind cui=ind::ONE;
    for (int i=0;i<6;i++){
        if (i==0){
            Rook[0].s.p=cup;
            Rook[0].s.i=cui;
            Rook[0].s.isblack=false;
            Rook[0].s.ptr=wrook.get();
            
            Rook[1].s.p=(pos)(7-cup);
            Rook[1].s.i=cui;
            Rook[1].s.isblack=false;
            Rook[1].s.ptr=wrook.get();

            Rook[2].s.p=cup;
            Rook[2].s.i=(ind)(7-cui);
            Rook[2].s.isblack=true;
            Rook[2].s.ptr=brook.get();

            Rook[3].s.p=(pos)(7-cup);
            Rook[3].s.i=(ind)(7-cui);
            Rook[3].s.isblack=true;
            Rook[3].s.ptr=brook.get();
        }
        else if (i==1){
            Knight[0].s.p=cup;
            Knight[0].s.i=cui;
            Knight[0].s.isblack=false;
            Knight[0].s.ptr=wknight.get();
            
            Knight[1].s.p=(pos)(7-cup);
            Knight[1].s.i=cui;
            Knight[1].s.isblack=false;
            Knight[1].s.ptr=wknight.get();

            Knight[2].s.p=cup;
            Knight[2].s.i=(ind)(7-cui);
            Knight[2].s.isblack=true;
            Knight[2].s.ptr=bknight.get();
            
            Knight[3].s.p=(pos)(7-cup);
            Knight[3].s.i=(ind)(7-cui);
            Knight[3].s.isblack=true;
            Knight[3].s.ptr=bknight.get();
        }
        else if (i==2){
            Bishop[0].s.p=cup;
            Bishop[0].s.i=cui;
            Bishop[0].s.isblack=false;
            Bishop[0].s.ptr=wbishop.get();
            
            Bishop[1].s.p=(pos)(7-cup);
            Bishop[1].s.i=cui;
            Bishop[1].s.isblack=false;
            Bishop[1].s.ptr=wbishop.get();

            Bishop[2].s.p=cup;
            Bishop[2].s.i=(ind)(7-cui);
            Bishop[2].s.isblack=true;
            Bishop[2].s.ptr=bbishop.get();
            
            Bishop[3].s.p=(pos)(7-cup);
            Bishop[3].s.i=(ind)(7-cui);
            Bishop[3].s.isblack=true;
            Bishop[3].s.ptr=bbishop.get();
        }
        else if (i==3){
            Queen[0].s.p=cup;
            Queen[0].s.i=cui;
            Queen[0].s.isblack=false;
            Queen[0].s.ptr=wqueen.get();
            
            Queen[1].s.p=cup;
            Queen[1].s.i=(ind)(7-cui);
            Queen[1].s.isblack=true;
            Queen[1].s.ptr=bqueen.get();
        }
        else if (i==4){
            King[0].s.p=cup;
            King[0].s.i=cui;
            King[0].s.isblack=false;
            King[0].s.ptr=wrook.get();
            
            King[1].s.p=cup;
            King[1].s.i=(ind)(7-cui);
            King[1].s.isblack=true;
            King[1].s.ptr=bking.get();
        }
        else {
            for (int i=0;i<8;i++){
                cup=(pos)i;
                cui = ind::TWO;
                Pawn[i].s.p=cup;
                Pawn[i].s.i=cui;
                Pawn[i].s.isblack=false;
                Pawn[i].s.ptr=wpawn.get();
            
                Pawn[i+8].s.p=cup;
                Pawn[i+8].s.i=(ind)(7-cui);
                Pawn[i+8].s.isblack=true;
                Pawn[i+8].s.ptr=bpawn.get();
            }
        }
        cup = (pos)(((int)cup)+1);
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
    for (auto& p : Rook){
        p.draw();
    }
    for (auto& p : Knight){
        p.draw();
    }
    for (auto& p : Bishop){
        p.draw();
    }
    for (auto& p : Queen){
        p.draw();
    }
    for (auto& p : King){
        p.draw();
    }
    for (auto& p : Pawn){
        p.draw();
    }
}