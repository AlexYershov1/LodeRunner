#include "movingInclude/Player.h"
#include "Macros.h"
#include "Controller.h"

sf::Vector2f Player::plyLocation;	// for smart enemy to follow player

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
    // get last position
    m_prevPos = m_icon.getPosition();
    // set initial icon
    m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::playerDefaultIcon));
    // make a move
	auto direction = getDirectionFromKey();
	m_icon.move(direction * BASE_SPEED * deltaTime.asSeconds());
    
    changeToCorrectDisplay(direction);  //change the scale to face the right direction
   

    if(outOfBounds(m_icon.getPosition())) //shouln't send anything - works on this object
        m_icon.setPosition(m_prevPos);

    plyLocation = this->getPos();   // for smart enemy to follow player
}

void Player::handleCollision(GameObject& obj, Controller& game)
{
    obj.handleCollision(*this, game);
}

void Player::handleCollision(Wall& wall, Controller& game)
{
    m_icon.setPosition(m_prevPos);
}

void Player::handleCollision(Floor& floor, Controller& game)
{
    if (this->getPos().y > m_prevPos.y) // trying to go down
    {
        if(floor.contains(this->centerDown()))  // floor is underneath
            m_icon.setPosition(m_prevPos);
    }
    if (this->contains(floor.Center()))
        m_icon.setPosition(m_prevPos);
}

void Player::handleCollision(Ladder& ladder, Controller&)
{
    if (this->contains(ladder.Center()))
        m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::playerClimbingIcon));
}

void Player::changeToCorrectDisplay(const sf::Vector2f& direction)  //move this to MovingObject and use maybe Type_def
{
    if (direction == DirectionVec[(int)Direction::Left] && (m_icon.getScale().x > 0))
        m_icon.scale(-1, 1);                         
    
    else if (direction == DirectionVec[(int)Direction::Right] && (m_icon.getScale().x < 0))
        m_icon.scale(-1, 1);    // -1,1 ?
    
    //else if (direction == DirectionVec[(int)Direction::Down])
        //m_icon.scale(1, 1);
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
