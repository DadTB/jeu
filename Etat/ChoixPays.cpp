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

void ChoixPays::initBouton() // fonction qui permet d'ajouter des boutons sur l'écran du menu, il faut rajouter la possibilité de juste lire les fichiers pour créer les boutons
{
    this->boutonsniveau1["FRANCE"] = new Bouton(300, 100, 0, 0, 150, 0, 150, 50, 50, 0,
        &this->font, "France",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    
    
}

void ChoixPays::initBoutonPays(std::string pays) // permet de créer les boutons en fonction des fichiers
{
    std::string filename = "common/missions/France/nom_arbre.txt"; // Nom du fichier à lire
    std::ifstream file(filename); // Ouvre le fichier en lecture
        
    if (!file)
    {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
    }

    std::string line;
    int place = 1;
    while (std::getline(file, line))
    { // Lit ligne par ligne
        //std::cout << "Ligne lue : " << line << std::endl; // Affiche la ligne
        this->boutonsniveau2[line] = new Bouton(100 * place, 300, 0, 0, 150, 0,  150, 50, 0, 50,
            &this->font, line,
            sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
            place += 2;
    }

    file.close(); // Ferme le fichier
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
    auto it1 = this->boutonsniveau1.begin();
    for (it1 = this->boutonsniveau1.begin(); it1 != this->boutonsniveau1.end(); ++it1)
    {
        delete it1->second;
    }
    auto it2 = this->boutonsniveau2.begin();
    for (it2 = this->boutonsniveau2.begin(); it2 != this->boutonsniveau2.end(); ++it2)
    {
        delete it2->second;
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
        this->choixPays = "France";
        this->initBoutonPays("France");
    }
}

void ChoixPays::choixArbreMission()
{
    for (auto &it : this->boutonsniveau2)
    {
        it.second->update(this->mousePosView);
    }
    for (auto &pair : this->boutonsniveau2)
    {
        std::string nomarbre = pair.first;
        if (this->boutonsniveau2[nomarbre]->isPressed())
        {
            // ajout code pour valider que l'arbre est sélectionné
            this->etats->push(new Etatjeu(this->window, this->supportedKeys, this->etats));
        }
    }
}

void ChoixPays::mettreajour(const float &dt)
{
    this->updateMousePositions();
    this->mettreajourinput(dt);

    if (this->niveau == 1)
    {
        this->mettreajourBoutons();
    }
    else if (this->niveau == 2)
    {
        this->choixArbreMission();
    }
    
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
}