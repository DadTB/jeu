#include "Etat.hpp"

Etat::Etat(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats)
{
    this->window = window;
    this->supportedKeys = supportedKeys;
    this->etats = etats;
    this->veutfin = false;
}

Etat::~Etat()
{

}

const bool& Etat::avoirfin() const
{
    return this->veutfin;
}

void Etat::finetat()
{
    this->veutfin = true;
}

void Etat::updateMousePositions()
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}