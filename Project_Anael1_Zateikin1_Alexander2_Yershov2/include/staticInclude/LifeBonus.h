#pragma once
#include "Bonus.h"

class LifeBonus : public Bonus
{
public:
	using Bonus::Bonus;
	~LifeBonus();

	virtual void handleCollision(Player&, Controller&) override;
};
