#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include <cmath>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

class Entitee
{
private:
    void initVariables();

protected:
    sf::Texture* texture;
    sf::Sprite* sprite;

    float vitessedeplacement;

public:
    Entitee();
    virtual ~Entitee(); //on le met en virtuel pour que si jamais on supprime Entitee, les destructeurs des classes qui auront un objet hérité d'un objet Entitee seront aussi appelés

    // Fonctions de composant
    void creerSprite(sf::Texture* texture);

    // Fonctions

    virtual void defPosition(const float x, const float y, sf::RenderWindow *window);
    virtual void bouger(const float& dt, const float dir_x, const float dir_y);

    virtual void mettreajour(const float& dt);
    virtual void render(sf::RenderTarget* target);
};