#pragma once
#include "Bonus.h"

class TimeBonus : public Bonus
{
public:
	using Bonus::Bonus;
	~TimeBonus();

	virtual void handleCollision(Player&, Controller&) override;

};
