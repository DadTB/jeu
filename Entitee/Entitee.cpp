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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->bouger(dt, 0.f, -1.f); // Déplacer vers le haut
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->bouger(dt, 0.f, 1.f); // Déplacer vers le bas
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->bouger(dt, -1.f, 0.f); // Déplacer vers la gauche
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->bouger(dt, 1.f, 0.f); // Déplacer vers la droite
    }
}

void Entitee::render(sf::RenderTarget* cible)
{
    cible->draw(this->forme);
}