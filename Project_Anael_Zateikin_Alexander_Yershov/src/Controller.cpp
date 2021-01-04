#pragma once
#include "Controller.h"
#include "Macros.h"

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
		(*objPtr)->move();
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
	auto staticObjPtr = m_staticObj.begin();
	for (; staticObjPtr != m_staticObj.end(); staticObjPtr++)
		(*staticObjPtr)->draw(this->m_gameWindow);
	//draw moving
	auto movingObjPtr = m_movingObj.begin();
	for (; movingObjPtr != m_movingObj.end(); movingObjPtr++)
		(*movingObjPtr)->draw(this->m_gameWindow);
	
}

void Controller::createIcons()
{
	Elements symbol;
	sf::Texture* icon;

	for (int row = 0; row < m_map.getHeight(); row++)
	{
		for (int col = 0; col < m_map.getWidth(); col++)
		{
			symbol = m_map.getSymbol(row, col);
			icon = m_textures.getIcon(symbol);

			if (isStaticObj(symbol))
				m_staticObj.push_back(std::make_unique<StaticObject>(icon));
			else
				m_movingObj.push_back(std::make_unique<MovingObject>(icon));
		}
	}
}
