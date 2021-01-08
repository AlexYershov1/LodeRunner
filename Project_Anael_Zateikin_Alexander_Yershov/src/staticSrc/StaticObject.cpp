#include "staticInclude/StaticObject.h"




StaticObject::StaticObject(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: GameObject(symbol, position, mapW, mapH)
{
}

StaticObject::~StaticObject()
{
}
