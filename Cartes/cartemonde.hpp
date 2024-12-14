#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>             // Pour les algorithmes procéduraux
//#include <nlohmann/json.hpp> // Bibliothèque JSON, à installer séparément

class CarteProcedurale
{
public:
    // Enum pour les types de terrain
    enum class TypeTerrain
    {
        PLAINE,
        MONTAGNE,
        FORET,
        EAU
    };

    // Structure représentant une tuile
    struct Tuile
    {
        TypeTerrain terrain;
        bool aVille = false;
        bool aDonjon = false;
        std::string nomLieu;
    };

    // Structure représentant un lieu prédéfini
    struct Lieu
    {
        std::string nom;
        int x;
        int y;
        enum class TypeLieu
        {
            VILLE,
            VILLAGE,
            DONJON
        } type;
    };

private:
    std::vector<std::vector<Tuile>> carte; // Grille de la carte
    std::vector<Lieu> lieuxPredetermines;  // Liste des lieux prédéfinis
    int largeur;
    int hauteur;

public:
    // Constructeur
    CarteProcedurale(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur)
    {
        carte.resize(hauteur, std::vector<Tuile>(largeur));
    }

    // Générer la carte procédurale
    void genererCarte()
    {
        for (int y = 0; y < hauteur; ++y)
        {
            for (int x = 0; x < largeur; ++x)
            {
                // Exemple simple : bruit basé sur les coordonnées (tu peux utiliser du bruit de Perlin ici)
                float altitude = bruitSimple(x, y);
                carte[y][x].terrain = terrainFromAltitude(altitude);
            }
        }

        // Placer les lieux prédéterminés
        placerLieuxPredetermines();
    }

    // Ajouter des lieux prédéfinis
    void ajouterLieu(const std::string &nom, int x, int y, Lieu::TypeLieu type)
    {
        lieuxPredetermines.push_back({nom, x, y, type});
    }

    // Afficher la carte (pour le débogage)
    void afficherCarte() const
    {
        for (int y = 0; y < hauteur; ++y)
        {
            for (int x = 0; x < largeur; ++x)
            {
                if (carte[y][x].aVille)
                    std::cout << "V"; // Ville
                else if (carte[y][x].aDonjon)
                    std::cout << "D"; // Donjon
                else
                    std::cout << terrainToChar(carte[y][x].terrain);
            }
            std::cout << std::endl;
        }
    }

    // Vérifier si un joueur est sur un lieu
    void verifierLieu(int x, int y)
    {
        if (carte[y][x].aVille)
        {
            std::cout << "Vous êtes dans la ville de " << carte[y][x].nomLieu << " !" << std::endl;
        }
        else if (carte[y][x].aDonjon)
        {
            std::cout << "Vous êtes devant le donjon " << carte[y][x].nomLieu << " !" << std::endl;
        }
        else
        {
            std::cout << "Rien de spécial ici." << std::endl;
        }
    }

    // Sauvegarder la carte dans un fichier JSON
    /*void sauvegarderCarte(const std::string &cheminFichier)
    {
        nlohmann::json jCarte;
        for (int y = 0; y < hauteur; ++y)
        {
            for (int x = 0; x < largeur; ++x)
            {
                jCarte["carte"][y][x]["terrain"] = static_cast<int>(carte[y][x].terrain);
                jCarte["carte"][y][x]["aVille"] = carte[y][x].aVille;
                jCarte["carte"][y][x]["aDonjon"] = carte[y][x].aDonjon;
                jCarte["carte"][y][x]["nomLieu"] = carte[y][x].nomLieu;
            }
        }
        std::ofstream fichier(cheminFichier);
        fichier << jCarte.dump(4); // Sauvegarde avec une indentation de 4
    }

    // Charger la carte depuis un fichier JSON
    void chargerCarte(const std::string &cheminFichier)
    {
        std::ifstream fichier(cheminFichier);
        nlohmann::json jCarte;
        fichier >> jCarte;

        for (int y = 0; y < hauteur; ++y)
        {
            for (int x = 0; x < largeur; ++x)
            {
                carte[y][x].terrain = static_cast<TypeTerrain>(jCarte["carte"][y][x]["terrain"]);
                carte[y][x].aVille = jCarte["carte"][y][x]["aVille"];
                carte[y][x].aDonjon = jCarte["carte"][y][x]["aDonjon"];
                carte[y][x].nomLieu = jCarte["carte"][y][x]["nomLieu"];
            }
        }
    }*/

private:
    // Mapper une altitude à un type de terrain
    TypeTerrain terrainFromAltitude(float altitude)
    {
        if (altitude < 0.3)
            return TypeTerrain::EAU;
        else if (altitude < 0.5)
            return TypeTerrain::PLAINE;
        else if (altitude < 0.8)
            return TypeTerrain::FORET;
        else
            return TypeTerrain::MONTAGNE;
    }

    // Convertir un type de terrain en caractère (pour le débogage)
    char terrainToChar(TypeTerrain terrain) const
    {
        switch (terrain)
        {
        case TypeTerrain::PLAINE:
            return '.';
        case TypeTerrain::MONTAGNE:
            return '^';
        case TypeTerrain::FORET:
            return '#';
        case TypeTerrain::EAU:
            return '~';
        default:
            return '?';
        }
    }

    // Exemple simple de bruit pour la génération procédurale
    float bruitSimple(int x, int y)
    {
        return std::sin(x * 0.1f) * std::cos(y * 0.1f) * 0.5f + 0.5f;
    }

    // Placer les lieux prédéfinis sur la carte
    void placerLieuxPredetermines()
    {
        for (const auto &lieu : lieuxPredetermines)
        {
            if (lieu.x >= 0 && lieu.x < largeur && lieu.y >= 0 && lieu.y < hauteur)
            {
                carte[lieu.y][lieu.x].nomLieu = lieu.nom;
                if (lieu.type == Lieu::TypeLieu::VILLE)
                {
                    carte[lieu.y][lieu.x].aVille = true;
                }
                else if (lieu.type == Lieu::TypeLieu::DONJON)
                {
                    carte[lieu.y][lieu.x].aDonjon = true;
                }
            }
        }
    }
};
