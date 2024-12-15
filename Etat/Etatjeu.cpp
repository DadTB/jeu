#include "Etatjeu.hpp"

Etatjeu::Etatjeu(sf::RenderWindow* window) : Etat(window)
{

}

Etatjeu::~Etatjeu()
{

}

void Etatjeu::finetat()
{

}

void Etatjeu::mettreajourinput(const float& dt)
{
    this->verifierfinEtat();
}

void Etatjeu::mettreajour(const float& dt)
{
    this->mettreajourinput(dt);

    this->player.mettreajour(dt);
}

void Etatjeu::render(sf::RenderTarget* cible)
{
    this->player.render(this->window);
}