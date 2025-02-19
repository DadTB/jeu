#include "Etatjeu.hpp"

void Etatjeu::initKeybinds()
{
    this->keybinds["FERMER"] = this->supportedKeys->at("Escape");
    this->keybinds["BOUGER_GAUCHE"] = this->supportedKeys->at("Q");
    this->keybinds["BOUGER_DROITE"] =  this->supportedKeys->at("D");
    this->keybinds["BOUGER_HAUT"] = this->supportedKeys->at("Z");
    this->keybinds["BOUGER_BAS"] = this->supportedKeys->at("S");
}

Etatjeu::Etatjeu(sf::RenderWindow *window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats) : Etat(window, supportedKeys, etats)
{
    this->initKeybinds();
}

Etatjeu::~Etatjeu()
{
    
}

void Etatjeu::mettreajourinput(const float &dt)
{

    // met à jour les input du joueur
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("BOUGER_HAUT"))))
    {
        this->player.bouger(dt, 0.f, -1.f); // Déplacer vers le haut
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("BOUGER_BAS"))))
    {
        this->player.bouger(dt, 0.f, 1.f); // Déplacer vers le bas
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("BOUGER_GAUCHE"))))
    {
        this->player.bouger(dt, -1.f, 0.f); // Déplacer vers la gauche
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("BOUGER_DROITE"))))
    {
        this->player.bouger(dt, 1.f, 0.f); // Déplacer vers la droite
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("FERMER"))))
    {
        this->finetat();
    }
}

void Etatjeu::mettreajour(const float &dt)
{
    this->updateMousePositions();
    this->mettreajourinput(dt);

    this->player.mettreajour(dt);
}

void Etatjeu::render(sf::RenderTarget *cible)
{
    if (!cible)
        cible = this->window;
        
    this->player.render(this->window);
}