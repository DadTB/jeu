#pragma once


class Personnage
{
private:

    int Force;
    int Intelligence;
    int Agilite;
    int Endurance;
    int Persuasion;
    int Vitesse;
    int Charisme;
    int Mana;
    int Vie;
    int Encombrement;
    int Argent;

public:

    // Constructeur par défaut ma gueule
    Personnage() {}

    // Constructeur paramétré pour que dans jeu.hpp quand on crée le perso on puisse changer ses comp, sa race et son signe astro
    Personnage(int Force, int Intelligence, int Agilite, int Endurance, int Persuasion, int Vitesse, int Charisme, int Mana, int Vie, int Encombrement): Force(Force), Intelligence(Intelligence), Agilite(Agilite), Endurance(Endurance), Persuasion(Persuasion), Vitesse(Vitesse), Charisme(Charisme), Mana(Mana), Vie(Vie), Encombrement(Encombrement) {}


};