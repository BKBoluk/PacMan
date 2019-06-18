#include "PacManBoard.h"
#include "PacManSFMLview.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <time.h>

using namespace std;
using namespace sf;

enum PacManDirection {UP, DOWN, LEFT, RIGHT, NONE};

PacManDirection currentDirection = NONE;

enum MonsterDirection {UP1, DOWN1, LEFT1, RIGHT1, NONE1};

MonsterDirection MonstercurrentDirection = RIGHT1;

PacManSFMLview::PacManSFMLview(PacManBoard& board) :board(board)
{
}

void PacManSFMLview::view()
{
    sf::Font font;
    font.loadFromFile("arial.ttf");
    board.spawnMonster();
    int X=board.getBoardWidth();
    int Y=board.getBoardHeight();
    int Xp=board.getPacManXPos();
    int Yp=board.getPacManYPos();
    int Xm=board.getMonsterXPos();
    int Ym=board.getMonsterYPos();
    int size=25;
    int x0=50;
    int y0=50;
    srand(time(NULL));
    int randx, randy;

    board.spawnFruit();
    board.MovePacMan(Xp,Yp);
    board.MoveMonster(Xm,Ym);

    RenderWindow window(VideoMode(800, 600), "PacMan");
    sf::RectangleShape plansza[X][Y];
    sf::RectangleShape PacMan[X][Y];
    sf::RectangleShape Icon[10];

    Text text[10];
    for(int i=0; i<10; i++)
    {
        text[i].setFont(font);
        text[i].setColor(sf::Color::White);
        text[i].setCharacterSize(30);
        text[i].setOutlineColor(sf::Color::Black);
        text[i].setOutlineThickness(3.f);
    }

    for(int i=0; i<10; i++)
    {
        Icon[i].setPosition(570,100);
        Icon[i].setSize(sf::Vector2f(50,50));
        Icon[i].setFillColor(sf::Color::Red);
        Icon[i].setOutlineColor(sf::Color::Black);
        Icon[i].setOutlineThickness(2.f);
    }

    Icon[1].setPosition(570,200);
    Icon[1].setFillColor(sf::Color::Yellow);

    Icon[2].setPosition(570,300);
    Icon[2].setFillColor(sf::Color::Blue);

    text[0].setPosition(650, 300);
    text[0].setString("- PacMan");

    text[1].setPosition(570, 50);
    text[1].setString("FRUIT LEFT: 25");

    text[2].setPosition(650, 100);
    text[2].setString("- Fruit");

    text[3].setPosition(650, 200);
    text[3].setString("- Monster");

    for(size_t i = 0; i < X; i++)
    {

        for(size_t j = 0; j < Y; j++)
        {
            plansza[j][i].setSize(sf::Vector2f(size,size));
            plansza[j][i].setPosition( i *size+x0, j*size+y0);
            plansza[j][i].setFillColor(sf::Color(0,100,0));
            plansza[j][i].setOutlineColor(sf::Color::Black);
            plansza[j][i].setOutlineThickness(2.f);
        }
    }
    int licznik=0;
    while (window.isOpen())
    {
        licznik++;
        Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed || ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape||board.getGameState()!=RUNNING)
                window.close();
        }
        if(board.CountFruits()==24)
            text[1].setString("FRUIT LEFT: 24");
        if(board.CountFruits()==23)
            text[1].setString("FRUIT LEFT: 23");
        if(board.CountFruits()==22)
            text[1].setString("FRUIT LEFT: 22");
        if(board.CountFruits()==21)
            text[1].setString("FRUIT LEFT: 21");
        if(board.CountFruits()==20)
            text[1].setString("FRUIT LEFT: 20");
        if(board.CountFruits()==19)
            text[1].setString("FRUIT LEFT: 19");
        if(board.CountFruits()==18)
            text[1].setString("FRUIT LEFT: 18");
        if(board.CountFruits()==17)
            text[1].setString("FRUIT LEFT: 17");
        if(board.CountFruits()==16)
            text[1].setString("FRUIT LEFT: 16");
        if(board.CountFruits()==15)
            text[1].setString("FRUIT LEFT: 15");
        if(board.CountFruits()==14)
            text[1].setString("FRUIT LEFT: 14");
        if(board.CountFruits()==13)
            text[1].setString("FRUIT LEFT: 13");
        if(board.CountFruits()==12)
            text[1].setString("FRUIT LEFT: 12");
        if(board.CountFruits()==11)
            text[1].setString("FRUIT LEFT: 11");
        if(board.CountFruits()==10)
            text[1].setString("FRUIT LEFT: 10");
        if(board.CountFruits()==9)
            text[1].setString("FRUIT LEFT: 9");
        if(board.CountFruits()==8)
            text[1].setString("FRUIT LEFT: 8");
        if(board.CountFruits()==8)
            text[1].setString("FRUIT LEFT: 7");
        if(board.CountFruits()==7)
            text[1].setString("FRUIT LEFT: 7");
        if(board.CountFruits()==6)
            text[1].setString("FRUIT LEFT: 6");
        if(board.CountFruits()==5)
            text[1].setString("FRUIT LEFT: 5");
        if(board.CountFruits()==4)
            text[1].setString("FRUIT LEFT: 4");
        if(board.CountFruits()==3)
            text[1].setString("FRUIT LEFT: 3");
        if(board.CountFruits()==2)
            text[1].setString("FRUIT LEFT: 2");
        if(board.CountFruits()==1)
            text[1].setString("FRUIT LEFT: 1");

        for(size_t i = 0; i < X; i++)
        {

            for(size_t j = 0; j < Y; j++)
            {
                if(board.isWallHere(i,j)==true)
                {
                    plansza[j][i].setSize(sf::Vector2f(size,size));
                    plansza[j][i].setPosition( i *size+x0, j*size+y0);
                    plansza[j][i].setFillColor(sf::Color(213, 215, 214));
                    plansza[j][i].setOutlineColor(sf::Color::Black);
                    plansza[j][i].setOutlineThickness(2.f);
                }
                if(board.isFruitHere(i,j)==true)
                {
                    PacMan[j][i].setSize(sf::Vector2f(size/2,size/2));
                    PacMan[j][i].setPosition( i *size+x0+size/4, j*size+y0+size/4);
                    PacMan[j][i].setFillColor(sf::Color::Red);
                    PacMan[j][i].setOutlineColor(sf::Color::Black);
                    PacMan[j][i].setOutlineThickness(2.f);
                }
                if(board.isPacManHere(i,j)==true)
                {
                    PacMan[j][i].setSize(sf::Vector2f(size,size));
                    PacMan[j][i].setPosition( i *size+x0, j*size+y0);
                    PacMan[j][i].setFillColor(sf::Color::Blue);
                    PacMan[j][i].setOutlineColor(sf::Color::Black);
                    PacMan[j][i].setOutlineThickness(2.f);
                }
                if(board.isMonsterHere(i,j)==true)
                {
                    PacMan[j][i].setSize(sf::Vector2f(size,size));
                    PacMan[j][i].setPosition( i *size+x0, j*size+y0);
                    PacMan[j][i].setFillColor(sf::Color::Yellow);
                    PacMan[j][i].setOutlineColor(sf::Color::Black);
                    PacMan[j][i].setOutlineThickness(2.f);
                }
                if(board.isEmpty(i,j)==true)
                {
                    PacMan[j][i].setSize(sf::Vector2f(size,size));
                    PacMan[j][i].setPosition( i *size+x0, j*size+y0);
                    PacMan[j][i].setFillColor(sf::Color(0,100,0));
                    PacMan[j][i].setOutlineColor(sf::Color::Black);
                    PacMan[j][i].setOutlineThickness(2.f);
                }
            }
        }

        Sleep(70);
        //================================sterowanie zwyk³e=================
        if ((Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))&&board.isWallHere(Xp+1,Yp)==false)
        {
            Xp++;
            board.EmptyField(Xp-1, Yp);
        }
        if ((Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))&&board.isWallHere(Xp-1,Yp)==false)
        {
            Xp--;
            board.EmptyField(Xp+1, Yp);
        }
        if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))&&board.isWallHere(Xp,Yp-1)==false)
        {
            Yp--;
            board.EmptyField(Xp, Yp+1);
        }
        if ((Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))&&board.isWallHere(Xp,Yp+1)==false)
        {
            Yp++;
            board.EmptyField(Xp, Yp-1);
        }
        //==============================================================


        /*if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))  //Sterowanie Pacmanem. PacMan bedzie szed³ w kierunku a¿ natrafi na œcianê lub zmienimy kierunek
            currentDirection = RIGHT;
        if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
            currentDirection = LEFT;
        if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
            currentDirection = UP;
        if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
            currentDirection = DOWN;


        if (currentDirection==RIGHT&board.isWallHere(Xp+1,Yp)==false)
        {
            Xp++;
            board.EmptyField(Xp-1, Yp);
        }
        if (currentDirection==LEFT&board.isWallHere(Xp-1,Yp)==false)
        {
            Xp--;
            board.EmptyField(Xp+1, Yp);
        }
        if(currentDirection==UP&board.isWallHere(Xp,Yp-1)==false)
        {
            Yp--;
            board.EmptyField(Xp, Yp+1);
        }
        if(currentDirection==DOWN&board.isWallHere(Xp,Yp+1)==false)
        {
            Yp++;
            board.EmptyField(Xp, Yp-1);
        }*/

        if(board.isFruitHere(Xp, Yp)==true)
        {
            board.EatFruit(Xp, Yp);
        }

        if(licznik%3==0)
        {
            randx=rand()%4+1;
            if(randx==1)
                MonstercurrentDirection=LEFT1;
            if(randx==2)
                MonstercurrentDirection=RIGHT1;
            if(randx==3)
                MonstercurrentDirection=UP1;
            if(randx==4)
                MonstercurrentDirection=DOWN1;
        }

        if (MonstercurrentDirection==LEFT1&&board.isWallHere(Xm+1, Ym)==false)
        {
            Xm++;
            board.EmptyField(Xm-1, Ym);
        }
        if (MonstercurrentDirection==RIGHT1&&board.isWallHere(Xm-1, Ym)==false)
        {
            Xm--;
            board.EmptyField(Xm+1, Ym);
        }
        if (MonstercurrentDirection==UP1&&board.isWallHere(Xm, Ym+1)==false)
        {
            Ym++;
            board.EmptyField(Xm, Ym-1);
        }
        if (MonstercurrentDirection==DOWN1&&board.isWallHere(Xm, Ym-1)==false)
        {
            Ym--;
            board.EmptyField(Xm, Ym+1);
        }

        board.MovePacMan(Xp, Yp);
        board.MoveMonster(Xm, Ym);
        window.clear(Color(0,130,0));

        for(int i=0; i<=3; i++)
        {
            window.draw(text[i]);
            window.draw(Icon[i]);
        }

        for(size_t i = 0; i < X; i++)
        {
            for(size_t j = 0; j < Y; j++)
            {
                window.draw(plansza[j][i]);
                window.draw(PacMan[j][i]);
            }
        }
        window.display();
    }
}
