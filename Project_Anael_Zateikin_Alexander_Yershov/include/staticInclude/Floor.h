#pragma once
#include "StaticObject.h"

class Floor : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Floor();
	virtual void handleCollision(Player&, Controller&) override;
	virtual void handleCollision(Enemy&, Controller&) override ;
	
private:

};