#include "Entitee.hpp"



void Entitee::initVariables()
{
    this->texture = NULL;
    this->sprite = NULL;
    this->vitessedeplacement = 100.f;
}

///////////////////////////////
// Constructeurs et destructeurs
///////////////////////////////

Entitee::Entitee()
{
    this->initVariables();
}

Entitee::~Entitee()
{
    delete this->sprite;
}

///////////////////////////////
// Fonctions de composant
///////////////////////////////

void Entitee::creerSprite(sf::Texture* texture)
{
    this->texture = texture;
    this->sprite = new sf::Sprite(*this->texture);
}

///////////////////////////////
// Fonctions
///////////////////////////////

void Entitee::defPosition(float x, float y, sf::RenderWindow *window)
{
    if (this->sprite)
    {
        // On récupère les dimensions de la texture du sprite
        sf::FloatRect bounds = this->sprite->getLocalBounds();

        // On place l'origine au centre du sprite
        this->sprite->setOrigin(bounds.width / 2.f, bounds.height / 2.f);

        // On récupère la taille de la fenêtre
        sf::Vector2u winSize = window->getSize();

        // On place le sprite au centre de la fenêtre
        this->sprite->setPosition(winSize.x / 2.f, winSize.y / 2.f);
    }
}

void Entitee::bouger(const float &dt, const float dir_x, const float dir_y)
{
    if (this->sprite)
    {
        this->sprite->move(dir_x * this->vitessedeplacement * dt, dir_y * this->vitessedeplacement * dt);
    }
}

void Entitee::mettreajour(const float &dt)
{

}

void Entitee::render(sf::RenderTarget* cible)
{
    if (this->sprite)
    {
        cible->draw(*this->sprite);
    }
}