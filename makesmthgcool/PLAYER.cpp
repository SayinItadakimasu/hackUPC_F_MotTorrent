#include <iostream>
using namespace std;

#include <SDL/SDL.h>

#include "player.h"
#include "game.h"

bool CPlayer::bInit(){
    x = SCR_W/2;
    y = SCR_H/2;

    step = 8;

    return true;
}

void CPlayer::Move(int dir){
    switch(dir) {
        case UP:
            y -= step;
        break;

        case DOWN:
            y += step;
        break;

        case LEFT:
            x -= step;
        break;

        case RIGHT:
            x += step;
        break;
    }
}

void CPlayer::Draw(SDL_Surface* screen){
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.h = rect.w = 16;

    SDL_FillRect(screen, &rect, 0x0000FF);
}
