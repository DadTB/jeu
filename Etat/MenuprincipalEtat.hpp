#pragma once

#include "Etatjeu.cpp"
#include "../Bouton.cpp"
#include <iostream>

class MenuprincipalEtat : public Etat
{
private:
    // Variables
    sf::RectangleShape background;
    sf::Font font;

    Bouton* gamestate_btn;

    // Fonctions
    void initFonts();
    void initKeybinds();

public:
    MenuprincipalEtat(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~MenuprincipalEtat();

    // Fonctions

    void finetat();
    void mettreajourinput(const float& dt);
    void mettreajour(const float& dt);
    void render(sf::RenderTarget* cible);

};