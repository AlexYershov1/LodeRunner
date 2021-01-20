#pragma once
#include "Controller.h"
//#include "Macros.h"


Controller::Controller()
	: m_gameWindow(sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT + CAPTION_HEIGHT), "Game Window",
		sf::Style::Titlebar | sf::Style::Close)),
	m_isStrike(false)
{
	srand(SEED);
}

Controller::~Controller()
{
}

void Controller::run()
{
	// set background music
	sf::Sound backGroundMusic;
	sf::Sound effect;
	backGroundMusic.setBuffer(*resourcesManager::instance().getSound(Recording::background));
	backGroundMusic.play();
	backGroundMusic.setLoop(true);
	backGroundMusic.setVolume(2);
	// set background image
	sf::RectangleShape mainBackground;
	mainBackground.setSize({ WINDOW_WIDTH, WINDOW_HEIGHT + CAPTION_HEIGHT });
	mainBackground.setTexture(resourcesManager::instance().getbackGround(false));
	// game loop
	m_menu.activateStartScreen(this->m_gameWindow);

	m_timer.restart();
	m_map.readLvlMap();
	createObject();
	this->m_caption.updateLevel(m_map.getInitLevelTime());	// param to be changed

    while(this->m_gameWindow.isOpen())
	{
		//clear, draw , display
		this->m_gameWindow.clear(sf::Color::White);
		this->m_gameWindow.draw(mainBackground);
		draw();
		this->m_gameWindow.display();
		
		for (auto evnt = sf::Event(); m_gameWindow.pollEvent(evnt); )
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				m_gameWindow.close();
				break;
			case sf::Event::KeyPressed:		// handles digging event
				if (evnt.key.code == sf::Keyboard::X) // dig right
				{
					dig(true);
				}
				else if (evnt.key.code == sf::Keyboard::Z) // dig left
				{
					dig(false);
				}
				break;
			case sf::Event::MouseButtonReleased:		// stopping and resuming background music
				if (m_caption.MusicIconContains(evnt))
				{
					if (backGroundMusic.getStatus() == sf::SoundSource::Status::Playing)
					{
						backGroundMusic.stop();
						m_caption.setMusicIcon(false);
					}	
					else
					{
						backGroundMusic.play();
						m_caption.setMusicIcon(true);
					}
				}
				break;
			default:
				break;
			}
		}

		move(m_timer.restart());
		
		if (m_isStrike)
		{
			m_isStrike = false;
			continue;
		}

		if (m_map.LvlWon())
			newLvl(effect);

		if (m_caption.getTime() <= 0)	// level time is up
			strike(effect);
	}
}


void Controller::newLvl(sf::Sound& effect)
{
	effect.setBuffer(*resourcesManager::instance().getSound(Recording::win));
	effect.play();

	m_caption.updateScore(STAGE_VALUE * m_caption.getLvl());
	
	m_caption.setTimelessOff();
	int updatedLife = resetLvl(); //removes all movables and saves the players lives
	m_map.resetLvlMap();		  //removes all the static objects and frees map vectors
	

	if (!m_map.readLvlMap()) //if reached last level 
		newGame();
	else
		updatePlayerLife(updatedLife);

	m_caption.updateLevel(m_map.getInitLevelTime());
	createObject();
}

void Controller::strike(sf::Sound& effect)	// player lost a life, level resets
{
	effect.setBuffer(*resourcesManager::instance().getSound(Recording::strike));
	effect.play();

	int livesLeft = updatePlayerLife();
	if (!livesLeft )	// no more strikes left
	{
		m_isStrike = true;
		resetLvl();
		m_map.resetLvlMap();
		//livesLeft = NUM_OF_LIVES;
		newGame();

		m_caption.updateLevel(m_map.getInitLevelTime());
		createObject();
	}

	else
	{
		moveBackToRespawnLoc();	// move all the movable objects to respawn location
		m_caption.updateLife(livesLeft);
	}
		
	
	m_caption.resetTime(m_map.getInitLevelTime());
}

float Controller::getStaticIconInfo(bool isWidth) const
{
	return m_map.getStaticIconInfo(isWidth);
}

void Controller::newGame()
{
	m_menu.activateStartScreen(this->m_gameWindow);

	//reset statistics 
	m_caption.setTimelessOff();
	m_caption.resetScore();
	m_timer.restart();
	m_map.resetStreamPtr();
	updatePlayerLife(NUM_OF_LIVES);
	m_caption.updateLife(NUM_OF_LIVES);

	//read new level
	m_map.readLvlMap();
	m_caption.resetLevelNum();
}


void Controller::move(sf::Time deltatime)
{
	auto size = m_movingObj.size();
	for (auto& movable : m_movingObj)
	{
		movable->move(deltatime);
		checkCollision(*movable, deltatime);

		
		if (m_isStrike)
			break;
		if (size < m_movingObj.size())
			break;
	}
}

void Controller::checkCollision(MovingObject& thisObj, sf::Time deltatime)
{
	// check collision between player and enemies
	for (auto& movable : m_movingObj)
	{
		if (thisObj.collidesWith(*movable))
		{
			thisObj.handleCollision(*movable, *this);

			//might reach strike
			if (m_isStrike)
				return;
		}
	}
	m_map.checkCollision(thisObj, *this, deltatime) ; //check collisions with static objects
}

void Controller::draw()
{
	//draw static objects
	this->m_map.draw(this->m_gameWindow);

	//draw moving
	for (auto& movable : m_movingObj)
		movable->draw(this->m_gameWindow);
	
	//draw captions 
	this->m_caption.draw(this->m_gameWindow);
}

void Controller::eraseObject(StaticObject& staticObj)
{
	m_map.eraseObject(staticObj);
}

void Controller::increaseScore()
{
	this->m_caption.updateScore(COIN_VALUE * this->m_caption.getLvl());
}

void Controller::addEnemy()
{
	//random through the movingObj vector, and get respawnLocation
	auto pos = (*m_movingObj[rand() % m_movingObj.size()]).getRespawnLocation();
	auto newEnemy = selectEnemyType(pos, m_map.getWidth(), m_map.getHeight());
	m_movingObj.push_back(std::move(newEnemy));
}

void Controller::addTime()
{
	this->m_caption.updateTime(BONUS_TIME);
}

void Controller::dig(bool direction)
{
	for (auto& movable : m_movingObj)
	{
		if (typeid(*movable) == typeid(Player))
		{
			//calculate the dig location
			auto digLocation = (*movable).centerDown();

			if (direction)	//if right
				digLocation.x += m_map.getStaticIconInfo(GET_WIDTH);
			else			//left
				digLocation.x -= m_map.getStaticIconInfo(GET_WIDTH);

			digLocation.y += m_map.getStaticIconInfo(GET_HEIGHT) / 2;

			m_map.dig(digLocation);
			break;
		}	
	}
}

void Controller::createObject()
{
	Elements symbol;
	sf::Vector2f position ;
	float xPos, yPos;

	//convert a location in a char vector to a location on the window
	for (int row = 0; row < m_map.getHeight(); row++)
	{
		for (int col = 0; col < m_map.getWidth(); col++)
		{
			symbol = m_map.getSymbol(row, col);
			if (symbol == Elements::empty)
				continue;
			xPos = ((float)WINDOW_WIDTH / (float)(m_map.getWidth())) * col ;
			yPos = ((float)WINDOW_HEIGHT / (float)(m_map.getHeight())) * row;
			position = { xPos, yPos };
			

			if (isStaticObj(symbol)) //static object
				this->m_map.createStaticObject(symbol, position);
			else   //moving object
			{
				std::unique_ptr<MovingObject> movable = createMovingObject(symbol, position, m_map.getWidth(), m_map.getHeight());
				m_movingObj.push_back(std::move(movable));
					
			}
		}
	}
}

int Controller::updatePlayerLife(int update)
{
	for (auto& movable : m_movingObj)
	{
		auto plyPtr = movable.get();
		if (dynamic_cast<Player*>(plyPtr))
		{
			if (update == 0)
				return dynamic_cast<Player*>(plyPtr)->decreaseLife();
			else
				dynamic_cast<Player*>(plyPtr)->setLife(update);
		}	
	}
	return NULL;
}

int Controller::resetLvl()
{
	int updatedLife = 0;

	while (!m_movingObj.empty())
	{
		auto movingPtr = m_movingObj.begin();
		if (auto plyPtr = dynamic_cast<Player*>((*movingPtr).get()))
			updatedLife = plyPtr->getLife();	// extract the life member from player before deleting it

		m_movingObj.erase(movingPtr);
	}

	return updatedLife;
}

void Controller::moveBackToRespawnLoc()
{
	for (auto& movable : m_movingObj)
		(*movable).respawn();
}

std::unique_ptr<MovingObject> Controller::createMovingObject(Elements type, sf::Vector2f position, int mapW, int mapH)
{
	switch (type)
	{
	case Elements::player:
		return std::make_unique<Player>(type, position, mapW, mapH);
		
	case Elements::enemy:
		return selectEnemyType(position, mapW, mapH); 
	}
	return nullptr;
}

std::unique_ptr<Enemy> selectEnemyType(sf::Vector2f position, int mapW, int mapH)
{
	int choice = rand() % NUM_OF_ENEMIE_TYPES; //choose one of three enemy types
	
	//
	return std::make_unique<SmartEnemy>(Elements::enemy, position, mapW, mapH);
	//

	switch ((EnemyType)choice)
	{
	case EnemyType::dumb :
		return std::make_unique<DumbEnemy>(Elements::enemy, position, mapW, mapH);
	case EnemyType::mediocre:
		return std::make_unique<MediocreEnemy>(Elements::enemy, position, mapW, mapH);
	case EnemyType::smart:
		return std::make_unique<SmartEnemy>(Elements::enemy, position, mapW, mapH);
	}

	return nullptr;
}

