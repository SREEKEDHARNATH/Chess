#include "white.hpp"
#include "api.hpp"
#include "board.hpp"

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
                c2BGetSquare(s.p, s.i).isoccupied=true;
                s.p= j == 0 ? cup : (pos)(7-cup);
                s.i= cui;
                s.isblack=false;
                s.ptr=wrook.get();
            }
        }
        else if (i==1){
            for (int j=0;j<2;j++){
                auto& s = Knight[j].s;
                c2BGetSquare(s.p, s.i).isoccupied=true;
                s.p= j == 0 ? cup : (pos)(7-cup);
                s.i= cui;
                s.isblack=false;
                s.ptr=wknight.get();
            }
        }
        else if (i==2){
            for (int j=0;j<2;j++){
                auto& s = Bishop[j].s;
                c2BGetSquare(s.p, s.i).isoccupied=true;
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
            c2BGetSquare(Queen.s.p, Queen.s.i).isoccupied=true;
        }
        else if (i==4){
            King.s.p=cup;
            King.s.i=cui;
            King.s.isblack=false;
            King.s.ptr=wking.get();
            c2BGetSquare(King.s.p, King.s.i).isoccupied=true;
        }
        else {
            for (int j=0;j<8;j++){
                cup=(pos)j;
                cui = ind::TWO;
                Pawn[j].s.p=cup;
                Pawn[j].s.i=cui;
                Pawn[j].s.isblack=false;
                Pawn[j].s.ptr=wpawn.get();
                c2BGetSquare(Pawn[j].s.p, Pawn[j].s.i).isoccupied=true;
            }
        }
        cup = (pos)(((int)cup)+1);
    }
}

void white::draw(){
    for (auto& p : Rook){
        move(p.s, p.clicks,Type::ROOK);
        p.draw();
    }
    for (auto& p : Knight){
        move(p.s, p.clicks,Type::KNIGHT);
        p.draw();
    }
    for (auto& p : Bishop){
        move(p.s, p.clicks,Type::BISHOP);
        p.draw();
    }
    move(Queen.s, Queen.clicks,Type::QUEEN);
    Queen.draw();
    move(King.s, King.clicks,Type::KING);
    King.draw();
    for (auto& p : Pawn){
        move(p.s, p.clicks,Type::PAWN);
        p.draw();
    }
}