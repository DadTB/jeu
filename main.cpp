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



// classe Etatjeu est classe fille de classe Etat


/*
sf::View view = window.getView();
view.setCenter(playerPosition);  // Déplace la caméra à la position du joueur
window.setView(view);
*/

// g++ -c main.cpp -I"C:\Users\thoma\Documents\librairies\SFML-2.6.2\include"

// g++ main.o -o sfml-app -L"C:\Users\thoma\Documents\librairies\SFML-2.6.2\include" -lsfml-graphics -lsfml-window -lsfml-system

// ./sfml-app