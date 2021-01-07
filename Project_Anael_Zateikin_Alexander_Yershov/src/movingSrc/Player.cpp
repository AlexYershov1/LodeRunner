#include "movingInclude/Player.h"
#include "Macros.h"

Player::Player(const sf::Texture* icon, const sf::Vector2f& position, int mapW, int mapH, std::vector<sf::Texture*>& iconsVector)
	: MovingObject(icon, position, mapW, mapH, iconsVector), m_life(NUM_OF_LIVES)
{
}


Player::~Player()
{
}

void Player::decreaseLife()
{
	this->m_life--;
}

void Player::move(sf::Time& deltaTime)
{
	//for further thought - where to ask if the action is "dig" ?

	auto direction = getDirectionFromKey();
	m_icon.move(direction * BASE_SPEED * deltaTime.asSeconds());
	
}

void Player::handleCollision(GameObject&) 
{

}

void Player::handleCollision(Wall&)
{

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
