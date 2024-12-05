#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>


using namespace std;

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

// g++ -c main.cpp -I"C:\Users\thoma\Documents\librairies\SFML-2.6.2\include"

// g++ main.o -o sfml-app -L"C:\Users\thoma\Documents\librairies\SFML-2.6.2\include" -lsfml-graphics -lsfml-window -lsfml-system

// vidéo tuto :
// https://www.youtube.com/watch?v=rZE700aaT5I