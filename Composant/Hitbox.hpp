#pragma once

#include "SFML/Graphics.hpp"

class ComposantHitbox
{
private:
    sf::Sprite& sprite;
    sf::RectangleShape hitbox;
    float offsetX;
    float offsetY;

public:
    ComposantHitbox(sf::Sprite& sprite, float offset_x, float offset_y, float largeur, float hauteur);
    virtual ~ComposantHitbox();

    // Fonctions
    bool verifcollision(const sf::FloatRect& frect);

    void mettreajour();
    void render(sf::RenderTarget& cible);
};