#pragma once

#include "Etat.cpp"

class Etatjeu : public Etat
{
private:
    Entitee player;

    // Fonctions
    void initKeybinds();

public:
    Etatjeu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats);
    virtual ~Etatjeu();

    // Fonctions

    void finetat();
    void mettreajourinput(const float& dt);
    void mettreajour(const float& dt);
    void render(sf::RenderTarget* cible);
};