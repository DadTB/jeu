#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class GenerationTerrain
{
public:

    sf::RectangleShape cell;
    sf::RectangleShape herbe;
    sf::Texture textureherbe;

    GenerationTerrain()
    {
        cell.setSize(sf::Vector2f(taillecellule - 1.0f, taillecellule - 1.0f));

        if (!textureherbe.loadFromFile("Monde/TextureTerrain/textureherbe.jpg"))
        {
            // Si la texture ne se charge pas, afficher une erreur
            std::cerr << "Erreur de chargement de la texture !" << std::endl;
        }
        herbe.setSize(sf::Vector2f(taillecellule, taillecellule));
        herbe.setTexture(&textureherbe);
    }

    int taillecellule = 50;
    int terrain[10][20] = {
        {1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {1, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {1, 1, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}};

    std::vector<sf::RectangleShape> walls; // vecteur pour stocker les murs

    void renderGrid(sf::RenderWindow &window)
    {

        window.clear();
        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < 20; y++)
            {
                if (terrain[x][y] == 1) // Affichage des cases
                {
                    cell.setPosition(y * taillecellule, x * taillecellule);
                    walls.push_back(cell); // mets les cells dans le vecteur walls
                    window.draw(cell);
                }
                else if (terrain[x][y] == 2)
                {
                    herbe.setPosition(y * taillecellule, x * taillecellule);
                    window.draw(herbe);
                }
            }
        }
    }
};