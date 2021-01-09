#pragma once
#include "MovingObject.h"


class Player : public MovingObject
{
public:
	//using MovingObject::MovingObject;
	Player(Elements, const sf::Vector2f& , int , int);
	~Player();
	void decreaseLife();	// decreases players' life by 1
	void increaseLife();
	virtual void move(sf::Time&) override;

	
	void handleCollision(GameObject&, Controller&) override ;
	void handleCollision(Wall&, Controller&) override ;
	virtual void handleCollision(Floor&, Controller&) override;	
	virtual void handleCollision(Player&, Controller&) override {};
	virtual void handleCollision(Enemy&, Controller&) override {};
	virtual void handleCollision(Bar&, Controller&) override {};
	virtual void handleCollision(Ladder&, Controller&) override {};
	virtual void handleCollision(Coin&, Controller&) override {};
	virtual void handleCollision(Bonus&, Controller&) override {};
private:
	sf::Vector2f getDirectionFromKey() const;
	int m_life;
};

