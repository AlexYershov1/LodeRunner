#pragma once
#include <SFML/Graphics.hpp>
#include "resourcesManager.h"

class StartScreen
{
public:
	StartScreen();
	~StartScreen();
	void activateStartScreen(sf::RenderWindow&);
private:
	sf::Font m_font;

	sf::Text m_header;
	sf::Text m_start;
	sf::Text m_exit;
	sf::RectangleShape m_background;

	bool handleClick(const sf::Vector2f&, sf::RenderWindow&) const;
	void handleMove(const sf::Vector2f&);
};