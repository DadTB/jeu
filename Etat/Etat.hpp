#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>

class Etat
{
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool veutfin;

public:
    Etat(sf::RenderWindow* window);
    virtual ~Etat();

    const bool& avoirfin() const;

    virtual void verifierfinEtat();

    virtual void finetat() = 0;
    virtual void mettreajourinput(const float& dt) = 0;
    virtual void mettreajour(const float& dt) = 0;
    virtual void render(sf::RenderTarget* cible = NULL) = 0;
};