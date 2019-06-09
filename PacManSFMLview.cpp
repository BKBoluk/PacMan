#include "PacManBoard.h"
#include "PacManSFMLview.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;


PacManSFMLview::PacManSFMLview(PacManBoard& board) :board(board)
{
}

void PacManSFMLview::view()
{
    sf::Font font;
    font.loadFromFile("arial.ttf");
    int X=board.getBoardWidth();
    int Y=board.getBoardHeight();
    int size=50;;
    int x0=50;
    int y0=50;

    Music music1;
    if (!music1.openFromFile("music/BossFight.wav"));

    board.spawnFruit();
    board.spawnMonster();

    RenderWindow window(VideoMode(800, 600), "PacMan");
    sf::RectangleShape plansza[X][Y];
    sf::RectangleShape PacMan[X][Y];

    Text text3;
    text3.setFont(font);
    text3.setColor(sf::Color::White);
    text3.setCharacterSize(30);
    text3.setPosition(400/2+60, 550);
    text3.setString("Music: BossFight - Milky Ways");
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
    music1.play();
    double x=0;
    while (window.isOpen())
    {

        Event ev;
        int wd=800;
        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed || ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
                window.close();
        }

        int z;
        z=wd-x;
        x+=0.05;
        if(z==-400)
        {
            x=0;
        }
        text3.setPosition(z, 550);


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
                    PacMan[j][i].setSize(sf::Vector2f(size/2,size/2));
                    PacMan[j][i].setPosition( i *size+x0+size/4, j*size+y0+size/4);
                    PacMan[j][i].setFillColor(sf::Color::Blue);
                    PacMan[j][i].setOutlineColor(sf::Color::Black);
                    PacMan[j][i].setOutlineThickness(2.f);
                }
                if(board.isMonsterHere(i,j)==true)
                {
                    PacMan[j][i].setSize(sf::Vector2f(size/2,size/2));
                    PacMan[j][i].setPosition( i *size+x0+size/4, j*size+y0+size/4);
                    PacMan[j][i].setFillColor(sf::Color::Yellow);
                    PacMan[j][i].setOutlineColor(sf::Color::Black);
                    PacMan[j][i].setOutlineThickness(2.f);
                }
            }
        }

        window.clear(Color::Black);

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
