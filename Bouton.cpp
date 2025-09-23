#include "Bouton.hpp"

/*Bouton::Bouton(float x, float y, float width, float height, sf::Font* font,
    std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->buttonState = BTN_IDLE;

    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(12);
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
    );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);
}*/

Bouton::Bouton(float x, float y, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, sf::Font* font,
    std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->buttonState = BTN_IDLE;

    this->convex.setPointCount(4);

    this->convex.setPosition(sf::Vector2f(x, y));
    this->convex.setPoint(0, sf::Vector2f(x1, y1));
    this->convex.setPoint(1, sf::Vector2f(x2, y2));
    this->convex.setPoint(2, sf::Vector2f(x3, y3));
    this->convex.setPoint(3, sf::Vector2f(x4, y4));
    //this->convex.setSize(sf::Vector2f(width, height));

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(12);
    this->text.setPosition(
        this->convex.getPosition().x + (this->convex.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
        this->convex.getPosition().y + (this->convex.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
    );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->convex.setFillColor(this->idleColor);
}

Bouton::~Bouton()
{
    
}

// Accesseurs

const bool Bouton::isPressed() const
{
    if (this->buttonState == BTN_ACTIVE)
    {
        return true;
    }
    return false;
}

// Fonctions

void Bouton::update(const sf::Vector2f mousePos)
{
    /*Mets à jour les booléens pour hover et pressed*/

    // Idle
    this->buttonState = BTN_IDLE;

    // Hover

    if (this->convex.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = BTN_HOVER;

        // Pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = BTN_ACTIVE;
        }
    }

    switch (this->buttonState)
    {
        case BTN_IDLE:
            this->convex.setFillColor(this->idleColor);
            break;

        case BTN_HOVER:
            this->convex.setFillColor(this->hoverColor);
            break;

        case BTN_ACTIVE:
            this->convex.setFillColor(this->activeColor);
            break;

        default:
        this->convex.setFillColor(sf::Color::Red);
            break;
    }
}

void Bouton::render(sf::RenderTarget * target)
{
    target->draw(this->convex);
    target->draw(this->text);
}