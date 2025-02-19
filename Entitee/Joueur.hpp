#pragma once

#include "Entitee.cpp"

class Joueur : public Entitee
{
private:
    // Variables

    // Fonctions d'initialisations
    void initVariables();
    void initComposants();

public:
    Joueur(float x, float y, sf::Texture* texture);
    virtual ~Joueur();

    // Fonctions
};