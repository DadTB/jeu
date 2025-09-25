#include "MenuprincipalEtat.hpp"


/////////////////////////////////////////////
// Fonctions d'initialisation
/////////////////////////////////////////////

void MenuprincipalEtat::initVariables()
{

}

void MenuprincipalEtat::initBackground()
{
    this->background.setSize(
        sf::Vector2f
        (static_cast<float>(this->window->getSize().x),
        static_cast<float>(this->window->getSize().y)));

    if(!this->backgroundTexture.loadFromFile("Ressources/images/Backgrounds/fond1carte1444.png"))
    {
        throw"ERREUR::MENUPRINCIPALETAT::BACKGROUND_PAS_CHARGE";
    }
    this->background.setTexture(&this->backgroundTexture);
}

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

void MenuprincipalEtat::initBouton() // fonction qui permet d'ajouter des boutons sur l'écran du menu
{
    this->boutons["GAME_STATE"] = new Bouton(100, 100, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Nouvelle partie",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

    this->boutons["GAME_STATE_CONTINUE"] = new Bouton(300, 100, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Continuer",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

    this->boutons["PARAMETRE"] = new Bouton(100, 200, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Parametres",
        sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

    this->boutons["EXIT_STATE"] = new Bouton(100, 300, 0, 0, 150, 0, 150, 50, 0, 50,
        &this->font, "Quittez le jeu",
        sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}


/////////////////////////////////////////////
// Constructeurs et destructeurs
/////////////////////////////////////////////


MenuprincipalEtat::MenuprincipalEtat(sf::RenderWindow *window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats) : Etat(window, supportedKeys, etats)
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initBouton();
}

MenuprincipalEtat::~MenuprincipalEtat()
{
    auto it = this->boutons.begin();
    for (it = this->boutons.begin(); it != this->boutons.end(); ++it)
    {
        delete it->second;
    }
}

void MenuprincipalEtat::mettreajourinput(const float &dt)
{
    
}

void MenuprincipalEtat::mettreajourBoutons()
{
    /* Cette fonction permet de mettre a jour l'état de tous les boutons et d'activer leur fonctionnalités */
    for (auto &it : this->boutons)
    {
        it.second->update(this->mousePosView);
    }

    // Nouvelle Partie
    if (this->boutons["GAME_STATE"]->isPressed())
    {
        this->etats->push(new ChoixPays(this->window, this->supportedKeys, this->etats));
    }

    if (this->boutons["GAME_STATE_CONTINUE"]->isPressed())
    {
        this->etats->push(new Etatjeu(this->window, this->supportedKeys, this->etats));  // pile etats dans classe jeu de type Etat, pile de classe
    }

    // Permet de quittez le jeu
    if (this->boutons["EXIT_STATE"]->isPressed())
    {
        this->finetat();
    }
}

void MenuprincipalEtat::mettreajour(const float &dt)
{
    this->updateMousePositions();
    this->mettreajourinput(dt);

    this->mettreajourBoutons();
}

void MenuprincipalEtat::renderBoutons(sf::RenderTarget* cible)
{
    for (auto &it : this->boutons)
    {
        it.second->render(cible);
    }
}

void MenuprincipalEtat::render(sf::RenderTarget *cible)
{
    if (!cible)
        cible = this->window;

    cible->draw(this->background);

    this->renderBoutons(cible);

    // Debug : à retirer, permet d'afficher du texte sous la souris
    /*
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(12);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << mousePosView.y;
    mouseText.setString(ss.str());

    cible->draw(mouseText);*/
}