#include "movingInclude/MovingObject.h"
#include "Macros.h"

MovingObject::MovingObject(const sf::Texture* icon, const sf::Vector2f& position, int mapW, int mapH, std::vector<sf::Texture*>& iconVec)
	: GameObject(icon, position, mapW, mapH),/* m_speed(BASE_SPEED),*/ m_respawnLocation(position), m_iconArsenal(iconVec)
{
}

MovingObject::~MovingObject()
{
}
