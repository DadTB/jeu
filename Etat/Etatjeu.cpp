#include "Etatjeu.hpp"

///////////////////////////////////////////
// Fonctions d'initialisation
///////////////////////////////////////////

void Etatjeu::initKeybinds()
{
    this->keybinds["FERMER"] = this->supportedKeys->at("Escape");
    this->keybinds["BOUGER_GAUCHE"] = this->supportedKeys->at("Q");
    this->keybinds["BOUGER_DROITE"] =  this->supportedKeys->at("D");
    this->keybinds["BOUGER_HAUT"] = this->supportedKeys->at("Z");
    this->keybinds["BOUGER_BAS"] = this->supportedKeys->at("S");
}

void Etatjeu::initTextures()
{
    this->textures["JOUEUR_REPOS"].loadFromFile("Ressources/images/Sprites/Joueur/Joueur_repos.png");
}

void Etatjeu::initJoueur()
{
    this->player = new Joueur(100, 100, &this->textures["JOUEUR_REPOS"]);
}

void Etatjeu::initFonts()
{
    if(!this->font.loadFromFile("Fonts/02587_ARIALMT.ttf"))
    {
        std::cout << "ça marche pas ici Etatjeu" << std::endl;
        throw("ERROR::MenuprincipalEtat::COULD NOT LOAD FONT");
    }
}

void Etatjeu::initBoutons()
{
    this->boutons["MENU_DIPLOMATIE"] = new Bouton(0, 0, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Diplomatie",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

///////////////////////////////////////////
// Constructeurs et destructeurs
///////////////////////////////////////////

Etatjeu::Etatjeu(sf::RenderWindow *window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats) : Etat(window, supportedKeys, etats)
{
    this->initFonts();
    this->initKeybinds();
    this->initTextures();
    this->initJoueur();
    this->initBoutons();
}

Etatjeu::~Etatjeu()
{
    delete this->player;
}

///////////////////////////////////////////
// Fonctions
///////////////////////////////////////////

void Etatjeu::mettreajourinput(const float &dt)
{

    // met à jour les input du joueur
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("BOUGER_HAUT"))))
    {
        this->player->bouger(dt, 0.f, -1.f); // Déplacer vers le haut 
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("BOUGER_BAS"))))
    {
        this->player->bouger(dt, 0.f, 1.f); // Déplacer vers le bas
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("BOUGER_GAUCHE"))))
    {
        this->player->bouger(dt, -1.f, 0.f); // Déplacer vers la gauche
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("BOUGER_DROITE"))))
    {
        this->player->bouger(dt, 1.f, 0.f); // Déplacer vers la droite
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("FERMER"))))
    {
        this->finetat(); // en l'occurence et pour le moment on revient en arrière
    }
}

void Etatjeu::mettreajourBoutons()
{
    /* Cette fonction permet de mettre a jour l'état de tous les boutons et d'activer leur fonctionnalités */
    for (auto &it : this->boutons)
    {
        it.second->update(this->mousePosView);
    }

    // Nouvelle Partie
    if (this->boutons["GAME_STATE"]->isPressed())
    {
        //this->etats->push(new Etatjeu(this->window, this->supportedKeys, this->etats));  // pile etats dans classe jeu de type Etat, pile de classe
        //
    }

    // Permet de quittez le jeu
    if (this->boutons["EXIT_STATE"]->isPressed())
    {
        this->finetat();
    }
}

void Etatjeu::mettreajour(const float &dt)
{
    this->updateMousePositions();
    this->mettreajourinput(dt);

    this->player->mettreajour(dt);
}

void Etatjeu::renderBoutons(sf::RenderTarget* cible)
{
    for (auto &it : this->boutons)
    {
        it.second->render(cible);
    }
}

void Etatjeu::render(sf::RenderTarget *cible)
{
    if (!cible)
        cible = this->window;
        
    this->player->render(this->window);
    this->renderBoutons(cible);
}