#include "Hitbox.hpp"

ComposantHitbox::ComposantHitbox(sf::Sprite& sprite, float offset_x, float offset_y, float largeur, float hauteur) : sprite(sprite), offsetX(offset_x), offsetY(offset_y)
{
    this->hitbox.setPosition(this->sprite.getPosition().x + offset_x, this->sprite.getPosition().y + offset_y);
    this->hitbox.setSize(sf::Vector2f(largeur, hauteur));
    this->hitbox.setFillColor(sf::Color::Transparent);
    this->hitbox.setOutlineThickness(1.f);
    this->hitbox.setOutlineColor(sf::Color::Blue);
}

bool ComposantHitbox::verifcollision(const sf::FloatRect& frect)
{
    return this->hitbox.getGlobalBounds().intersects(frect);
}

void ComposantHitbox::mettreajour()
{
    this->hitbox.setPosition(this->sprite.getPosition().x + this->offsetX, this->sprite.getPosition().y + this->offsetY);
}

void ComposantHitbox::render(sf::RenderTarget& cible)
{
    cible.draw(this->hitbox);
}