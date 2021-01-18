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

bool Player::decreaseLife()
{
	this->m_life--;
    if (this->m_life == 0)
        return false;
    return true;
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
    //m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::playerDefaultIcon));
    m_icon.setTexture(*TextureHolder::instance().getPlayerRunningIcon());

    //get direction of movement
	m_direction = getDirectionFromKey();

    //set texture
    if (m_direction == STAND)
        m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::playerDefaultIcon));
    else
    changeToCorrectDisplay(); //change the scale to face the right direction
    

    if (this->getFall())
        m_direction = DirectionVec[(int)Direction::Down];

    //move the sprite
	m_icon.move(m_direction * BASE_SPEED * deltaTime.asSeconds());
    
    //check bounds
    if (outOfBounds()) //shouln't send anything - works on this object
        this->moveToPrevPos();
    
    this->setFall(false);

    plyLocation = this->getPos();   // for smart enemy to follow player
}

int Player::getLife() const
{
    return this->m_life;
}

void Player::setLife(int update)
{
    this->m_life = update;
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
        m_prevPos.y -= 1.0f ; //to avoid getting stuck inside a floor
    }
    if (floor.contains(this->centerDown()) && (m_prevPos.y == getPos().y))
    {
        m_icon.setPosition(this->getPos().x, floor.getPos().y - 1.0f - this->getIconHeight()); //move above floor
    }
    else
        this->moveToPrevPos(); //case of after falling
}

void Player::handleCollision(Enemy& enemy, Controller& game)
{
    enemy.handleCollision(*this, game);
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

void Player::handleCollision(Bonus&, Controller&)
{
    static sf::Sound bonusHit;
    bonusHit.setBuffer(*TextureHolder::instance().getSound(Recording::bonus));
    bonusHit.play();
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
