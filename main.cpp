#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Terrain/generationterrain.cpp"
#include "deplacement.cpp"
#include "Inventaire/inventaire.cpp"

using namespace std;

int taillecellule = 50;
int terrain[5][5] = {{1, 2, 1}, {1, 0, 1}};

void renderGrid(sf::RenderWindow &window)
{
    int x, y;

    sf::RectangleShape cell(sf::Vector2f(taillecellule - 1.0f, taillecellule - 1.0f));
    window.clear();
    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            if (terrain[x][y] == 1)  // Affichage des cases
            {
                cell.setPosition(y * taillecellule, x * taillecellule);
                window.draw(cell);
            }
        }
    }
}

int main()
{
    Deplacement d0;
    Inventaire i0;

    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(1800, 1000), "Donjon et dragons");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Gérer les entrées de direction
        d0.gereinput();

        // Temps écoulé depuis la dernière itération
        sf::Time deltaTime = clock.restart();
        
        // Mettre à jour la position du personnage
        d0.mettreajour(deltaTime);

        // Rendu du terrain
        renderGrid(window);

        //i0.ouvririnventaire();

        //window.draw(i0.ouvririnventaire());

        // Affichage du sprite du personnage
        window.draw(d0.getRectangle());

        // Affichage à l'écran
        window.display();
    }

    return 0;
}
