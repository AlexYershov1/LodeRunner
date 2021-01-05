#pragma once
#include "MovingObject.h"

class Player : public MovingObject
{
public:
	//using MovingObject::MovingObject;
	Player(const sf::Texture*, const sf::Vector2f& , int , int);
	~Player();

	virtual void move(sf::Time) override {} ;

	
	void handleCollision(const GameObject&) override ;
	void handleCollision(const Wall&) override ;
	// virtual void handleCollision(const Floor&) = 0;	// maybe relevent
	virtual void handleCollision(const Player&) override {};
	virtual void handleCollision(const Enemy&) override {};
	virtual void handleCollision(const Bar&) override {};
	virtual void handleCollision(const Ladder&) override {};
	virtual void handleCollision(const Coin&) override {};
	virtual void handleCollision(const Bonus&) override {};
private:
	int m_life;
};

