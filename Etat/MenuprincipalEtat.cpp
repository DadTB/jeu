#include "MenuprincipalEtat.hpp"

void MenuprincipalEtat::initKeybinds()
{
    this->keybinds["FERMER"] = this->supportedKeys->at("Escape");
    this->keybinds["BOUGER_GAUCHE"] = this->supportedKeys->at("Q");
    this->keybinds["BOUGER_DROITE"] =  this->supportedKeys->at("D");
    this->keybinds["BOUGER_HAUT"] = this->supportedKeys->at("Z");
    this->keybinds["BOUGER_BAS"] = this->supportedKeys->at("S");
}

MenuprincipalEtat::MenuprincipalEtat(sf::RenderWindow *window, std::map<std::string, int>* supportedKeys) : Etat(window, supportedKeys)
{
    this->initKeybinds();

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}

MenuprincipalEtat::~MenuprincipalEtat()
{
}

void MenuprincipalEtat::finetat()
{
    //std::cout << "Fin de Etatjeu" << "\n";
}

void MenuprincipalEtat::mettreajourinput(const float &dt)
{
    this->verifierfinEtat();
}

void MenuprincipalEtat::mettreajour(const float &dt)
{
    this->mettreajourinput(dt);
}

void MenuprincipalEtat::render(sf::RenderTarget *cible)
{
    if (!cible)
        cible = this->window;

    cible->draw(this->background);
}