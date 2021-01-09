#pragma once
#include "StaticObject.h"

class Ladder : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Ladder();

	virtual void handleCollision(Player&, Controller&) override;
	virtual void handleCollision(Enemy&, Controller&) override;
private:

};