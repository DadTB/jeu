#pragma once

#include <string>
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Monde/generationterrain.cpp"
#include "Composant/deplacement.cpp"
#include "Inventaire/inventaire.cpp"
//#include "Entitee.cpp"
#include "Etat/MenuprincipalEtat.cpp"

class Jeu
{
private:
    //bool estdansinven = false;
    sf::Font font;
    Entitee player;

    // Variables
    sf::RenderWindow *window;
    sf::Event sfEvent;
    std::vector<sf::VideoMode> videoModes;
    sf::ContextSettings windowSettings;
    bool fullscreen;

    sf::Clock dtClock;
    float dt;

    std::stack<Etat*> etats;

    std::map<std::string, int> supportedKeys;

    // Initialisation
    void initVariables();
    void initWindow();
    void initKeys();
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
};