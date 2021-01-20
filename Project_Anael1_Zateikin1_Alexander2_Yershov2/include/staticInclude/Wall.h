#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Wall();
	virtual void handleCollision(Player&, Controller&) override;
	virtual void handleCollision(Enemy&, Controller&) override;
};
