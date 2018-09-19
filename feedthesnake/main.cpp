#include "Game.hpp"

int main(int argc, char const *argv[])
{
    Game g1;
    g1.gameSetup();
    int temp;
    while(!g1.getGameOver())
    {
        g1.draw();
        g1.input();
        g1.logic();

    }
    
    return 0;
}
