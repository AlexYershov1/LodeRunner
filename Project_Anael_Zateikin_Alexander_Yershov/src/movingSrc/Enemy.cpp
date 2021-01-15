#include "movingInclude/Enemy.h"
#include "movingInclude/Player.h"
#include "Controller.h"

Enemy::Enemy(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH)	
{
	m_direction = DirectionVec[(int)Direction::Left];	// direction of movement)
	//this->m_icon.scale(-1, 1);	// flipIcon();
	m_icon.scale(0.9f, 0.9f);

	//m_prevPos.x -= m_icon.getGlobalBounds().width;  //to correct the previous location after mirroring the sprite
	//m_icon.move(-m_icon.getGlobalBounds().width, 0);
}

Enemy::~Enemy()
{
}

void Enemy::move(sf::Time& clock)
{
	m_prevPos = m_icon.getPosition();
	// set to default icon
	m_icon.setTexture(*TextureHolder::instance().getEnemyChangingIcon());
	//change the scale to face the right direction
	changeToCorrectDisplay();
	// set new position
	this->m_icon.move(this->m_direction * BASE_SPEED * clock.asSeconds());
	if(outOfBounds())
		handleBlock();
}

void Enemy::handleCollision(GameObject& obj, Controller& game)
{
	obj.handleCollision(*this, game);
}

void Enemy::handleCollision(Wall&, Controller&)
{
	handleBlock();
}

void Enemy::handleCollision(Floor& floor, Controller&)
{
	//if (this->getPos().y > m_prevPos.y) // trying to go down
	//{
	//	auto leftVertice = sf::Vector2f(this->centerDown().x - this->getIconWidth() / 2, this->centerDown().y);
	//	auto rightVertice = sf::Vector2f(leftVertice.x + this->getIconWidth(), leftVertice.y);
	//	if (floor.contains(leftVertice) || floor.contains(rightVertice))  // floor is underneath
	//		m_icon.setPosition(m_prevPos);
	//}
	//if (this->contains(floor.Center()))
	//	m_icon.setPosition(m_prevPos);
	/*
	
	
	if (floor.contains(m_prevPos) && floor.getPos().y < m_prevPos.y) //if the collision is underneath the floor
	{
		//if left to floor - move left
		//if right to floor - move right


		//move to center of ladder
	}
	*/
	
		//std::abs(Player::plyLocation.y - this->getPos().y) > SIGMA)	// not on same level
	this->moveToPrevPos();
	//we need to add a function that will teleport a moving object above floor ==> move to top coordinate of floor + a pixel (const)

}

void Enemy::handleCollision(Player& ply, Controller& game)
{
	ply.decreaseLife();
	//game.restartLevel();
}

void Enemy::handleCollision(Bar&, Controller&)
{
	m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::charOnBarIcon));
	if(m_direction == DirectionVec[(int)Direction::Up] || m_direction == DirectionVec[(int)Direction::Down])
		this->m_icon.move(0, this->getIconHeight());
}

void Enemy::handleCollision(Ladder& ladder, Controller& game)
{
	if(this->contains(ladder.Center()))
		m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::enemyClimbingIcon));
}

void Enemy::handleBlock() 
{
	m_icon.setPosition(m_prevPos);
	if (m_direction == DirectionVec[(int)Direction::Left])
		m_direction = DirectionVec[(int)Direction::Right];
	else
		m_direction = DirectionVec[(int)Direction::Left];

	//this->m_icon.scale(-1, 1);	// flipIcon();
}
