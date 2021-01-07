#include "staticInclude/StaticObject.h"




StaticObject::StaticObject(const sf::Texture* icon, const sf::Vector2f& position, int mapW, int mapH)
	: GameObject(icon, position, mapW, mapH)
{
}

StaticObject::~StaticObject()
{
}
