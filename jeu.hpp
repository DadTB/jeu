#pragma once

#include <string>
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Monde/generationterrain.cpp"
#include "Composant/deplacement.cpp"
#include "Inventaire/inventaire.cpp"
//#include "Entitee.cpp"
#include "Etat/Etatjeu.cpp"

class Jeu
{
private:
    //bool estdansinven = false;
    sf::Font font;
    Entitee player;

    // Variables
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<Etat*> etats;

    // Initialisation
    void initWindow();
    void initEtat();

public:

    // Constructeurs
    Jeu();
    virtual ~Jeu();

    //////////////////////////////////
    // Fonctions
    //////////////////////////////////

    // fonction basique
    void finjeu();

    // mise a jour
    void mettreajourdt();
    void mettreajourevenementSFML();
    void mettreajour();

    // render
    void render();

    // coeur
    void lancer();

    /*void DaggerFall2(sf::RenderWindow& window, sf::Clock& clock)
    {
        Deplacement d0;
        Inventaire i0(0.f, 0.f, 1800.f, 1000.f);
        GenerationTerrain g0;

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
            d0.bouger(deltaTime, g0.walls);

            // Rendu du terrain
            g0.renderGrid(window);

            i0.draw(window);

            // Affichage du sprite du personnage
            window.draw(d0.getRectangle());

            // Affichage à l'écran
            window.display();
        }
    }*/
};