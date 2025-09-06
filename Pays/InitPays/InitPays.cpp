#include "InitPays.hpp"

/////////////////////////////////////////////
// Fonctions composants
/////////////////////////////////////////////

void InitPays::lireFichierConf(std::ifstream &file, std::unordered_map<std::string, std::string> &data) {
    std::string line;
    
    while (std::getline(file, line)) {
        line.erase(0, line.find_first_not_of(" \t")); // Supprimer les espaces/tabs en début de ligne
        
        // Fin de section
        if (line == "}") {
            break;
        }

        std::istringstream iss(line);
        std::string key, equal, value;
        
        if (iss >> key >> equal) {
            if (equal == "=") {
                std::getline(iss, value);
                value.erase(0, value.find_first_not_of(" ")); // Supprimer espaces initiaux
                data[key] = value;
            }
        }
    }
}

/////////////////////////////////////////////
// Fonctions d'initialisation
/////////////////////////////////////////////

void InitPays::initDirigeant(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("dirigeant =") != std::string::npos) {
            std::unordered_map<std::string, std::string> data;
            this->lireFichierConf(file, data);
        }
    }
    
}

void InitPays::initReforme(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("reforme =") != std::string::npos) {
            std::unordered_map<std::string, std::string> data;
            this->lireFichierConf(file, data);
        }
    }
}

void InitPays::initReligion()
{
    
}

/////////////////////////////////////////////
// Constructeurs et destructeurs
/////////////////////////////////////////////

InitPays::InitPays()
{
    std::string filename = "FRANCE.txt";
    this->initDirigeant(filename);
    this->initReforme(filename);
    this->initReligion();
}

InitPays::~InitPays()
{

}