#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>  // Pour std::sqrt()

class Deplacement
{
public:
    int taillepersonnage = 50;  // Taille du personnage (carré)

    sf::RectangleShape rectangle;  // Rectangle représentant le personnage
    float vitessedeplacement = 100.f;  // Vitesse de déplacement
    sf::Vector2f direction;     // Direction du mouvement

    // Constructeur
    Deplacement()
    {
        // Créer le rectangle représentant le personnage
        rectangle.setSize(sf::Vector2f(taillepersonnage, taillepersonnage));  // Définir la taille
        rectangle.setFillColor(sf::Color(100, 250, 50));  // Définir la couleur (vert clair)
        rectangle.setPosition(400.f, 300.f);  // Position initiale du personnage

        vitessedeplacement = 100.f;  // Initialisation de la vitesse
    }

    ~Deplacement() {}

    // Mise à jour de la position en fonction de la direction
    void mettreajour(const sf::Time &deltaTime)
    {
        // Déplacer le rectangle (le personnage) en fonction de la direction et de la vitesse
        rectangle.move(direction * vitessedeplacement * deltaTime.asSeconds());
    }

    // Gérer les entrées utilisateur
    void gereinput()
    {
        // Réinitialiser la direction à chaque mise à jour des entrées
        direction = sf::Vector2f(0.f, 0.f);

        // Détecter les touches de direction et définir la direction du mouvement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            direction.y = -1.f;  // Déplacer vers le haut
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            direction.y = 1.f;  // Déplacer vers le bas
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            direction.x = -1.f;  // Déplacer vers la gauche
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            direction.x = 1.f;  // Déplacer vers la droite
        }

        // Normaliser la direction pour gérer les diagonales (déplacement uniforme)
        if (direction.x != 0.f && direction.y != 0.f)
        {
            direction /= std::sqrt(2.f);  // Réduction de la vitesse en diagonale
        }
    }

    // Récupérer le rectangle pour l'afficher dans le main
    sf::RectangleShape& getRectangle()
    {
        return rectangle;
    }
};