#pragma once

#include "Etat.cpp"

class Etatjeu : public Etat
{
private:
    Joueur* player;

    // Fonctions
    void initKeybinds();
    void initTextures();
    void initJoueur();

public:
    Etatjeu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats);
    virtual ~Etatjeu();

    // Fonctions

    void mettreajourinput(const float& dt);
    void mettreajour(const float& dt);
    void render(sf::RenderTarget* cible);
};