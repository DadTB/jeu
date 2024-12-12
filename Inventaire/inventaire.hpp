#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

class Inventaire
{
private:
    sf::Vector2f m_position;
    sf::Vector2f m_size;
    bool m_isOpen;
    sf::RectangleShape m_background; // Fond de l'inventaire
    sf::Texture m_itemTexture;       // Texture pour les objets
    std::vector<sf::Sprite> m_items; // Liste des objets dans l'inventaire

public:
    Inventaire(float x, float y, float width, float height)
        : m_position(x, y), m_size(width, height), m_isOpen(false)
    {
        // Création du fond de l'inventaire (simple rectangle)
        m_background.setSize(m_size);
        m_background.setPosition(m_position);
        m_background.setFillColor(sf::Color(250, 0, 0)); // Couleur semi-transparente

        // Charge les textures des objets d'exemple
        if (!m_itemTexture.loadFromFile("item.png"))
        {
            // Charger une texture par défaut en cas d'erreur
            m_itemTexture.create(50, 50); // Texture vide
        }

        // Initialiser les objets de l'inventaire
        for (int i = 0; i < 5; ++i)
        {
            sf::Sprite item;
            item.setTexture(m_itemTexture);
            item.setPosition(m_position.x + 10.f + (i * 60.f), m_position.y + 10.f);
            m_items.push_back(item);
        }
    }

    // Ouvrir ou fermer l'inventaire
    void toggle();

    // Ajouter un item à l'inventaire
    void addItem(const sf::Sprite &item)
    {
        m_items.push_back(item);
    }

    // Rendu de l'inventaire
    void draw(sf::RenderWindow &window)
    {
        if (m_isOpen)
        {
            window.draw(m_background); // Dessiner le fond de l'inventaire

            // Dessiner chaque item de l'inventaire
            for (size_t i = 0; i < m_items.size(); ++i)
            {
                window.draw(m_items[i]);
            }
        }
    }

    // Vérifier si l'inventaire est ouvert
    bool isOpen() const
    {
        return m_isOpen;
    }


};