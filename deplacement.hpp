#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

class Deplacement
{
public:
    int taillepersonnage = 50;

    sf::Sprite sprite;
    sf::Texture texture;
    float vitessedeplacement;
    sf::Vector2f direction;

    Deplacement() {}
    ~Deplacement() {}

    void mettreajour(const sf::Time &deltaTime)
    {
        // Mise à jour de la position en fonction de la direction
        sprite.move(direction * vitessedeplacement * deltaTime.asSeconds());
    }

    void gereinput(const sf::Keyboard::Key &key)
    {
        // Réinitialiser la direction à chaque mise à jour des entrées
        direction = sf::Vector2f(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            direction.y = -1.f; // Déplacer vers le haut
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            direction.y = 1.f; // Déplacer vers le bas
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            direction.x = -1.f; // Déplacer vers la gauche
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            direction.x = 1.f; // Déplacer vers la droite
        }

        // Normaliser la direction pour gérer les diagonales (déplacement uniforme)
        if (direction.x != 0.f && direction.y != 0.f)
        {
            direction /= std::sqrt(2.f); // Réduction de la vitesse en diagonale
        }
    }
};