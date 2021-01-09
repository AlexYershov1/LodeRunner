#include "staticInclude/Wall.h"
/*
Wall::Wall(const sf::Texture* icon, const sf::Vector2f& position, int mapW, int mapH)
	: StaticObject(icon, position, mapW, mapH)
{
}
*/
Wall::~Wall()
{
}

void Wall::handleCollision(Player& ply, Controller& game)
{
	ply.handleCollision(*this,game);
}

void Wall::handleCollision(Enemy& enemy, Controller& game)
{
	enemy.handleCollision(*this, game);
}
