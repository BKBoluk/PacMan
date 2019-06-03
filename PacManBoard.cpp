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
        }

    }
    board[width/2][height/2].PacManPosition=true;
    for(int i=0; i<=width; i++)
    {
        for(int j=0; j<=height; j++)
        {
            board[j][3].isWall=true;
        }

    }
    board[3][9].isWall=true;

}

bool PacManBoard::isWallHere(int x, int y)
{
    if(board[x][y].isWall==true)
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
