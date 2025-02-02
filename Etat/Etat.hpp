#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>
#include "../Entitee/Entitee.cpp"

class Etat
{
protected:
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool veutfin;

    // Resources
    std::vector<sf::Texture> textures;

    // Fonctions
    virtual void initKeybinds() = 0;

public:
    Etat(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~Etat();

    const bool& avoirfin() const;

    virtual void verifierfinEtat();

    virtual void finetat() = 0;
    virtual void mettreajourinput(const float& dt) = 0;
    virtual void mettreajour(const float& dt) = 0;
    virtual void render(sf::RenderTarget* cible = NULL) = 0;
};