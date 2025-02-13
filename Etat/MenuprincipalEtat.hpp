#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "Etatjeu.cpp"

class MenuprincipalEtat : public Etat
{
private:
    // Variables
    sf::RectangleShape background;

    // Fonctions
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

#endif