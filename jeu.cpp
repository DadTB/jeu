#include "jeu.hpp"

// Fonctions d'initialisation
void Jeu::initWindow()
{

    std::ifstream ifs("Config/window.ini");

    std::string title = "Daggerfall2";
    sf::VideoMode window_bounds(1800, 1000);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Jeu::initEtat()
{
    this->etats.push(new Etatjeu(this->window));
}


// Constructeur


Jeu::Jeu()
{
    this->initWindow();
    this->initEtat();
}

Jeu::~Jeu()
{
    delete this->window;

    while(!this->etats.empty())
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