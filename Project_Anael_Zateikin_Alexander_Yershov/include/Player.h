#pragma once
#include "MovingObject.h"


class Player : public MovingObject
{
public:
	//using MovingObject::MovingObject;
	Player(const sf::Texture*, const sf::Vector2f& , int , int, std::vector<sf::Texture*>&);
	~Player();
	void decreaseLife();	// decreases players' life by 1
	virtual void move(sf::Time&) override;

	
	void handleCollision(GameObject&) override ;
	void handleCollision(Wall&) override ;
	// virtual void handleCollision(const Floor&) = 0;	// maybe relevent
	virtual void handleCollision(Player&) override {};
	virtual void handleCollision(Enemy&) override {};
	virtual void handleCollision(Bar&) override {};
	virtual void handleCollision(Ladder&) override {};
	virtual void handleCollision(Coin&) override {};
	virtual void handleCollision(Bonus&) override {};
private:
	sf::Vector2f getDirectionFromKey() const;
	int m_life;
};

