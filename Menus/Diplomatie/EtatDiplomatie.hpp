#pragma once

#include "../../Etat/Etat.cpp"

class EtatDiplomatie : public Etat
{
private:
    sf::Font font;

    std::map<std::string, Bouton*> boutons;

    // Fonctions
    void initKeybinds();
    void initTextures();
    void initBoutons();
    void initFonts();

public:
    EtatDiplomatie(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<Etat*>* etats);
    virtual ~EtatDiplomatie();

    // Fonctions

    void mettreajourinput(const float& dt);
    void mettreajourBoutons();
    void mettreajour(const float& dt);
    void renderBoutons(sf::RenderTarget* cible);
    void render(sf::RenderTarget* cible);
};