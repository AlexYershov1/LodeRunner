#pragma once
#include "Controller.h"


Controller::Controller()
	: m_gameWindow(sf::RenderWindow(sf::VideoMode(1000, 800), "Game Window")),
	  m_level(1)
{
	
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
	auto it = m_movingObj.begin();
	for (; it != m_movingObj.end(); it++)
		*it.move();
}

void Controller::checkCollision()
{
	auto it = m_movingObj.begin();
	for (; it != m_movingObj.end(); it++)
	{
		// check collision between moving objects and static objects
		// check collision between player and enemies
	}
}
