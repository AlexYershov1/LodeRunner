#pragma once
#include "MovingObject.h"
class Wall;

class Enemy : public MovingObject
{
public:
	using MovingObject::MovingObject;
	~Enemy();
	void move() override;
	virtual void handleCollision(const Wall&) override;
	
protected:
	Direction m_direction = Direction::Left;	// direction of movement
};