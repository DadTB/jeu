#include "jeu.hpp"

// Fonctions d'initialisation
void Jeu::initWindow()
{

    std::ifstream ifs("Config/window.ini");

    std::string title = "Daggerfall2";
    sf::VideoMode window_bounds(1800, 1000);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())  // cette condition permet de récupérer les données stockées dans le fichier config.ini
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title);   // crée une nouvelle fenêtre avec en paramètre les données stockées dans config.ini
    this->window->setFramerateLimit(framerate_limit);            // définis le max framerate
    this->window->setVerticalSyncEnabled(vertical_sync_enabled); // permet de définir la synchro verticale
}

void Jeu::initKeys()
{
    std::ifstream ifs("Config/supported_keys.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;

        while (ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }

    ifs.close();

    // pour afficher (non vitale) - a retirer plus tard
    for (auto i : this->supportedKeys)
    {
        std::cout << i.first << " " << i.second << "\n";
    }
}

void Jeu::initEtat()
{
    this->etats.push(new MenuprincipalEtat(this->window, &this->supportedKeys));
    this->etats.push(new Etatjeu(this->window, &this->supportedKeys));  // pile etats dans classe jeu de type Etat, pile de classe
}



//////////////////////////
// Constructeur et destructeur
//////////////////////////

Jeu::Jeu()
{
    this->initWindow();
    this->initKeys();
    this->initEtat();
}

Jeu::~Jeu()
{
    delete this->window;

    while(!this->etats.empty())      // permet de vider la pile etats
    {
        delete this->etats.top();
        this->etats.pop();
    }
}

//////////////////////////
// Fonctions
//////////////////////////

void Jeu::finjeu()
{

}

// mise à jour
void Jeu::mettreajourdt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Jeu::mettreajourevenementSFML()
{
    sf::Event event;
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Jeu::mettreajour()
{
    this->mettreajourevenementSFML();

    if (!this->etats.empty())
    {
        this->etats.top()->mettreajour(this->dt);

        if (this->etats.top()->avoirfin()) // permet de vider la pile et de mettre fin au if
        {
            this->etats.top()->finetat(); // appelle le boolein si on appui sur échap
            delete this->etats.top();
            this->etats.pop();
        }
    }
    else
    {
        this->finjeu();
        this->window->close();
    }
}

// rendue

void Jeu::render()
{
    this->window->clear();

    if (!this->etats.empty())
    {
        this->etats.top()->render(this->window);
    }

    this->window->display();
}


// coeur

void Jeu::lancer()
{
    while (this->window->isOpen())
    {
        this->mettreajourdt();
        this->mettreajour();
        this->render();
    }
}