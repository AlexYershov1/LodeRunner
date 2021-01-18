#pragma once
#include "StaticObject.h"

class Bar : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Bar();
	virtual void handleCollision(Player&, Controller&) override ;
	virtual void handleCollision(Enemy&, Controller&) override;

private:
	
};