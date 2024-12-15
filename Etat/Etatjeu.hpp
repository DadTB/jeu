#pragma once

#include "Etat.cpp"

class Etatjeu : public Etat
{
private:

public:
    Etatjeu(sf::RenderWindow* window);
    virtual ~Etatjeu();

    // Fonctions

    void finetat();
    void mettreajourinput(const float& dt);
    void mettreajour(const float& dt);
    void render(sf::RenderTarget* cible);
};