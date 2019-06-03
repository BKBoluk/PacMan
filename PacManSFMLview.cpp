#include "PacManBoard.h"
#include "PacManSFMLview.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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

    RenderWindow window(VideoMode(800, 600), "PacMan");
    sf::RectangleShape plansza[X][Y];

    for(size_t i = 0; i < X; i++)
    {

        for(size_t j = 0; j < Y; j++)
        {
            plansza[j][i].setSize(sf::Vector2f(size,size));
            plansza[j][i].setPosition( i *size+x0, j*size+y0);
            plansza[j][i].setFillColor(sf::Color(0,100,0));
            plansza[j][i].setOutlineColor(sf::Color::Yellow);
            plansza[j][i].setOutlineThickness(2.f);
        }
    }

    while (window.isOpen())
    {

        Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed || ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
                window.close();
        }



        for(size_t i = 0; i < X; i++)
        {

            for(size_t j = 0; j < Y; j++)
            {
                if(board.isWallHere(i,j)==true)
                {
                    plansza[j][i].setSize(sf::Vector2f(size,size));
                    plansza[j][i].setPosition( i *size+x0, j*size+y0);
                    plansza[j][i].setFillColor(sf::Color::Red);
                    plansza[j][i].setOutlineColor(sf::Color::Yellow);
                    plansza[j][i].setOutlineThickness(2.f);
                }


            }
        }

        window.clear(Color::Black);


        for(size_t i = 0; i < X; i++)
        {
            for(size_t j = 0; j < Y; j++)
            {
                window.draw(plansza[j][i]);
            }
        }


        window.display();
    }
}

