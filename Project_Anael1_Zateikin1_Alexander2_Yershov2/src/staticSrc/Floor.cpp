#include "staticInclude/Floor.h"

Floor::~Floor()
{
}

void Floor::handleCollision(Player& ply, Controller& game)
{
	ply.handleCollision(*this, game);
}

void Floor::handleCollision(Enemy& enemy, Controller& game)
{
	enemy.handleCollision(*this, game);
}

void Floor::dig()
{
	m_eliminated = true;
	m_prevPos = this->getPos();
	this->m_icon.setPosition(-this->getIconWidth(), -this->getIconHeight());
	m_construction.restart();
}

void Floor::draw(sf::RenderWindow& window)
{
	if(!m_eliminated)
		window.draw(m_icon);
	else
	{
		if (m_construction.getElapsedTime().asSeconds() > 3)
		{
			m_eliminated = false;
			this->m_icon.setPosition(m_prevPos);
		}
	}
}


