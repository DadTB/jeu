#include "Joueur.hpp"

///////////////////////////////
// Fonctions d'initialisations
///////////////////////////////

void Joueur::initVariables()
{

}

void Joueur::initComposants()
{
    
}

///////////////////////////////
// Constructeurs et destructeurs
///////////////////////////////

Joueur::Joueur(float x, float y, sf::Texture* texture)
{
    this->initVariables();
    this->initComposants();

    this->creerSprite(texture);
    this->defPosition(x, y);
}

Joueur::~Joueur()
{

}