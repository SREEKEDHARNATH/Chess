#include "white.hpp"
#include "api.hpp"

void white::init(){
    c2Image wpawn("assets/images/white-pawn.png");
    
    c2Image wrook("assets/images/white-rook.png");
    
    c2Image wknight("assets/images/white-knight.png");
    
    c2Image wbishop("assets/images/white-bishop.png");
    
    c2Image wqueen("assets/images/white-queen.png");
    
    c2Image wking("assets/images/white-king.png");

    pos cup=pos::A;
    ind cui=ind::ONE;
    for (int i=0;i<6;i++){
        if (i==0){
            for (int j=0;j<2;j++){
                auto& s = Rook[j].s;
                s.p= j == 0 ? cup : (pos)(7-cup);
                s.i= cui;
                s.isblack=false;
                s.ptr=wrook.get();
            }
        }
        else if (i==1){
            for (int j=0;j<2;j++){
                auto& s = Knight[j].s;
                s.p= j == 0 ? cup : (pos)(7-cup);
                s.i= cui;
                s.isblack=false;
                s.ptr=wknight.get();
            }
        }
        else if (i==2){
            for (int j=0;j<2;j++){
                auto& s = Bishop[j].s;
                s.p= j == 0 ? cup : (pos)(7-cup);
                s.i= cui;
                s.isblack=false;
                s.ptr=wbishop.get();
            }
        }
        else if (i==3){
            Queen.s.p=cup;
            Queen.s.i=cui;
            Queen.s.isblack=false;
            Queen.s.ptr=wqueen.get();
        }
        else if (i==4){
            King.s.p=cup;
            King.s.i=cui;
            King.s.isblack=false;
            King.s.ptr=wking.get();
        }
        else {
            for (int i=0;i<8;i++){
                cup=(pos)i;
                cui = ind::TWO;
                Pawn[i].s.p=cup;
                Pawn[i].s.i=cui;
                Pawn[i].s.isblack=false;
                Pawn[i].s.ptr=wpawn.get();
            }
        }
        cup = (pos)(((int)cup)+1);
    }
}

void white::draw(){
    for (auto& p : Rook){
        move(p.s, p.clicks);
        p.draw();
    }
    for (auto& p : Knight){
        move(p.s, p.clicks);
        p.draw();
    }
    for (auto& p : Bishop){
        move(p.s, p.clicks);
        p.draw();
    }
    move(Queen.s, Queen.clicks);
    Queen.draw();
    move(King.s, King.clicks);
    King.draw();
    for (auto& p : Pawn){
        move(p.s, p.clicks);
        p.draw();
    }
}