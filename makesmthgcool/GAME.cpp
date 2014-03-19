#include <iostream>
using namespace std;

#include <SDL/SDL.h>

#include "game.h"
#include "player.h"

bool CGame::bInit(){

    SDL_Init( SDL_INIT_VIDEO );
    screen = SDL_SetVideoMode(SCR_W,SCR_H,16,SDL_HWSURFACE);

    SDL_ShowCursor(SDL_DISABLE);

    cicle = 100;

    return true;

}

void CGame::Main(){
    CPlayer player;
    player.bInit();

    bool exit = false;
    while (not exit){

    unsigned int time = SDL_GetTicks();

    //INPUTS//
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                exit = true;
            break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    default:
                    break;
                }
            break;
        }
    }

    unsigned char *keystate = SDL_GetKeyState(NULL);

    //LOGICS//
    if (keystate[SDLK_UP]) player.Move(UP);
    if (keystate[SDLK_DOWN]) player.Move(DOWN);
    if (keystate[SDLK_LEFT]) player.Move(LEFT);
    if (keystate[SDLK_RIGHT]) player.Move(RIGHT);

    //OUTPUTS//
    SDL_FillRect(screen,NULL,0);
    player.Draw(screen);
    SDL_Flip(screen);

    //SYNC//
    unsigned int time_now = SDL_GetTicks();
    if ((time_now - time) < cicle)
        SDL_Delay(cicle - (time_now - time));

    SDL_Quit();
}
