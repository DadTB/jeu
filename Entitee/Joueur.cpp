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

Joueur::Joueur(float x, float y, sf::Texture* texture, sf::RenderWindow *window)
{
    this->initVariables();
    this->initComposants();
    std::cout << "perso créé" << std::endl;

    this->creerSprite(texture); // appelle la fonction creerSprite de Entitee
    this->defPosition(x, y, window);
}

Joueur::~Joueur()
{

}