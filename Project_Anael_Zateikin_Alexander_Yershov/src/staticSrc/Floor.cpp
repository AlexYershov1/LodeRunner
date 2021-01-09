#include "staticInclude/Floor.h"

Floor::~Floor()
{
}

void Floor::handleCollision(Player& ply, Controller& game)
{
	ply.handleCollision(*this, game);
}

void Floor::handleCollision(Enemy& enemy, Controller& game)
{
	enemy.handleCollision(*this, game);
}
