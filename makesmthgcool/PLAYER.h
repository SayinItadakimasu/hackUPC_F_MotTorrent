#ifndef PLAYER_DEFINED
#define PLAYER_DEFINED

#include <iostream>

class CPlayer{
public:
    bool bInit();
    void Move(int dir);
    void Draw(SDL_Surface* screen);
private:
    int x,y;
    int step;
};

#endif
