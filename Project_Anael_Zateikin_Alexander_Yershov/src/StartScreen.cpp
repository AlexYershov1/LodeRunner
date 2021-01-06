#include "StartScreen.h"
#include "Macros.h"

const sf::Vector2f HEADER_POS = { WINDOW_WIDTH / 2 - 330, 10 };
const sf::Vector2f CENTER = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
const sf::Vector2f RECT_SIZE = { 140.0, 60.0 };

StartScreen::StartScreen()
{
	this->m_font.loadFromFile("SundayMorning.ttf");

	// intialize header
	this->m_header.setFont(m_font);
	m_header.setStyle(sf::Text::Style::Bold | sf::Text::Style::Italic);
	m_header.setCharacterSize(HEADER_SIZE);
	m_header.setPosition(HEADER_POS);
	m_header.setString("Get Every Penny !");
	m_header.setColor(sf::Color::Magenta);
	m_header.setOutlineColor(sf::Color::Black);
	m_header.setOutlineThickness(OUTLINE_THICKNESS);

	// intialize start button
	this->m_start.setFont(m_font);
	m_start.setColor(sf::Color::Green);
	m_start.setCharacterSize(REG_CHAR_SIZE);
	m_start.setPosition({ CENTER.x - 420, CENTER.y});
	m_start.setString("Start");
	m_start.setOutlineColor(sf::Color::Magenta);
	m_start.setOutlineThickness(OUTLINE_THICKNESS);

	// intialize exit button
	this->m_exit.setFont(m_font);
	m_exit.setColor(sf::Color::Green);
	m_exit.setCharacterSize(REG_CHAR_SIZE);
	m_exit.setPosition({ CENTER.x + 180, CENTER.y});
	m_exit.setString("Exit");
	m_exit.setOutlineColor(sf::Color::Magenta);
	m_exit.setOutlineThickness(OUTLINE_THICKNESS);
}

StartScreen::~StartScreen()
{
}

void StartScreen::activateStartScreen(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		window.draw(this->m_header);
		window.draw(this->m_start);
		window.draw(this->m_exit);
		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			sf::Vector2f Location;
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				Location = window.mapPixelToCoords
				({ event.mouseButton.x, event.mouseButton.y });
				if (handleClick(Location, window))
					return;
				break;
			case sf::Event::MouseMoved:
				Location = (sf::Vector2f)sf::Mouse::getPosition(window);
				handleMove(Location);
				break;
			}
		}
	}
}

bool StartScreen::handleClick(const sf::Vector2f& Location, sf::RenderWindow& window) const
{
	if (this->m_start.getGlobalBounds().contains(Location)) // pressed start
		return true;
	if (this->m_exit.getGlobalBounds().contains(Location))
		window.close();
	else
		return false;
}

void StartScreen::handleMove(const sf::Vector2f& Location)
{
	// mark/unmark start button
	if (this->m_start.getGlobalBounds().contains(Location))
	{
		this->m_start.setOutlineColor(sf::Color::Red);
		this->m_start.setOutlineThickness(BOLD_OUTLINE);
	}
	else
	{
		this->m_start.setOutlineColor(sf::Color::Magenta);
		this->m_start.setOutlineThickness(OUTLINE_THICKNESS);
	}
	// mark/unmark exit button
	if (this->m_exit.getGlobalBounds().contains(Location))
	{
		this->m_exit.setOutlineColor(sf::Color::Red);
		this->m_exit.setOutlineThickness(BOLD_OUTLINE);
	}
	else
	{
		this->m_exit.setOutlineColor(sf::Color::Magenta);
		this->m_exit.setOutlineThickness(OUTLINE_THICKNESS);
	}
}
