#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum button_stats{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Bouton
{
private:
    short unsigned buttonState;

    //sf::RectangleShape shape;
    sf::ConvexShape convex;
    sf::Font* font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Bouton(float x, float y, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, sf::Font* font,
        std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Bouton();

    // Accesseurs
    const bool isPressed() const;

    // Fonctions
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget * target);
};