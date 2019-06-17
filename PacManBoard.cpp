#include <iostream>
#include "PacManBoard.h"
#include <time.h>
#include <cstdlib>

using namespace std;


PacManBoard::PacManBoard(int w, int h):width(w), height(h)
{
    for(int i=0; i<=width; i++)
    {
        for(int j=0; j<=height; j++)
        {
            board[j][i].hasFruit=false;
            board[j][i].PacManPosition=false;
            board[j][i].MonsterPosition=false;
            board[0][i].isWall=true;
            board[19][i].isWall=true;
            board[j][0].isWall=true;
            board[j][19].isWall=true;
        }
    }
    for(int i=2; i<=width-3; i++)
    {
        for(int j=2; j<=height-3; j++)
        {
            board[2][i].isWall=true;
            board[17][i].isWall=true;
            board[j][2].isWall=true;
            board[j][17].isWall=true;
        }
    }
    for(int i=4; i<=width-5; i++)
    {
        for(int j=4; j<=height-5; j++)
        {
            board[4][i].isWall=true;
            board[15][i].isWall=true;
            board[j][4].isWall=true;
            board[j][15].isWall=true;
        }
    }
    for(int i=6; i<=width-7; i++)
    {
        for(int j=6; j<=height-7; j++)
        {
            board[6][i].isWall=true;
            board[13][i].isWall=true;
            board[j][6].isWall=true;
            board[j][13].isWall=true;
        }
    }

    board[10][10].isWall=true;
    board[9][10].isWall=true;
    board[10][9].isWall=true;
    board[9][9].isWall=true;

    board[10][2].isWall=false;
    board[10][4].isWall=false;
    board[10][6].isWall=false;
    board[9][2].isWall=false;
    board[9][4].isWall=false;
    board[9][6].isWall=false;

    board[10][17].isWall=false;
    board[10][15].isWall=false;
    board[10][13].isWall=false;
    board[9][17].isWall=false;
    board[9][15].isWall=false;
    board[9][13].isWall=false;

    board[2][10].isWall=false;
    board[4][10].isWall=false;
    board[6][10].isWall=false;
    board[2][9].isWall=false;
    board[4][9].isWall=false;
    board[6][9].isWall=false;

    board[17][10].isWall=false;
    board[15][10].isWall=false;
    board[13][10].isWall=false;
    board[17][9].isWall=false;
    board[15][9].isWall=false;
    board[13][9].isWall=false;

    board[7][5].PacManPosition=true;
}

void PacManBoard::spawnFruit()
{
    int FruitCount=25;
    srand(time(NULL));
    int x=0;
    int y=0;

    while(FruitCount!=0)
    {
        x=rand()%width;
        y=rand()%height;
        if(board[x][y].isWall==false&&board[x][y].hasFruit==false)
        {
            board[x][y].hasFruit=true;
            FruitCount--;
        }
    }
}

void PacManBoard::spawnMonster()
{
    int MonsterCount=1;
    srand(time(NULL));
    int x=0;
    int y=0;

    while(MonsterCount!=0)
    {
        x=rand()%width;
        y=rand()%height;
        if(board[x][y].isWall==false&&board[x][y].hasFruit==false&&board[x][y].MonsterPosition==false&&board[x][y].PacManPosition==false)
        {
            board[x][y].MonsterPosition=true;
            MonsterCount--;
        }
    }
}

bool PacManBoard::isMonsterHere(int x, int y)
{
    if(board[x][y].MonsterPosition==true)
        return true;
    else
        return false;
}

bool PacManBoard::isWallHere(int x, int y)
{
    if(board[x][y].isWall==true)
        return true;
    else
        return false;
}

bool PacManBoard::isFruitHere(int x, int y)
{
    if(board[x][y].hasFruit==true)
        return true;
    else
        return false;
}

bool PacManBoard::isPacManHere(int x, int y)
{
    if(board[x][y].PacManPosition==true)
        return true;
    else
        return false;
}

bool PacManBoard::isEmpty(int x, int y)
{
    if(board[x][y].hasFruit==false&&board[x][y].PacManPosition==false&&board[x][y].MonsterPosition==false&&board[x][y].isWall==false)
        return true;
    else
        return false;
}


void PacManBoard::MovePacMan(int x, int y)
{
    board[x][y].PacManPosition=true;
}

void PacManBoard::MoveMonster(int x, int y)
{
    board[x][y].MonsterPosition=true;
}

void PacManBoard::EmptyField(int x, int y)
{
    board[x][y].PacManPosition=false;
    board[x][y].MonsterPosition=false;
}

void PacManBoard::EatFruit(int x, int y)
{
    board[x][y].hasFruit=false;
}

int PacManBoard::getBoardHeight()
{
    return height;
}


int PacManBoard::getBoardWidth()
{
    return width;
}

int PacManBoard::getPacManXPos()
{
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            if(board[j][i].PacManPosition==true)
                return j;
        }
    }
}

int PacManBoard::getPacManYPos()
{
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            if(board[j][i].PacManPosition==true)
                return i;
        }
    }
}

int PacManBoard::getMonsterXPos()
{
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            if(board[j][i].MonsterPosition==true)
                return j;
        }
    }
}

int PacManBoard::getMonsterYPos()
{
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            if(board[j][i].MonsterPosition==true)
                return i;
        }
    }
}

int PacManBoard::CountFruits()
{
    int FruitCount=0;
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            if(board[j][i].hasFruit==true)
                FruitCount++;
        }
    }
    return FruitCount;
}

GameState PacManBoard::getGameState()
{
    int state=0;
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            if(board[j][i].PacManPosition==true&&board[j][i].MonsterPosition==true)
                state=1;
        }
    }
    if(CountFruits()==0)
        return FINISHED_WIN;
    if(state==1)
        return FINISHED_LOSS;
    else
        return RUNNING;
}


void PacManBoard::debug_display()
{
    cout<<endl;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            cout<<"[";
            if(board[j][i].hasFruit==false)
                cout<<".";
            else
                cout<<"F";
            if(board[j][i].PacManPosition==false)
                cout<<".";
            else
                cout<<"S";
            if(board[j][i].isWall==false)
                cout<<".";
            else
                cout<<"X";
            cout<<"]";
        }
        cout<<endl;
    }
}
