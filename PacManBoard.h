#ifndef PACMANBOARD_H_
#define PACMANBOARD_H_

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

struct Field
{
    bool hasFruit;
    bool PacManPosition;
    bool isWall;
    bool MonsterPosition;
};

class PacManBoard
{
    Field board[100][100];
    int width;
    int height;
public:
    PacManBoard(int, int);
    void debug_display();
    int getBoardWidth();
    int getBoardHeight();
    bool isWallHere(int, int);
    bool isPacManHere(int, int);
    bool isMonsterHere(int, int);
    void spawnFruit();
    void spawnMonster();
    bool isFruitHere(int, int);


};

#endif
