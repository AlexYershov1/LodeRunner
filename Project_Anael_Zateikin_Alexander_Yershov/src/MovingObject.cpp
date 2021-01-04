#include "MovingObject.h"

MovingObject::MovingObject(const sf::Texture* texturePtr, const sf::Vector2f& initLoction)
	: GameObject(texturePtr), m_speed(BASE_SPEED), m_respawnLocation(initLoction)
{
}

MovingObject::~MovingObject()
{
}