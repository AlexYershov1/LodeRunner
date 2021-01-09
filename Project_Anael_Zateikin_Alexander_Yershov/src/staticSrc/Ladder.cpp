#include "staticInclude/Ladder.h"

Ladder::~Ladder()
{
}

void Ladder::handleCollision(Player& ply, Controller& game)
{
	ply.handleCollision(*this, game);
}

void Ladder::handleCollision(Enemy& enemy, Controller& game)
{
	enemy.handleCollision(*this, game);
}
