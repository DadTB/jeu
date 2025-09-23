#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>
//#include "../Entitee/Entitee.cpp"
#include "../Entitee/Joueur.cpp"
#include "../Bouton.cpp"

class Etat //classe abstraite, toutes les classes de menu doivent hériter de cette classe
{
protected:
std::stack<Etat*>* etats; // etats est un pointeur vers la pile, la pile est une pile de pointeur vers des états
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool veutfin;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Resources
    std::map<std::string, sf::Texture> textures;

    // Fonctions
    virtual void initKeybinds() = 0;

public:
    Etat(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats);
    virtual ~Etat();

    const bool& avoirfin() const;
    void finetat();

    virtual void updateMousePositions();
    virtual void mettreajourinput(const float& dt) = 0;
    virtual void mettreajour(const float& dt) = 0;
    virtual void render(sf::RenderTarget* cible = NULL) = 0;
};