#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

class InitPays
{
private:

    // Fonctions composants
    void lireFichierConf(std::ifstream &file, std::unordered_map<std::string, std::string> &data);

    // Fonctions d'initialisation
    void initDirigeant(const std::string &filename);
    void initReforme(const std::string &filename);
    void initReligion();

protected:

public:

    InitPays();
    ~InitPays();
};