//#include "Menutitre.hpp"

#include "jeu.cpp"

using namespace std;

int main()
{
    Jeu j0;
    //Menu m0;

    //m0.afficherMenuPrincipal();

    j0.lancer();

    return 0;
}

/*
sf::View view = window.getView();
view.setCenter(playerPosition);  // Déplace la caméra à la position du joueur
window.setView(view);
*/