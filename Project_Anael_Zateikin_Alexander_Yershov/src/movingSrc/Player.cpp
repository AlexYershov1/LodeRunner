#include "movingInclude/Player.h"
#include "Macros.h"
#include "Controller.h"

Player::Player(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH), m_life(NUM_OF_LIVES)
{
}


Player::~Player()
{
}

void Player::decreaseLife()
{
	this->m_life--;
}

void Player::increaseLife()
{
    m_life++;
}

void Player::move(sf::Time& deltaTime)
{
	//for further thought - where to ask if the action is "dig" ?
    m_prevPos = m_icon.getPosition();
	auto direction = getDirectionFromKey();
	m_icon.move(direction * BASE_SPEED * deltaTime.asSeconds());
	
}

void Player::handleCollision(GameObject& obj, Controller& game)
{
    obj.handleCollision(*this, game);
}

void Player::handleCollision(Wall& wall, Controller& game)
{

}

void Player::handleCollision(Floor&, Controller&)
{
    //m_icon.setPosition(m_prevPos);
    m_icon.move({ 0,-0.1 });
}

sf::Vector2f Player::getDirectionFromKey() const
{
    static const
        std::initializer_list<std::pair<sf::Keyboard::Key, sf::Vector2f>>
        keyToVectorMapping =
    {
        { sf::Keyboard::Right, { 1, 0 } },
        { sf::Keyboard::Left , { -1, 0 } },
        { sf::Keyboard::Up   , { 0, -1 } },
        { sf::Keyboard::Down , { 0, 1 } },
    };

    for (const auto& pair : keyToVectorMapping)
    {
        if (sf::Keyboard::isKeyPressed(pair.first))
        {
            return pair.second;
        }
    }

    return { 0, 0 };
}
