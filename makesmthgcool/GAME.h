#ifndef GAME_DEFINED
#define GAME_DEFINED

#define SCR_W 640
#define SCR_H 480

#include <SDL/SDL.h>

enum eDir{UP,DOWN,LEFT,RIGHT};

class CGame{
public:
    bool bInit();
    void Main();
private:
    SDL_Surface* screen;
    int cicle;
};

#endif
