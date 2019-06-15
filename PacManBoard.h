#ifndef PACMANBOARD_H_
#define PACMANBOARD_H_

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

enum GameState {RUNNING, FINISHED_WIN, FINISHED_LOSS};

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
    int getBoardWidth();
    int getBoardHeight();
    int getPacManXPos();
    int getPacManYPos();
    int CountFruits();
    bool isWallHere(int, int);
    bool isPacManHere(int, int);
    bool isMonsterHere(int, int);
    bool isFruitHere(int, int);
    bool isEmpty(int, int);
    void spawnFruit();
    void spawnMonster();
    void MovePacMan(int, int);
    void EmptyField(int, int);
    void EatFruit(int, int);
    void debug_display();
    GameState getGameState();



};

#endif
