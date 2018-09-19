#ifndef _GAME_FEEDTHESNAKE
#define _GAME_FEEDTHESNAKE

#include <iostream>
#include <cstdlib>
#include <utility>
#include <ctime>
#include <list>
#include <iterator>
#include <deque>
/*
Class Game will contain the following member data. Use Constructor for initialization and use the access specifiers appropriately to incorporate data hiding:
- a. Boolean variable to indicate if the game is over which is initialized to false
- b. Constant integer variables - width and height of the border/map initialized to 20
- c. Integer variables for head position initialized to 0,0
- d. Integer variables for fruit position initialized to 0,0
- e. Integer score variable initialized to 0
- f. To track directions of the snake: use enum variable to track STOP, LEFT, RIGHT, UP, DOWN
In the class Game, you will have the following member functions:
a. snakeSetUp()
b. fruitSetUp()
c. draw()
d. input()
e. logic()


*/


enum motion { STOP, LEFT, RIGHT, UP, DOWN};

class Game
{
    public:
        Game();
        ~Game(){};
        void gameSetup();
        bool getGameOver();
        void draw();
        void input();
        void logic();


    private:
        bool gameOver;

        const int height;
        const int width;
        std::pair <int, int> head;
        std::pair <int, int> fruit;
        enum motion direction; 
        int score;
        void pSnakeSetUp();
        void pFruitSetUp();        
        bool pPrintSnake(std::pair<int, int> position);
        bool pPrintFruit(std::pair<int, int> position);
        bool pLogic(int i, int j);
        std::deque < std::pair <int, int> > body;
        

        
};


#endif