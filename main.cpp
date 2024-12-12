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
bool estdansinven = false;
int terrain[5][5] = {{1, 2, 1}, {1, 0, 1}};
sf::RectangleShape cell(sf::Vector2f(taillecellule - 1.0f, taillecellule - 1.0f));
std::vector<sf::RectangleShape> walls; // vecteur pour stocker les murs

void renderGrid(sf::RenderWindow &window)
{
    int x, y;

    window.clear();
    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            if (terrain[x][y] == 1) // Affichage des cases
            {
                cell.setPosition(y * taillecellule, x * taillecellule);
                walls.push_back(cell); // mets les cells dans le vecteur walls
                window.draw(cell);
            }
        }
    }
}

int main()
{
    Deplacement d0;
    Inventaire i0(0.f, 0.f, 1800.f, 1000.f);

    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(1800, 1000), "Donjon et dragons");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I)
            {
                i0.toggle(); // Ouvrir ou fermer l'inventaire
                if (estdansinven == false)
                {
                    estdansinven = true;
                }
                else
                {
                    estdansinven = false;
                }
            }
        }

        // Détecter l'appui sur la touche I pour ouvrir ou fermer l'inventaire

        // Gérer les entrées de direction
        if (estdansinven == false)
        {
            d0.gereinput();
        }

        // Temps écoulé depuis la dernière itération
        sf::Time deltaTime = clock.restart();

        // Mettre à jour la position du personnage
        d0.mettreajour(deltaTime, walls);

        // Rendu du terrain
        renderGrid(window);

        i0.draw(window);

        // Affichage du sprite du personnage
        window.draw(d0.getRectangle());

        // Affichage à l'écran
        window.display();
    }

    return 0;
}
