#include "staticInclude/Bar.h"

Bar::~Bar()
{
}

void Bar::handleCollision(Player& ply, Controller& game)
{
	ply.handleCollision(*this, game);
}

void Bar::handleCollision(Enemy& enemy, Controller& game)
{
	enemy.handleCollision(*this, game);
}
