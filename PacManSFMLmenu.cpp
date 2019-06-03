#include "PacManSFMLmenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>

using namespace std;
using namespace sf;


PacManSFMLmenu::PacManSFMLmenu()
{
}

void PacManSFMLmenu::menu()
{

    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::RenderWindow window(sf::VideoMode(800, 600), "PacMan");

    Music music;
    if (!music.openFromFile("button-31.wav"));



    sf::Text texta;
    texta.setFont(font);
    texta.setColor(sf::Color::White);
    texta.setCharacterSize(100);
    texta.setPosition(800/2-200, 10);
    texta.setString("PacMan");
    texta.setOutlineColor(sf::Color::Black);
    texta.setOutlineThickness(3.f);

    Text text1;
    text1.setFont(font);
    text1.setColor(sf::Color::White);
    text1.setCharacterSize(100);
    text1.setPosition(400/2+80, 400-10);
    text1.setString("Start");
    text1.setOutlineColor(sf::Color::Black);
    text1.setOutlineThickness(3.f);




    RectangleShape button;
    button.setSize(sf::Vector2f(300,100));
    button.setFillColor(sf::Color(136, 154, 189));
    button.setPosition(400/2+30, 400);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(3.f);


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

        if(button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
        {
            music.play();
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                window.close();
            }
        }




        // clear the window with black color
        window.clear(sf::Color(213, 215, 214));
        window.draw(texta);
        window.draw(button);
        window.draw(text1);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }



}
