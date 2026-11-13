#include "listeners.hpp"
#include "SDL_events.h"
#include "SDL_keyboard.h"
#include "SDL_mouse.h"
#include "SDL_scancode.h"

#define validsc(sc) sc>0 && sc<SDL_NUM_SCANCODES

bool keys[SDL_NUM_SCANCODES]={false};
bool prvkeys[SDL_NUM_SCANCODES]={false};

void c2KReg(SDL_KeyboardEvent k){
    auto sc = k.keysym.scancode;
    if (validsc(sc)){
        keys[sc]=(k.state==SDL_PRESSED);
    }
}
bool c2KIsPressed(SDL_KeyCode k){
    return c2KIsPressed(SDL_GetScancodeFromKey(k));
}
bool c2KIsPressed(SDL_Scancode sc){
    if (validsc(sc)){
        return keys[sc]&& !prvkeys[sc];
    }
    return false;
}
bool c2KIsDown(SDL_KeyCode k){
    return c2KIsDown(SDL_GetScancodeFromKey(k));
}
bool c2KIsDown(SDL_Scancode sc){
    if (validsc(sc)){
        return keys[sc];
    }
    return false;
}
void c2KUpdate(){
    for (int i=0;i<SDL_NUM_SCANCODES;i++){
        prvkeys[i]=keys[i];
    }
}


#define validb(b) b>0 && b<4

int x=0,y=0;
float scrlx=0,scrly=0;
bool buttons[3]={false},prvbuttons[3]={false};

void c2MReg(SDL_MouseMotionEvent m){
    x=m.x;
    y=m.y;
}
void c2MReg(SDL_MouseButtonEvent b){
    if (validb(b.button)){
        buttons[b.button-1]=(b.state==SDL_PRESSED);
    }
}
void c2MReg(SDL_MouseWheelEvent w){
    scrlx=w.preciseX;
    scrly=w.preciseY;

    if (w.direction==SDL_MOUSEWHEEL_FLIPPED){
        scrlx*=-1;
        scrly*=-1;
    }
}
bool c2MIsPressed(int b){
    if (validb(b)){
        return buttons[b-1] && !prvbuttons[b-1];
    }
    return false;
}
bool c2MIsDown(int b){
    if (validb(b)){
        return buttons[b-1];
    }
    return false;
}
int c2MGetX(){
    return x;
}
int c2MGetY(){
    return y;
}
float c2MGetScrlX(){
    return scrlx;
}
float c2MGetScrlY(){
    return scrly;
}
void c2MUpdate(){
    for (int i=0;i<3;i++){
        prvbuttons[i]=buttons[i];
    }
    scrlx=0;
    scrly=0;
}
SDL_Rect c2MGetRect(){
    return {c2MGetX(),c2MGetY(),1,1};
}