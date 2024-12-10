#pragma once

#include <vector>

#include <SFML/Graphics.hpp>


class Inventaire
{
private:
    std::vector<float> IdInventaire;
    
    int tailleInventaire = 500;

    sf::RectangleShape Inventairefenetre;

public:

    Inventaire()
    {
        Inventairefenetre.setSize(sf::Vector2f(tailleInventaire - 1.0f, tailleInventaire - 1.0f));
        Inventairefenetre.setFillColor(sf::Color(250, 0, 0));
    }

    ~Inventaire() {}

    sf::RectangleShape& ouvririnventaire()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        {
            return Inventairefenetre;
        }
    }

};