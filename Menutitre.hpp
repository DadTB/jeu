#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "jeu.hpp"

class Menu {
private:

    sf::RenderWindow window; // Déclaration de la fenêtre au niveau de la classe
    sf::Font font;
    sf::Clock clock;

public:
    Menu()
    {
        window.create(sf::VideoMode(1800, 1000), "Daggerfall 2D");

        if (!font.loadFromFile("02587_ARIALMT.ttf"))
        {
            std::cerr << "Erreur lors du chargement de la police!" << std::endl;
        }
        if (!font.loadFromFile("02587_ARIALMT.ttf")) {
            std::cerr << "Erreur lors du chargement de la police!" << std::endl;
        }
    }

    // Afficher le menu principal
    void afficherMenuPrincipal()
    {
        Jeu j0;

        sf::Text titleText("Mon Jeu", font, 50);
        titleText.setFillColor(sf::Color::White);
        titleText.setPosition(300, 100);

        sf::Text newGameText("Nouvelle Partie", font, 30);
        newGameText.setFillColor(sf::Color::Green);
        newGameText.setPosition(350, 250);

        sf::Text loadGameText("Charger Partie", font, 30);
        loadGameText.setFillColor(sf::Color::Green);
        loadGameText.setPosition(350, 300);

        sf::Text exitText("Quitter", font, 30);
        exitText.setFillColor(sf::Color::Green);
        exitText.setPosition(350, 350);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    if (newGameText.getGlobalBounds().contains(mousePos))
                    {
                        std::cout << "Nouvelle Partie sélectionnée!" << std::endl;
                        // Retourne un choix ou appelle une méthode liée
                        DaggerFall2choixcreationpersonnage(window);
                    }
                    else if (loadGameText.getGlobalBounds().contains(mousePos))
                    {
                        std::cout << "Charger Partie sélectionnée!" << std::endl;
                        // Retourne un choix ou appelle une méthode liée
                    }
                    else if (exitText.getGlobalBounds().contains(mousePos))
                    {
                        window.close();
                    }
                }
            }

            window.clear();
            window.draw(titleText);
            window.draw(newGameText);
            window.draw(loadGameText);
            window.draw(exitText);
            window.display();
        }
    }

    void DaggerFall2choixcreationpersonnage(sf::RenderWindow& window)
    {
        sf::Text titleText("Souhaitez vous choisir parmi les classes deja existantes ou creer la votre ?", font, 40);
        titleText.setFillColor(sf::Color::White);
        titleText.setPosition(300, 100);

        sf::Text choixrapide("Classe existante", font, 30);
        choixrapide.setFillColor(sf::Color::Blue);
        choixrapide.setPosition(350, 250);
        
        sf::Text choixlong("Creer classe", font, 30);
        choixlong.setFillColor(sf::Color::Blue);
        choixlong.setPosition(350, 300);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Vérifier si la souris est sur l'option "Nouvelle Partie"
                        if (choixrapide.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                        {
                            std::cout << "Clase existante" << std::endl;
                            afficherMenuChoixClasse(window);
                            // Appeler la fonction pour démarrer une nouvelle partie
                        }
                        // Vérifier si la souris est sur l'option "Charger Partie"
                        else if (choixlong.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                        {
                            std::cout << "Classe personnalisé" << std::endl;
                            // Appeler la fonction pour charger une partie
                        }
                    }
                }
            }
            window.clear();  // Effacer l'écran
            window.draw(titleText);  // Dessiner le titre
            window.draw(choixrapide);  // Dessiner le texte pour le choix court
            window.draw(choixlong);  // Dessiner le texte pour le choix long
            window.display();  // Afficher les éléments à l'écran
        }
    }

    // Autres méthodes pour des menus spécifiques
    void afficherMenuChoixClasse(sf::RenderWindow& window)
    {
        Jeu j0;

        sf::Text titleText("Quel classe souhaitez-vous avoir ?", font, 50);
        titleText.setFillColor(sf::Color::White);
        titleText.setPosition(300, 100);

        sf::Text chevalier("Chevalier", font, 30);
        chevalier.setFillColor(sf::Color::Blue);
        chevalier.setPosition(350, 250);

        sf::Text barbare("Barbare", font, 30);
        barbare.setFillColor(sf::Color::Blue);
        barbare.setPosition(350, 300);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    if (chevalier.getGlobalBounds().contains(mousePos))
                    {
                        std::cout << "Chevalier sélectionné!" << std::endl;
                        j0.DaggerFall2(window, clock);
                    }
                    else if (barbare.getGlobalBounds().contains(mousePos))
                    {
                        std::cout << "Barbare sélectionné!" << std::endl;
                    }
                }
            }

            window.clear();
            window.draw(titleText);
            window.draw(chevalier);
            window.draw(barbare);
            window.display();
        }
    }
};