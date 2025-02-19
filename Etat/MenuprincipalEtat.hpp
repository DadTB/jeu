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

    std::map<std::string, Bouton*> boutons;

    // Fonctions
    void initFonts();
    void initKeybinds();
    void initBouton();

public:
    MenuprincipalEtat(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats);
    virtual ~MenuprincipalEtat();

    // Fonctions

    void finetat();

    void mettreajourinput(const float& dt);
    void mettreajourBoutons();
    void mettreajour(const float& dt);
    void renderBoutons(sf::RenderTarget* cible);
    void render(sf::RenderTarget* cible);

};