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
    int size=50;;
    int x0=50;
    int y0=50;
    srand(time(NULL));
    int randx, randy;

    board.spawnFruit();
    board.MovePacMan(Xp,Yp);
    board.MoveMonster(Xm,Ym);

    Music music;
    if (!music.openFromFile("music/button-31.wav"));
    Music music1;

    RenderWindow window(VideoMode(800, 600), "PacMan");
    sf::RectangleShape plansza[X][Y];
    sf::RectangleShape PacMan[X][Y];

    Text text3;
    text3.setFont(font);
    text3.setColor(sf::Color::White);
    text3.setCharacterSize(30);
    text3.setPosition(570, 50);
    text3.setString("FRUIT LEFT: ");
    text3.setOutlineColor(sf::Color::Black);
    text3.setOutlineThickness(3.f);

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
    while (window.isOpen())
    {

        Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed || ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape||board.getGameState()!=RUNNING)
                window.close();
        }

        int c=board.CountFruits();
        if(board.CountFruits()==24)
            text3.setString("FRUIT LEFT: 24");
        if(board.CountFruits()==23)
            text3.setString("FRUIT LEFT: 23");
        if(board.CountFruits()==22)
            text3.setString("FRUIT LEFT: 22");
        if(board.CountFruits()==21)
            text3.setString("FRUIT LEFT: 21");
        if(board.CountFruits()==20)
            text3.setString("FRUIT LEFT: 20");
        if(board.CountFruits()==19)
            text3.setString("FRUIT LEFT: 19");
        if(board.CountFruits()==18)
            text3.setString("FRUIT LEFT: 18");
        if(board.CountFruits()==17)
            text3.setString("FRUIT LEFT: 17");
        if(board.CountFruits()==16)
            text3.setString("FRUIT LEFT: 16");
        if(board.CountFruits()==15)
            text3.setString("FRUIT LEFT: 15");
        if(board.CountFruits()==14)
            text3.setString("FRUIT LEFT: 14");
        if(board.CountFruits()==13)
            text3.setString("FRUIT LEFT: 13");
        if(board.CountFruits()==12)
            text3.setString("FRUIT LEFT: 12");
        if(board.CountFruits()==11)
            text3.setString("FRUIT LEFT: 11");
        if(board.CountFruits()==10)
            text3.setString("FRUIT LEFT: 10");
        if(board.CountFruits()==9)
            text3.setString("FRUIT LEFT: 9");
        if(board.CountFruits()==8)
            text3.setString("FRUIT LEFT: 8");
        if(board.CountFruits()==8)
            text3.setString("FRUIT LEFT: 7");
        if(board.CountFruits()==7)
            text3.setString("FRUIT LEFT: 7");
        if(board.CountFruits()==6)
            text3.setString("FRUIT LEFT: 6");
        if(board.CountFruits()==5)
            text3.setString("FRUIT LEFT: 5");
        if(board.CountFruits()==4)
            text3.setString("FRUIT LEFT: 4");
        if(board.CountFruits()==3)
            text3.setString("FRUIT LEFT: 3");
        if(board.CountFruits()==2)
            text3.setString("FRUIT LEFT: 2");
        if(board.CountFruits()==1)
            text3.setString("FRUIT LEFT: 1");


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
        Sleep(100);

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

        if(board.isFruitHere(Xp, Yp)==true)
        {
            board.EatFruit(Xp, Yp);
            music.play();
        }

        randx=rand()%3-1;
        randy=rand()%3-1;

        if (randx==1&&randy==0&&board.isWallHere(Xm+1, Ym)==false)
        {
            Xm++;
            board.EmptyField(Xm-1, Ym);
        }
        if (randx==-1&&randy==0&&board.isWallHere(Xm-1, Ym)==false)
        {
            Xm--;
            board.EmptyField(Xm+1, Ym);
        }
        if (randx==0&&randy==1&&board.isWallHere(Xm, Ym+1)==false)
        {
            Ym++;
            board.EmptyField(Xm, Ym-1);
        }
        if (randx==0&&randy==-1&&board.isWallHere(Xm, Ym-1)==false)
        {
            Ym--;
            board.EmptyField(Xm, Ym+1);
        }

        board.MovePacMan(Xp, Yp);
        board.MoveMonster(Xm, Ym);
        window.clear(Color(0,130,0));


        window.draw(text3);
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
