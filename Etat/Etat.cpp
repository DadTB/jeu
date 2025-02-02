#include "Etat.hpp"

Etat::Etat(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
{
    this->window = window;
    this->supportedKeys = supportedKeys;
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("FERMER"))))
    {
        this->veutfin = true;
    }
}