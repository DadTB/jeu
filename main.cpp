#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Terrain/generationterrain.cpp"

using namespace std;

int taillecellule = 50;
int grid[5][5] = {{1, 2, 1},{1,0,1}};

void renderGrid(sf::RenderWindow &window)
{
    int x,y;

    sf::RectangleShape cell(sf::Vector2f(taillecellule - 1.0f, taillecellule - 1.0f));
    window.clear();
    for (x = 0; x < 3; x++)
        {
            for (y = 0; y < 3; y++)
            {
                if (grid[x][y] == 1) // cette condition permet de ne remplir la fenêtre avec des cases blanches uniquement aux coordonnées dont la valeur est égale à 1
                {
                    cell.setPosition(y * taillecellule, x * taillecellule);
                    window.draw(cell);
                }
            }
        }
    window.display();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1800, 1000), "Donjon et dragons");
    //cell.setPosition();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderGrid(window);

    }

    return 0;
}

// g++ -c main.cpp -I"C:\Users\thoma\Documents\librairies\SFML-2.6.2\include"

// g++ main.o -o sfml-app -L"C:\Users\thoma\Documents\librairies\SFML-2.6.2\include" -lsfml-graphics -lsfml-window -lsfml-system

// vidéo tuto :
// https://www.youtube.com/watch?v=rZE700aaT5I