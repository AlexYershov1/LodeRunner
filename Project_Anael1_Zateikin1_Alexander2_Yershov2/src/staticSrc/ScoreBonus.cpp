#include "staticInclude/ScoreBonus.h"
#include "Controller.h"


ScoreBonus::~ScoreBonus()
{
}

void ScoreBonus::handleCollision(Player& ply, Controller& game)
{
	game.increaseScore();
	game.eraseObject(*this);
	ply.handleCollision(*this, game);
}
