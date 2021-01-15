#pragma once
#include "Controller.h"
//#include "Macros.h"


Controller::Controller()
	: m_gameWindow(sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT /* caption size*/ ), "Game Window",
									sf::Style::Titlebar | sf::Style::Close)), 
	  m_level(1), m_score(0), m_stageTime(STAGE_TIME)
{
	srand(SEED);
	//m_map.get_size();
	//create icons
	//createIcons(); //CHANGE THE NAME TO CREATE OBJECT
	
}

Controller::~Controller()
{
}

void Controller::run()
{
	// game loop
	//sf::Event ev;
	sf::Clock clock;

	
	m_menu.activateStartScreen(this->m_gameWindow);
	m_map.readLvlMap();
	createObject();

    while(this->m_gameWindow.isOpen())
	{
		//clear, draw , display
		this->m_gameWindow.clear(sf::Color::White);
		draw();
		this->m_gameWindow.display();
		
		for (auto evnt = sf::Event(); m_gameWindow.pollEvent(evnt); )
		{
		
		
			switch (evnt.type)
			{
			case sf::Event::Closed:
				m_gameWindow.close();
				break;
			case sf::Event::KeyPressed:
				if (evnt.key.code == sf::Keyboard::X) // dig right
				{
					dig(true);
				}
				else if (evnt.key.code == sf::Keyboard::Z) // dig left
				{
					dig(false);
				}

			default:
				break;
			}
		}
			/*
		for (this->m_gameWindow.pollEvent(ev))
		{
			switch (ev.type)
			{
			default:
				break;
			}
		}

		*/
		//start clock
		
		//while stage is not over 
		//restart clock and save deltaTime 

		// if(isWon())
			//m_score += STAGE_VALUE * m_level ;
			// m_map.LoadLvlMap();
			// update data in controller
		// if(lostGame())
			// update data in contoller
			// activateStartScreen(this->m_window);
		move(clock.restart());	 //send deltaTime to move function
		

		//check life ...
	}
}

void Controller::move(sf::Time deltatime)
{
	auto objPtr = m_movingObj.begin();
	for (; objPtr != m_movingObj.end(); objPtr++)
	{
		(*objPtr)->move(deltatime);
		checkCollision(**objPtr, deltatime);			//operates on this
	}
}

void Controller::checkCollision(MovingObject& thisObj, sf::Time deltatime)
{
	//bool collided = false;
	// check collision between player and enemies
	for (auto& movable : m_movingObj)
	{
		if (thisObj.collidesWith(*movable))
		{
			thisObj.handleCollision(*movable, *this);
		}
	}
	m_map.checkCollision(thisObj, *this, deltatime) ;

}

void Controller::draw()
{
	this->m_map.draw(this->m_gameWindow);
	//draw moving
	for (auto& movable : m_movingObj)
		movable->draw(this->m_gameWindow);
	
	//draw captions : clock, score, life...
}

void Controller::eraseCoin(Coin& coin)
{
	m_map.eraseCoin(coin);
}

void Controller::increaseScore()
{
	this->m_score += COIN_VALUE * m_level;
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
	m_stageTime += BONUS_TIME;
}

void Controller::dig(bool direction)
{
	for (auto& movable : m_movingObj)
	{
		if (typeid(*movable) == typeid(Player))
		{
			auto digLocation = (*movable).centerDown();
			if (direction)
				digLocation.x += m_map.getStaticIconInfo(true);
			else
				digLocation.x -= m_map.getStaticIconInfo(true);
			digLocation.y += m_map.getStaticIconInfo(false) / 2;

			m_map.dig(digLocation);
			break;
		}
			
	}
	
}

void Controller::createObject()
{
	Elements symbol;
	//sf::Texture* icon;
	sf::Vector2f position ; //xPos, yPos
	float xPos, yPos;

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
	return std::make_unique<SmartEnemy>(Elements::enemy, position, mapW, mapH);
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

