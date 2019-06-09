#include "PacManSFMLmenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

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
    if (!music.openFromFile("music/button-31.wav"));
    Music music1;
    if (!music1.openFromFile("music/BossFight.wav"));



    sf::Text texta;
    texta.setFont(font);
    texta.setColor(sf::Color::White);
    texta.setCharacterSize(100);
    texta.setPosition(800/2-200, 0);
    texta.setString("PacMan");
    texta.setOutlineColor(sf::Color::Black);
    texta.setOutlineThickness(3.f);

    Text text1;
    text1.setFont(font);
    text1.setColor(sf::Color::White);
    text1.setCharacterSize(100);
    text1.setPosition(400/2+80, 400-15);
    text1.setString("Start");
    text1.setOutlineColor(sf::Color::Black);
    text1.setOutlineThickness(3.f);

    Text text2;
    text2.setFont(font);
    text2.setColor(sf::Color::White);
    text2.setCharacterSize(50);
    text2.setPosition(400/2+60, 160);
    text2.setString("Sterowanie:");
    text2.setOutlineColor(sf::Color::Black);
    text2.setOutlineThickness(3.f);

    Text text[10];

    for(int i=3; i<8; i++)
    {
        text[i].setFont(font);
        text[i].setColor(sf::Color::White);
        text[i].setCharacterSize(30);
        text[i].setOutlineColor(sf::Color::Black);
        text[i].setOutlineThickness(3.f);
    }
    text[3].setPosition(400/2+120, 220);
    text[3].setString("UP :  W");
    text[4].setPosition(400/2+120, 260);
    text[4].setString("DOWN :  S");
    text[5].setPosition(400/2+120, 300);
    text[5].setString("LEFT :  A");
    text[6].setPosition(400/2+120, 340);
    text[6].setString("RIGHT :  D");




    RectangleShape button;
    button.setSize(sf::Vector2f(300,100));
    button.setFillColor(sf::Color(136, 154, 189));
    button.setPosition(400/2+30, 400);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(3.f);

    //music1.play();


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
            button.setOutlineThickness(4.f);
            text1.setOutlineThickness(4.f);
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                window.close();
            }
        }
        else
        {
            button.setOutlineThickness(3.f);
            text1.setOutlineThickness(3.f);
        }




        // clear the window with black color
        window.clear(sf::Color(213, 215, 214));
        window.draw(texta);
        window.draw(button);
        window.draw(text1);
        window.draw(text2);
        window.draw(text[3]);
        window.draw(text[4]);
        window.draw(text[5]);
        window.draw(text[6]);


        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }



}
