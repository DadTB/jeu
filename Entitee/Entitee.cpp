#include "Entitee.hpp"

Entitee::Entitee()
{
    this->forme.setSize(sf::Vector2f(50.f, 50.f));
    this->forme.setFillColor(sf::Color::Green);
    this->vitessedeplacement = 100.f;
}

Entitee::~Entitee()
{
}

void Entitee::bouger(const float &dt, const float dir_x, const float dir_y)
{
    this->forme.move(dir_x * this->vitessedeplacement * dt, dir_y * this->vitessedeplacement * dt);
}

void Entitee::mettreajour(const float &dt)
{

}

void Entitee::render(sf::RenderTarget* cible)
{
    cible->draw(this->forme);
}