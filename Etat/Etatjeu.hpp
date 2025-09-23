#pragma once

#include "Etat.cpp"

class Etatjeu : public Etat
{
private:
    Joueur* player;
    sf::Font font;

    std::map<std::string, Bouton*> boutons;

    // Fonctions
    void initKeybinds();
    void initTextures();
    void initJoueur();
    void initBoutons();
    void initFonts();

public:
    Etatjeu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats);
    virtual ~Etatjeu();

    // Fonctions

    void mettreajourinput(const float& dt);
    void mettreajourBoutons();
    void mettreajour(const float& dt);
    void renderBoutons(sf::RenderTarget* cible);
    void render(sf::RenderTarget* cible);
};