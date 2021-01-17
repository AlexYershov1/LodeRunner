#include "staticInclude/TimeBonus.h"
#include "Controller.h"

TimeBonus::~TimeBonus()
{
}

void TimeBonus::handleCollision(Player& ply, Controller& game)
{
	game.addTime();
	game.eraseObject(*this); 
}
