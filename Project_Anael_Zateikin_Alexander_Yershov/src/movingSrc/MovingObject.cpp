#include "movingInclude/MovingObject.h"
#include "Macros.h"
#include "staticInclude/Floor.h"

MovingObject::MovingObject(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: GameObject(symbol, position , mapW, mapH),/* m_speed(BASE_SPEED),*/ m_respawnLocation(position),
	  m_prevPos(position)
{
	m_icon.move(DirectionVec[(int)Direction::Up] * 1.2f);
	m_respawnLocation = m_icon.getPosition();
}

MovingObject::~MovingObject()
{
}

void MovingObject::fall(const sf::Time& clock)
{
	//auto checkPos = this->getPos();
	//checkPos.y += 2.0f;
	//if()
	m_prevPos = m_icon.getPosition();
	//this->m_icon.move(DirectionVec[(int)Direction::Down] * BASE_SPEED * clock.asSeconds());
	this->m_icon.move(DirectionVec[(int)Direction::Down] );
}

sf::Vector2f MovingObject::getRespawnLocation() const
{
	return m_respawnLocation;
}

const sf::Vector2f MovingObject::centerDown() const
{
	const auto rect = this->m_icon.getGlobalBounds();
	sf::Vector2f Location = { this->getPos().x + rect.width / 2, this->getPos().y + rect.height };
	return Location;
}
bool MovingObject::outOfBounds(const sf::Vector2f& Location) const	//shouldn't receive a location
{
	//needs to be changed - needs to receive the icon to know the width
	if (Location.x < 0 || (Location.x + m_icon.getGlobalBounds().width) > WINDOW_WIDTH ||	 //one possible soution 
		Location.y < 0 || Location.y > WINDOW_HEIGHT)
		return true;
	return false;
}
/*
void MovingObject::handleCollision(Floor&, Controller&)
{
	m_icon.setPosition(m_prevPos);
}
*/
