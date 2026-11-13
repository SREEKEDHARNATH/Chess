#include "listeners.hpp"
#include "SDL_events.h"
#include "SDL_keyboard.h"
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