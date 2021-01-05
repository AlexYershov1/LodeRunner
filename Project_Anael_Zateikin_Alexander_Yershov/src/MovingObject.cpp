#include "MovingObject.h"

MovingObject::MovingObject(const sf::Texture* icon, const sf::Vector2f& position, int mapW, int mapH)
	: GameObject(icon, position, mapW, mapH), m_speed(BASE_SPEED), m_respawnLocation(position)
{
}

MovingObject::~MovingObject()
{
}