#include "movingInclude/MovingObject.h"
#include "Macros.h"

MovingObject::MovingObject(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: GameObject(symbol, position, mapW, mapH),/* m_speed(BASE_SPEED),*/ m_respawnLocation(position),
	  m_prevPos(position)
{
}

MovingObject::~MovingObject()
{
}
