#pragma once

#include "Etatjeu.cpp"
#include "../Bouton.cpp"
#include <iostream>

class ChoixPays : public Etat
{
private:
    // Variables
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;
    int niveau;
    std::string choixPays;
    std::string pays;

    std::map<std::string, Bouton*> boutonsniveau1;
    std::map<std::string, Bouton*> boutonsniveau2;

    // Fonctions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initBouton();
    void initBoutonPays(std::string pays);

public:
    ChoixPays(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats);
    virtual ~ChoixPays();

    // Fonctions

    void mettreajourinput(const float& dt);
    void mettreajourBoutons();
    void choixArbreMission();
    void mettreajour(const float& dt);
    void renderBoutons(sf::RenderTarget* cible);
    void render(sf::RenderTarget* cible);

};