#include "PacManSFMLgameresult.h"
#include "PacManBoard.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;


PacManSFMLgameresult::PacManSFMLgameresult(PacManBoard& board) :board(board)
{
}

void PacManSFMLgameresult::gameresult()
{

    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::RenderWindow window(sf::VideoMode(800, 600), "PacMan");

    sf::Text texta;
    if(board.getGameState()==FINISHED_WIN)
    {
        texta.setFont(font);
        texta.setColor(sf::Color::White);
        texta.setCharacterSize(100);
        texta.setPosition(800/2-200, 200);
        texta.setString("VICTORY");
        texta.setOutlineColor(sf::Color::Black);
        texta.setOutlineThickness(3.f);
    }
    else
    {
        texta.setFont(font);
        texta.setColor(sf::Color::White);
        texta.setCharacterSize(100);
        texta.setPosition(800/2-200, 200);
        texta.setString("DEFEAT");
        texta.setOutlineColor(sf::Color::Black);
        texta.setOutlineThickness(3.f);
    }


    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

        }

        // clear the window with black color
        window.clear(sf::Color(213, 215, 214));
        window.draw(texta);


        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }



}
