#include "ChoixPays.hpp"


/////////////////////////////////////////////
// Fonctions d'initialisation
/////////////////////////////////////////////

void ChoixPays::initVariables()
{
    this->niveau = 1;
}

void ChoixPays::initBackground()
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

void ChoixPays::initFonts()
{
    if(!this->font.loadFromFile("Fonts/02587_ARIALMT.ttf"))
    {
        std::cout << "ça marche pas ici" << std::endl;
        throw("ERROR::MenuprincipalEtat::COULD NOT LOAD FONT");
    }
}

void ChoixPays::initKeybinds()
{
    this->keybinds["FERMER"] = this->supportedKeys->at("Escape");
    this->keybinds["BOUGER_GAUCHE"] = this->supportedKeys->at("Q");
    this->keybinds["BOUGER_DROITE"] =  this->supportedKeys->at("D");
    this->keybinds["BOUGER_HAUT"] = this->supportedKeys->at("Z");
    this->keybinds["BOUGER_BAS"] = this->supportedKeys->at("S");
}

void ChoixPays::initBouton() // fonction qui permet d'ajouter des boutons sur l'écran du menu
{
    this->boutonsniveau1["FRANCE"] = new Bouton(300, 100, 150, 50,
        &this->font, "France",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->boutonsniveau2["FRANCE"] = new Bouton(300, 100, 150, 50,
        &this->font, "France",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

/////////////////////////////////////////////
// Constructeurs et destructeurs
/////////////////////////////////////////////

ChoixPays::ChoixPays(sf::RenderWindow *window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats) : Etat(window, supportedKeys, etats)
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initBouton();
}

ChoixPays::~ChoixPays()
{
    auto it = this->boutonsniveau1.begin();
    for (it = this->boutonsniveau1.begin(); it != this->boutonsniveau1.end(); ++it)
    {
        delete it->second;
    }
    auto it = this->boutonsniveau2.begin();
    for (it = this->boutonsniveau2.begin(); it != this->boutonsniveau2.end(); ++it)
    {
        delete it->second;
    }
}

void ChoixPays::mettreajourinput(const float &dt)
{
    
}

void ChoixPays::mettreajourBoutons()
{
    /* Cette fonction permet de mettre a jour l'état de tous les boutons et d'activer leur fonctionnalités */
    for (auto &it : this->boutonsniveau1)
    {
        it.second->update(this->mousePosView);
    }

    if (this->boutonsniveau1["FRANCE"]->isPressed())
    {
        this->niveau = 2;
        this->etats->push(new Etatjeu(this->window, this->supportedKeys, this->etats));
    }
}

void ChoixPays::choixArbreMission()
{
    for (auto &it : this->boutonsniveau1)
    {
        it.second->update(this->mousePosView);
    }
}

void ChoixPays::mettreajour(const float &dt)
{
    this->updateMousePositions();
    this->mettreajourinput(dt);

    this->mettreajourBoutons();
}

void ChoixPays::renderBoutons(sf::RenderTarget* cible)
{
    if (this->niveau == 1)
    {
        for (auto &it : this->boutonsniveau1)
        {
            it.second->render(cible);
        }
    }
    else if (this->niveau == 2)
    {
        for (auto &it : this->boutonsniveau2)
        {
            it.second->render(cible);
        }
    }
    
}

void ChoixPays::render(sf::RenderTarget *cible)
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