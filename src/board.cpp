#include "board.hpp"
#include "SDL_render.h"
#include "api.hpp"
#include "app.hpp"
#include "black.hpp"
#include "listeners.hpp"
#include "movement.hpp"
#include "white.hpp"
#include <cstdlib>

square squares[8][8];
white w;
black b;
bool isthisvalidstraight(pos oldp, ind oldi, pos p, ind i, bool isblack, square& s){
    if (std::abs(i-oldi)){
        if ((i-oldi)>0){
            ind in = (ind)(((int)oldi)+1);
            while (in != i){
                if (c2BGetSquare(p, in).isoccupied){
                    return false;
                }
                in = (ind)(((int)in)+1);
            }
        }
        else {
            ind in = (ind)(((int)oldi)-1);
            while (in != i){
                if (c2BGetSquare(p, in).isoccupied){
                    return false;
                }
                in = (ind)(((int)in)-1);
            }
        }
    }
    else if(std::abs(p-oldp)){
        if ((p-oldp)>0){
            pos po = (pos)(((int)oldp)+1);
            while (po != p){
                if (c2BGetSquare(po, i).isoccupied){
                    return false;
                }
                po = (pos)(((int)po)+1);
            }
        }
        else {
            pos po = (pos)(((int)oldp)-1);
            while (po != p){
                if (c2BGetSquare(po, i).isoccupied){
                    return false;
                }
                po = (pos)(((int)po)-1);
            }
        }
    }
    return true;
}
bool isthisvaliddiagonalmove(pos oldp, ind oldi, pos p, ind i, bool isblack, square& s){
    int x=1;
    int y=1;
    if ((int)p<(int)oldp){
        x=-1;
    }
    if ((int)i<(int)oldi){
        y=-1;
    }
    pos po = (pos)(((int)oldp)+x);
    ind in = (ind)(((int)oldi)+y);
    while (po != p || in != i){
        if (c2BGetSquare(po, in).isoccupied){
            return false;
        }
        po = (pos)(((int)po)+x);
        in = (ind)(((int)in)+y);
    }
    return true;
}
bool isThisLegalPawnMove(pos oldp, ind oldi, pos p, ind i, bool isblack, square& s){
    if (isblack){
        if ((int)i < (int)oldi){
            return false;
        }
    }
    else {
        if ((int)i > (int)oldi){
            return false;
        }
    }
    bool firstmove = oldi == ind::TWO || oldi == ind::SEVEN;
    if (std::abs(i-oldi) > (firstmove ? 2 : 1)){
        return false;
    }
    if (isblack){
        for (auto& r : w.Rook){
            if (std::abs((int)r.s.p - (int)oldp) == 1 && std::abs((int)r.s.i - (int)oldi) == 1){
                return true;
            }
            if (r.s == s){
                return false;
            }
        }
        for (auto& r : w.Knight){
            if (std::abs((int)r.s.p - (int)oldp) == 1 && std::abs((int)r.s.i - (int)oldi) == 1){
                return true;
            }
            if (r.s == s){
                return false;
            }
        }
        for (auto& r : w.Bishop){
            if (std::abs((int)r.s.p - (int)oldp) == 1 && std::abs((int)r.s.i - (int)oldi) == 1){
                return true;
            }
            if (r.s == s){
                return false;
            }
        }
        for (auto& r : w.Pawn){
            if (std::abs((int)r.s.p - (int)oldp) == 1 && std::abs((int)r.s.i - (int)oldi) == 1){
                return true;
            }
            if (r.s == s){
                return false;
            }
        }
        if (std::abs((int)w.Queen.s.p - (int)oldp) == 1 && std::abs((int)w.Queen.s.i - (int)oldi) == 1){
            return true;
        }
        if (std::abs((int)w.King.s.p - (int)oldp) == 1 && std::abs((int)w.King.s.i - (int)oldi) == 1){
            return true;
        }
        if (s == w.Queen.s || s==w.King.s){
            return false;
        }
    }
    else {
        for (auto& r : b.Rook){
            if (std::abs((int)r.s.p - (int)oldp) == 1 && std::abs((int)r.s.i - (int)oldi) == 1){
                return true;
            }
            if (r.s == s){
                return false;
            }
        }
        for (auto& r : b.Knight){
            if (std::abs((int)r.s.p - (int)oldp) == 1 && std::abs((int)r.s.i - (int)oldi) == 1){
                return true;
            }
            if (r.s == s){
                return false;
            }
        }
        for (auto& r : b.Bishop){
            if (std::abs((int)r.s.p - (int)oldp) == 1 && std::abs((int)r.s.i - (int)oldi) == 1){
                return true;
            }
            if (r.s == s){
                return false;
            }
        }
        for (auto& r : b.Pawn){
            if (std::abs((int)r.s.p - (int)oldp) == 1 && std::abs((int)r.s.i - (int)oldi) == 1){
                return true;
            }
            if (r.s == s){
                return false;
            }
        }
        if (std::abs((int)b.Queen.s.p - (int)oldp) == 1 && std::abs((int)b.Queen.s.i - (int)oldi) == 1){
            return true;
        }
        if (std::abs((int)b.King.s.p - (int)oldp) == 1 && std::abs((int)b.King.s.i - (int)oldi) == 1){
            return true;
        }
        if (s == b.Queen.s || s==b.King.s){
            return false;
        }
    }
    if ((int)p != (int)oldp){
        return false;
    }
    return true;
}
bool isThisLegalKingMove(pos oldp, ind oldi, pos p, ind i, bool isblack, square& s){
    if (std::abs(i-oldi) > 1){
        return false;
    }
    if (std::abs(p-oldp) > 1){
        return false;
    }
    
    return true;
}
bool isThisLegalRookMove(pos oldp, ind oldi, pos p, ind i, bool isblack, square& s){
    return (isthisvalidstraight(oldp, oldi, p, i, isblack, s) && !(std::abs(i-oldi) && std::abs(p-oldp)));
}
bool isThisLegalBishopMove(pos oldp, ind oldi, pos p, ind i, bool isblack, square& s){
    if (!(std::abs(i-oldi) && std::abs(p-oldp))){
        return false;
    }
    return (isthisvaliddiagonalmove(oldp, oldi, p, i, isblack, s) && (std::abs(i-oldi) == std::abs(p-oldp)));
}
bool isThisLegalQueenMove(pos oldp, ind oldi, pos p, ind i, bool isblack, square& s){
    return isThisLegalRookMove(oldp, oldi, p, i, isblack, s) || isThisLegalBishopMove(oldp, oldi, p, i, isblack, s);
}

void move(square& s, int& clicks, Type t){
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
            auto oldp=s.p;
            auto oldi=s.i;
            s.p=(pos)(c2MGetX()/96);
            s.i=(ind)(c2MGetY()/96);
            bool amisafe=amiok(s,w,b);
            if (t==Type::PAWN){
                if (amisafe){
                    amisafe=isThisLegalPawnMove(oldp, oldi, s.p, s.i, s.isblack, s);
                }
            }
            if (t==Type::KING){
                if (amisafe){
                    amisafe=isThisLegalKingMove(oldp, oldi, s.p, s.i, s.isblack, s);
                }
            }
            if (t==Type::ROOK){
                if (amisafe){
                    amisafe=isThisLegalRookMove(oldp, oldi, s.p, s.i, s.isblack, s);
                }
            }
            if (t==Type::BISHOP){
                if (amisafe){
                    amisafe=isThisLegalBishopMove(oldp, oldi, s.p, s.i, s.isblack, s);
                }
            }
            if (t==Type::QUEEN){
                if (amisafe){
                    amisafe=isThisLegalQueenMove(oldp, oldi, s.p, s.i, s.isblack, s);
                }
            }
            
            if (!amisafe){
                s.p=oldp;
                s.i=oldi;
            }
            else {
                c2BGetSquare(oldp, oldi).isoccupied=false;
                c2BGetSquare(s.p, s.i).isoccupied=true;
            }
            takepiece(s,w,b);
            clicks=0;
            offload();
        }
    }
}
bool square::operator==(const square& s) const{
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
square& c2BGetSquare(pos p, ind i){
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