#pragma once
#include "Bonus.h"

class BadBonus : public Bonus
{
public:
	using Bonus::Bonus;
	~BadBonus();
	virtual void handleCollision(Player&, Controller&) override;

};

