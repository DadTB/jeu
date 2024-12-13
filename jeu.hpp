#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Monde/generationterrain.cpp"
#include "deplacement/deplacement.cpp"
#include "Inventaire/inventaire.cpp"


class Jeu
{
private:
    bool estdansinven = false;
    sf::RenderWindow window; // Déclaration de la fenêtre au niveau de la classe
    sf::Font font;
    sf::Clock clock;

public:

    Jeu()
    {
        window.create(sf::VideoMode(1800, 1000), "Daggerfall 2D");

        if (!font.loadFromFile("02587_ARIALMT.ttf"))
        {
            std::cerr << "Erreur lors du chargement de la police!" << std::endl;
        }
    }

    void DaggerFall2()
    {
        Deplacement d0;
        Inventaire i0(0.f, 0.f, 1800.f, 1000.f);
        GenerationTerrain g0;

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I)
                {
                    i0.toggle(); // Ouvrir ou fermer l'inventaire
                    if (estdansinven == false)
                    {
                        estdansinven = true;
                    }
                    else
                    {
                        estdansinven = false;
                    }
                }
            }

            // Détecter l'appui sur la touche I pour ouvrir ou fermer l'inventaire

            // Gérer les entrées de direction
            if (estdansinven == false)
            {
                d0.gereinput();
            }

            // Temps écoulé depuis la dernière itération
            sf::Time deltaTime = clock.restart();

            // Mettre à jour la position du personnage
            d0.mettreajour(deltaTime, g0.walls);

            // Rendu du terrain
            g0.renderGrid(window);

            i0.draw(window);

            // Affichage du sprite du personnage
            window.draw(d0.getRectangle());

            // Affichage à l'écran
            window.display();
        }
    }

    void DaggerFall2choixcreationpersonnage()
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
                            std::cout << "Nouvelle Partie sélectionnée!" << std::endl;
                            DaggerFall2choixclassepersonnage();
                            // Appeler la fonction pour démarrer une nouvelle partie
                        }
                        // Vérifier si la souris est sur l'option "Charger Partie"
                        else if (choixlong.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                        {
                            std::cout << "Charger Partie sélectionnée!" << std::endl;
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

    void DaggerFall2choixclassepersonnage()
    {
        sf::Text titleText("Quel classe souhaitez vous avoir ?", font, 50);
        titleText.setFillColor(sf::Color::White);
        titleText.setPosition(300, 100);

        DaggerFall2();

    }

    void DaggerFall2menutitre()
    {
        // Créer le texte du titre
        sf::Text titleText("Mon Jeu", font, 50);
        titleText.setFillColor(sf::Color::White);
        titleText.setPosition(300, 100);

        // Créer le texte pour les options
        sf::Text newGameText("Nouvelle Partie", font, 30);
        newGameText.setFillColor(sf::Color::Green);
        newGameText.setPosition(350, 250);

        sf::Text loadGameText("Charger Partie", font, 30);
        loadGameText.setFillColor(sf::Color::Green);
        loadGameText.setPosition(350, 300);

        sf::Text exitText("Quitter", font, 30);
        exitText.setFillColor(sf::Color::Green);
        exitText.setPosition(350, 350);

        // Gestion des événements
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
                        if (newGameText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                        {
                            std::cout << "Nouvelle Partie sélectionnée!" << std::endl;
                            DaggerFall2choixcreationpersonnage();
                            // Appeler la fonction pour démarrer une nouvelle partie
                        }
                        // Vérifier si la souris est sur l'option "Charger Partie"
                        else if (loadGameText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                        {
                            std::cout << "Charger Partie sélectionnée!" << std::endl;
                            // Appeler la fonction pour charger une partie
                        }
                        // Vérifier si la souris est sur l'option "Quitter"
                        else if (exitText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                        {
                            window.close();  // Fermer le jeu
                        }
                    }
                }
            }

            // Dessiner tout sur l'écran
            window.clear();  // Effacer l'écran
            window.draw(titleText);  // Dessiner le titre
            window.draw(newGameText);  // Dessiner le texte de la nouvelle partie
            window.draw(loadGameText);  // Dessiner le texte pour charger
            window.draw(exitText);  // Dessiner le texte pour quitter
            window.display();  // Afficher les éléments à l'écran
        }
    }
};