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
            board[9][i].isWall=true;
            board[j][0].isWall=true;
            board[j][9].isWall=true;
        }

    }

    for(int i=2; i<=width-3; i++)
    {
        for(int j=2; j<=height-3; j++)
        {
            board[2][i].isWall=true;
            board[7][i].isWall=true;
            board[j][2].isWall=true;
            board[j][7].isWall=true;
        }

    }
    board[5][4].isWall=true;
    board[4][4].isWall=true;
    board[2][5].isWall=false;
    board[7][5].isWall=false;
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
    int MonsterCount=3;
    srand(time(NULL));
    int x=0;
    int y=0;

    while(MonsterCount!=0)
    {
        x=rand()%width;
        y=rand()%height;
        if(board[x][y].isWall==false&&board[x][y].hasFruit==false&&board[x][y].MonsterPosition==false)
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

int PacManBoard::getBoardHeight()
{
    return height;
}


int PacManBoard::getBoardWidth()
{
    return width;
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
