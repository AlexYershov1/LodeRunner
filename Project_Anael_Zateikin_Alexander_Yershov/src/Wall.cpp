#include "Wall.h"

Wall::Wall(const sf::Texture* icon, const sf::Vector2f& position, int mapW, int mapH)
	: StaticObject(icon, position, mapW, mapH)
{
}

Wall::~Wall()
{
}