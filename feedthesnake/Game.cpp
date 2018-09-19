#include "Game.hpp"


Game::Game():gameOver(false),height(20),width(20),score(0){}


void Game::pSnakeSetUp()
{
    head.first = height/2;
    head.second = width/2;
    direction = STOP;
    body.push_front(head);
}

void Game::pFruitSetUp()
{  
    fruit.first = (rand() % (height + 1 - 0));
    fruit.second =(rand() % (width + 1 - 0));
}

void Game::gameSetup()
{
    pSnakeSetUp();
    pFruitSetUp();
}
bool Game::getGameOver()
{
    return gameOver;
}

bool Game::pPrintSnake(std::pair<int, int> position)
{
    int count = 1;
    for(std::pair <int, int> &p1: body)
    {
        if(position == p1)
        {
            if(count == 1)
                std::cout <<  'O';  
            else
                std::cout <<  'o'; 
            return true;
        }
        count++;
    }
    return false;

}
bool Game::pPrintFruit(std::pair<int, int> position)
{
    
    if (position == fruit) 
    {
        std::cout <<  'F';  
        return true; 
    }       
}

void Game::draw()
{
    std::system("clear");
    for(size_t i = 0; i < width; i++)
    {
        std::cout<<"#";
    }

    std::cout<<std::endl;
    for(size_t i = 1; i < height - 1; i++)
    {
        std::cout<<"#";
        for(size_t j = 0; j < width ; j++)
        {
            if(!pLogic(i,j))
                std::cout<<" ";
        }
        std::cout<<"#"<<std::endl;

    }
    for(size_t i = 0; i < width; i++)
    {
        std::cout<<"#";
    }
    std::cout<<std::endl;

}

void Game::input()
{
    char control = std::cin.get();
    switch(control)
    {
        case 'w':
            head.first--;
            break;
        case 'd':
            head.second++;
            break;
        case 'a':
            head.second--;
            break;
        case 's':
            head.  first++;      
        case 'x':
            gameOver = true;                             
        default:
            break;
    }
}

bool Game::pLogic(int x, int y)
{
    bool flag1 = pPrintFruit(std::make_pair(x,y));
    bool flag2 = pPrintSnake(std::make_pair(x,y));
    
    
    if (flag1 || flag2) 
        return true;
    else   
        return false;
}

void Game::logic()
{
    
    if(head.first >= height || head.first <= 0 || head.second >= width ||   head.second <= 0)
    {
        gameOver = true;
    }


    if(head == fruit)
    {

        body.push_front(fruit);
        
        fruit.first = (rand() % (height + 1 - 0));
        fruit.second =(rand() % (width + 1 - 0));
    }
    else
    {
        body.pop_front();
        body.push_front(head);

        // figure out how to swap things here.
        if(body.size() != 1)
        {

        }

    }


}