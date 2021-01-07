#include "staticInclude/Bonus.h"

Bonus::~Bonus()
{
}

Bonus::Bonus(const sf::Texture* icon, const sf::Vector2f& position, int mapW, int mapH)
	: StaticObject(icon, position, mapW, mapH)
{
}
