#pragma once
#include "Bonus.h"

class ScoreBonus : public Bonus
{
public:
	using Bonus::Bonus;
	~ScoreBonus();

	virtual void handleCollision(Player&, Controller&) override;
};
