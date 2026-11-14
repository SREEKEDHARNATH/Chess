#include "black.hpp"
#include "api.hpp"
#include "board.hpp"

void black::init(){
    c2Image bpawn("assets/images/black-pawn.png");
    
    c2Image brook("assets/images/black-rook.png");
    
    c2Image bknight("assets/images/black-knight.png");
    
    c2Image bbishop("assets/images/black-bishop.png");
    
    c2Image bqueen("assets/images/black-queen.png");
    
    c2Image bking("assets/images/black-king.png");

    pos cup=pos::A;
    ind cui=ind::EIGHT;
    for (int i=0;i<6;i++){
        if (i==0){
            for (int j=0;j<2;j++){
                auto& s = Rook[j].s;
                s.p= j == 0 ? cup : (pos)(7-cup);
                s.i= cui;
                s.isblack=true;
                s.ptr=brook.get();
            }
        }
        else if (i==1){
            for (int j=0;j<2;j++){
                auto& s = Knight[j].s;
                s.p= j == 0 ? cup : (pos)(7-cup);
                s.i= cui;
                s.isblack=true;
                s.ptr=bknight.get();
            }
        }
        else if (i==2){
            for (int j=0;j<2;j++){
                auto& s = Bishop[j].s;
                s.p= j == 0 ? cup : (pos)(7-cup);
                s.i= cui;
                s.isblack=true;
                s.ptr=bbishop.get();
            }
        }
        else if (i==3){
            Queen.s.p=cup;
            Queen.s.i=cui;
            Queen.s.isblack=true;
            Queen.s.ptr=bqueen.get();
        }
        else if (i==4){
            King.s.p=cup;
            King.s.i=cui;
            King.s.isblack=true;
            King.s.ptr=bking.get();
        }
        else {
            for (int i=0;i<8;i++){
                cup=(pos)i;
                cui = ind::SEVEN;
                Pawn[i].s.p=cup;
                Pawn[i].s.i=cui;
                Pawn[i].s.isblack=true;
                Pawn[i].s.ptr=bpawn.get();
            }
        }
        cup = (pos)(((int)cup)+1);
    }
}

void black::draw(){
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