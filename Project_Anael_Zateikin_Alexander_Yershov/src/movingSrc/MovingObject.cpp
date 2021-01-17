#include "movingInclude/MovingObject.h"
#include "Macros.h"
#include "staticInclude/Floor.h"

MovingObject::MovingObject(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: GameObject(symbol, position , mapW, mapH),/* m_speed(BASE_SPEED),*/ m_respawnLocation(position),
	  m_prevPos(position), m_falling(false)
{
	m_icon.move(DirectionVec[(int)Direction::Up] * 2.2f);
	m_respawnLocation = m_icon.getPosition();

	//making the moving objects smaller than static objects
	//m_icon.scale(1.0f, 1.2f);	//specific adjustment for the texture "enemyMatan.png". for different texture might be different
}

MovingObject::~MovingObject()
{
}

void MovingObject::fall(const sf::Time& clock)
{
	//save prevoius
	m_prevPos = m_icon.getPosition();

	//move down
	//this->m_icon.move(DirectionVec[(int)Direction::Down] * BASE_SPEED * clock.asSeconds());
	this->m_icon.move(DirectionVec[(int)Direction::Down] );
}

sf::Vector2f MovingObject::getRespawnLocation() const
{
	return m_respawnLocation;
}

const sf::Vector2f MovingObject::centerDown() const
{
	const auto rect = this->m_icon.getGlobalBounds();
	sf::Vector2f Location = { this->getPos().x + rect.width / 2, this->getPos().y + rect.height };
	return Location;
}
void MovingObject::moveToPrevPos()
{
	m_icon.setPosition(m_prevPos);
}

void MovingObject::changeToCorrectDisplay()
{
	//if direction is left but was right before
	if (m_direction == DirectionVec[(int)Direction::Left] && (m_icon.getScale().x > 0))
	{
		m_icon.scale(-1, 1);
		m_prevPos.x += m_icon.getGlobalBounds().width;      //to correct the previous location after mirroring the sprite
		m_icon.move(m_icon.getGlobalBounds().width, 0);
	}

	//if direction is right but was left before
	else if (m_direction == DirectionVec[(int)Direction::Right] && (m_icon.getScale().x < 0))
	{
		m_icon.scale(-1, 1);
		m_prevPos.x -= m_icon.getGlobalBounds().width;  //to correct the previous location after mirroring the sprite
		m_icon.move(-m_icon.getGlobalBounds().width, 0);
		}
}

bool MovingObject::outOfBounds() const	//shouldn't receive a location
{
	if (this->m_icon.getGlobalBounds().left < 0 ||
		this->m_icon.getGlobalBounds().left + this->m_icon.getGlobalBounds().width > WINDOW_WIDTH ||
		this->m_icon.getGlobalBounds().top < 0 ||
		this->m_icon.getGlobalBounds().top + this->m_icon.getGlobalBounds().height > WINDOW_HEIGHT)
		return true;
	return false;
}

bool MovingObject::getFall() const
{
	return this->m_falling;
}

void MovingObject::setFall(bool update)
{
	this->m_falling = update;
}

void MovingObject::respawn()
{
	this->m_icon.setPosition(this->m_respawnLocation);
}

