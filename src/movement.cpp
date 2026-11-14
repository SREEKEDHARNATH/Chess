#include "movement.hpp"
#include "SDL_events.h"
#include "listeners.hpp"

void offload(){
    SDL_MouseButtonEvent b;
    b.button=SDL_BUTTON_LEFT;
    b.state=SDL_RELEASED;
    c2MReg(b);
}
void takepiece(square& s, white& w, black& b){
    if (!s.isblack){
        auto& rk = b.Rook;
        auto& kn = b.Knight;
        auto& bi = b.Bishop;
        auto& pa = b.Pawn;
        auto& q = b.Queen;
        auto& k = b.King;

        if (k.s==s){
            k.s.ptr.reset();
        }
        if (q.s==s){
            q.s.ptr.reset();
        }
        for (auto& o : rk){
            if (o.s==s){
                o.s.ptr.reset();
            }
        }
        for (auto& o : kn){
            if (o.s==s){
                o.s.ptr.reset();
            }
        }
        for (auto& o : bi){
            if (o.s==s){
                o.s.ptr.reset();
            }
        }
        for (auto& o : pa){
            if (o.s==s){
                o.s.ptr.reset();
            }
        }
        }
    else {
        auto& rk = w.Rook;
        auto& kn = w.Knight;
        auto& bi = w.Bishop;
        auto& pa = w.Pawn;
        auto& q = w.Queen;
        auto& k = w.King;

        if (k.s==s){
            k.s.ptr.reset();
        }
        if (q.s==s){
            q.s.ptr.reset();
        }
        for (auto& o : rk){
            if (o.s==s){
                o.s.ptr.reset();
            }
        }
        for (auto& o : kn){
            if (o.s==s){
                o.s.ptr.reset();
            }
        }
        for (auto& o : bi){
            if (o.s==s){
                o.s.ptr.reset();
            }
        }
        for (auto& o : pa){
            if (o.s==s){
                o.s.ptr.reset();
            }
        }
    }
}
bool amiok(square& s, white& w, black& b){
    if (s.isblack){
        auto& rk = b.Rook;
        auto& kn = b.Knight;
        auto& bi = b.Bishop;
        auto& pa = b.Pawn;
        auto& q = b.Queen;
        auto& k = b.King;
        if (k.s==s){
            if (k.s.ptr.get()!=s.ptr.get()){
                return false;   
            }
        }
        if (q.s==s){
            if (q.s.ptr.get()!=s.ptr.get()){
                return false; 
            }
        }
        for (auto& o : rk){
            if (o.s==s){
                if (o.s.ptr.get()!=s.ptr.get()){
                    return false; 
                }
            }
        }
        for (auto& o : kn){
            if (o.s==s){
                if (o.s.ptr.get()!=s.ptr.get()){
                    return false; 
                }
            }
        }
        for (auto& o : bi){
            if (o.s==s){
                if (o.s.ptr.get()!=s.ptr.get()){
                    return false; 
                }
            }
        }
        for (auto& o : pa){
            if (o.s==s){
                if (o.s.ptr.get()!=s.ptr.get()){
                    return false; 
                }
            }
        }
        }
    else {
        auto& rk = w.Rook;
        auto& kn = w.Knight;
        auto& bi = w.Bishop;
        auto& pa = w.Pawn;
        auto& q = w.Queen;
        auto& k = w.King;

        if (k.s==s){
            if (k.s.ptr.get()!=s.ptr.get()){
                return false;   
            }
        }
        if (q.s==s){
            if (k.s.ptr.get()!=s.ptr.get()){
                return false;   
            }
        }
        for (auto& o : rk){
            if (o.s==s){
                if (o.s.ptr.get()!=s.ptr.get()){
                    return false; 
                }
            }
        }
        for (auto& o : kn){
            if (o.s==s){
                if (o.s.ptr.get()!=s.ptr.get()){
                    return false; 
                }
            }
        }
        for (auto& o : bi){
            if (o.s==s){
                if (o.s.ptr.get()!=s.ptr.get()){
                    return false; 
                }
            }
        }
        for (auto& o : pa){
            if (o.s==s){
                if (o.s.ptr.get()!=s.ptr.get()){
                    return false; 
                }
            }
        }
    }
    return true;
}