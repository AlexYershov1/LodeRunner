#include "movingInclude/Player.h"
#include "Macros.h"
#include "Controller.h"

sf::Vector2f Player::plyLocation;	// for smart enemy to follow player

Player::Player(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH), m_life(NUM_OF_LIVES)
{
    m_icon.scale(0.9f, 0.9f);
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
    //save the last position
    m_prevPos = m_icon.getPosition();

    // set initial icon
    m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::playerDefaultIcon));

    //get direction of movement
	m_direction = getDirectionFromKey();
    
    //change the scale to face the right direction
    changeToCorrectDisplay(); 

    //move the sprite
	m_icon.move(m_direction * BASE_SPEED * deltaTime.asSeconds());
    
    //check bounds
    if (outOfBounds(m_icon.getPosition())) //shouln't send anything - works on this object
        m_icon.setPosition(m_prevPos);
        

    plyLocation = this->getPos();   // for smart enemy to follow player
}

void Player::handleCollision(GameObject& obj, Controller& game)
{
    obj.handleCollision(*this, game);
}

void Player::handleCollision(Wall& , Controller& )
{
    this->moveToPrevPos(); //move back
}

void Player::handleCollision(Floor& floor, Controller& )
{
    if (floor.contains(m_prevPos) && floor.getPos().y < m_prevPos.y ) //if the collision is underneath the floor
    {
        m_prevPos.y += 1.0f ; //to avoid getting stuck inside a floor
    }

    //go back to previous location
    this->moveToPrevPos(); // <-----------> m_icon.setPosition(m_prevPos);
}

void Player::handleCollision(Bar& bar, Controller&)
{
    m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::charOnBarIcon));

    if (m_direction == DirectionVec[(int)Direction::Up])
        this->m_icon.setPosition(m_prevPos);
    if (m_direction == DirectionVec[(int)Direction::Down])
        this->m_icon.move(0, this->getIconHeight());
}

void Player::handleCollision(Ladder& ladder, Controller&)
{
    if (this->contains(ladder.Center()))
        m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::playerClimbingIcon));
}

void Player::changeToCorrectDisplay()  //move this to MovingObject and use maybe Type_def
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
