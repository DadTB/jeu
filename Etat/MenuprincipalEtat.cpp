#include "MenuprincipalEtat.hpp"


void MenuprincipalEtat::initFonts()
{
    if(!this->font.loadFromFile("Fonts/02587_ARIALMT.ttf"))
    {
        std::cout << "ça marche pas ici" << std::endl;
        throw("ERROR::MenuprincipalEtat::COULD NOT LOAD FONT");
    }
}

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
    this->initFonts();
    this->initKeybinds();

    this->gamestate_btn = new Bouton(100, 100, 150, 50,
        &this->font, "Nouvelle partie",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}

MenuprincipalEtat::~MenuprincipalEtat()
{
    delete this->gamestate_btn;
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
    this->updateMousePositions();
    this->mettreajourinput(dt);
}

void MenuprincipalEtat::render(sf::RenderTarget *cible)
{
    if (!cible)
        cible = this->window;

    cible->draw(this->background);
}