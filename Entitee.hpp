#pragma once

#include "SFML/Graphics.hpp"
#include <cmath>

class Entitee
{
protected:
    sf::RectangleShape forme;
    float vitessedeplacement;

public:
    Entitee();
    virtual ~Entitee();

    // Fonctions
    virtual void bouger(const float& dt, const float dir_x, const float dir_y);

    virtual void mettreajour(const float& dt);
    virtual void render(sf::RenderTarget& target);
};