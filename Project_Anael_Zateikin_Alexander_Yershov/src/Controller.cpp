#pragma once
#include "Controller.h"


Controller::Controller()
	: m_gameWindow(sf::RenderWindow(sf::VideoMode(1000, 800), "Game Window")),
	  m_level(1)
{
	//m_map.get_size();
	//create icons
	createIcons();
	
}

Controller::~Controller()
{
}

void Controller::run()
{
	// game loop
	sf::Event ev;
	int key;
    while(this->m_gameWindow.isOpen())
	{
		//clear, draw , display
		this->m_gameWindow.clear(sf::Color::White);
		draw();
		this->m_gameWindow.display();
		

		/*while (this->m_gameWindow.pollEvent(ev))
		{
			switch (ev.type)
			{
			default:
				break;
			}
		}*/
		move();
		checkCollision();
	}
}

void Controller::move()
{
	auto objPtr = m_movingObj.begin();
	for (; objPtr != m_movingObj.end(); objPtr++)
		*objPtr.move();
}

bool Controller::checkCollision()
{
	auto objPtr = m_movingObj.begin();
	for (; objPtr != m_movingObj.end(); objPtr++)
	{
		// check collision between moving objects and static objects
		// check collision between player and enemies
	}
}

void Controller::draw()
{
	//draw ststics
	auto objPtr = m_staticObj.begin();
	for (; objPtr != m_movingObj.end(); objPtr++)
		*objPtr.draw();
	//draw moving
	for (objPtr = m_movingObj.begin(); objPtr != m_movingObj.end(); objPtr++)
		*objPtr.draw();
	
}

void Controller::createIcons()
{
	char symbol;
	for (int row = 0; row < m_map.getHeight(); row++)
	{
		for (int col = 0; col < m_map.getWidth(); col++)
		{
			symbol = getSymbol(row, col);
			m_movingObj.push_back(std::make_unique<GameObject>(m_textures.getIcon(symbol));
			//(&m_textures.getIcon(symbol))) //the function getIcon returns an address to a texture
		}
	}
}
