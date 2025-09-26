#include "EtatDiplomatie.hpp"

///////////////////////////////////////////
// Fonctions d'initialisation
///////////////////////////////////////////

void EtatDiplomatie::initKeybinds()
{
    this->keybinds["FERMER"] = this->supportedKeys->at("Escape");
    this->keybinds["BOUGER_GAUCHE"] = this->supportedKeys->at("Q");
    this->keybinds["BOUGER_DROITE"] =  this->supportedKeys->at("D");
    this->keybinds["BOUGER_HAUT"] = this->supportedKeys->at("Z");
    this->keybinds["BOUGER_BAS"] = this->supportedKeys->at("S");
}

void EtatDiplomatie::initTextures()
{
    
}

void EtatDiplomatie::initBackground()
{
    this->background.setSize(
        sf::Vector2f
        (static_cast<float>(this->window->getSize().x),
        static_cast<float>(this->window->getSize().y)));

    if(!this->backgroundTexture.loadFromFile("Ressources/images/backgrounds/fond_ecran_menu_diplomatie.png"))
    {
        throw"ERREUR::MENUPRINCIPALETAT::BACKGROUND_PAS_CHARGE";
    }
    this->background.setTexture(&this->backgroundTexture);
}

void EtatDiplomatie::initFonts()
{
    if(!this->font.loadFromFile("Fonts/02587_ARIALMT.ttf"))
    {
        std::cout << "ça marche pas ici EtatDiplomatie" << std::endl;
        throw("ERROR::EtatDiplomatie::COULD NOT LOAD FONT");
    }
}

void EtatDiplomatie::initBoutons()
{
    this->boutons["MENU_DIPLOMATIE"] = new Bouton(0, 0, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Diplomatie",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->boutons["MENU_ECONOMIQUE"] = new Bouton(150, 0, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Economie",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->boutons["MENU_MILITAIRE"] = new Bouton(300, 0, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Militaire",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->boutons["MENU_MISSION"] = new Bouton(450, 0, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Mission",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->boutons["MENU_GESTION"] = new Bouton(600, 0, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Gestion",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->boutons["MENU_REFORME"] = new Bouton(600, 0, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Reforme",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->boutons["MENU_DYNASTIE"] = new Bouton(750, 0, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Dynastie",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->boutons["MENU_RELIGIEUX"] = new Bouton(900, 0, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Religion",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->boutons["MENU_CARTE"] = new Bouton(1050, 0, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Carte",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->boutons["QUITTER_CARTE"] = new Bouton(1200, 0, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Retour",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

///////////////////////////////////////////
// Constructeurs et destructeurs
///////////////////////////////////////////

EtatDiplomatie::EtatDiplomatie(sf::RenderWindow *window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats) : Etat(window, supportedKeys, etats)
{
    this->initFonts();
    this->initKeybinds();
    this->initTextures();
    this->initBoutons();
    this->initBackground();
}

EtatDiplomatie::~EtatDiplomatie()
{

}

///////////////////////////////////////////
// Fonctions
///////////////////////////////////////////

void EtatDiplomatie::mettreajourinput(const float &dt)
{

}

void EtatDiplomatie::mettreajourBoutons()
{
    /* Cette fonction permet de mettre a jour l'état de tous les boutons et d'activer leur fonctionnalités */
    for (auto &it : this->boutons)
    {
        it.second->update(this->mousePosView);
    }

    if (this->boutons["QUITTER_CARTE"]->isPressed())
    {
        // On retire l'état de la pile
        Etat* etatASupprimer = this->etats->top();
        this->etats->pop();
        delete etatASupprimer;
    }
}

void EtatDiplomatie::mettreajour(const float &dt)
{
    this->updateMousePositions();
    this->mettreajourinput(dt);
    this->mettreajourBoutons();
}

void EtatDiplomatie::renderBoutons(sf::RenderTarget* cible)
{
    for (auto &it : this->boutons)
    {
        it.second->render(cible);
    }
}

void EtatDiplomatie::render(sf::RenderTarget *cible)
{
    if (!cible)
        cible = this->window;

    cible->draw(this->background);
        
    this->renderBoutons(cible);
}