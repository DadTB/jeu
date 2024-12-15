#include "Etat.hpp"

Etat::Etat(sf::RenderWindow* window)
{
    this->window = window;
    this->veutfin = false;
}

Etat::~Etat()
{

}

const bool& Etat::avoirfin() const
{
    return this->veutfin;
}

void Etat::verifierfinEtat()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->veutfin = true;
    }
}