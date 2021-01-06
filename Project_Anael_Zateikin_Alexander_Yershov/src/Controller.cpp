#pragma once
#include "Controller.h"
//#include "Macros.h"

Controller::Controller()
	: m_gameWindow(sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game Window",
									sf::Style::Titlebar | sf::Style::Close)), 
	  m_level(1)
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
		checkCollision(**objPtr);			//operates on this
	}
		
}

void Controller::checkCollision(MovingObject& thisObj)
{
	// check collision between player and enemies
	for (auto& movable : m_movingObj)
	{
		if (thisObj.collidesWith(*movable))
			thisObj.handleCollision(*movable);
	}
	m_map.checkCollision(thisObj);
}

void Controller::draw()
{
	this->m_map.draw(this->m_gameWindow);
	//draw moving
	for (auto& movable : m_movingObj)
		movable->draw(this->m_gameWindow);
	
}

void Controller::createObject() 
{
	Elements symbol;
	sf::Texture* icon;
	sf::Vector2f position ; //xPos, yPos
	float xPos, yPos;

	for (int row = 0; row < m_map.getHeight(); row++)
	{
		for (int col = 0; col < m_map.getWidth(); col++)
		{
			symbol = m_map.getSymbol(row, col);
			if ((icon = m_textures.getIcon(symbol)) == nullptr)
				continue;
			xPos = ((float)WINDOW_WIDTH / (float)(m_map.getWidth())) * col ;
			yPos = ((float)WINDOW_HEIGHT / (float)(m_map.getHeight())) * row;
			position = { xPos, yPos };
			

			if (isStaticObj(symbol)) //static object
				this->m_map.createStaticObject(symbol, icon, position);
			else   //moving object
			{
				std::unique_ptr<MovingObject> movable = createMovingObject(symbol, icon, position, m_map.getWidth(), m_map.getHeight());
				m_movingObj.push_back(std::move(movable));
					
			}
		}
	}
}

std::unique_ptr<MovingObject> Controller::createMovingObject(Elements type, sf::Texture* icon, sf::Vector2f position, int mapW, int mapH)
{
	auto iconVec = this->m_textures.createSwitchingIcons();
	switch (type)
	{
	case Elements::player:
		return std::make_unique<Player>(icon, position, mapW, mapH, iconVec);
		
	case Elements::enemy:
		return selectEnemyType(icon, position, mapW, mapH, iconVec); 
	}
	return nullptr;
}

std::unique_ptr<Enemy> selectEnemyType(sf::Texture* icon, sf::Vector2f position, int mapW, int mapH, std::vector<sf::Texture*>& iconVec)
{
	int choice = rand() % NUM_OF_ENEMIE_TYPES; //choose one of three enemy types

	switch ((EnemyType)choice)
	{
	case EnemyType::dumb :
		return std::make_unique<DumbEnemy>(icon, position, mapW, mapH, iconVec);
	case EnemyType::mediocre:
		return std::make_unique<MediocreEnemy>(icon, position, mapW, mapH, iconVec);
	case EnemyType::smart:
		return std::make_unique<SmartEnemy>(icon, position, mapW, mapH, iconVec);
	}

	return nullptr;
}

//std::unique_ptr<Bonus> selectBonusType(sf::Texture* icon, sf::Vector2f position, int mapW, int mapH)
//{
//	int choice = rand() % NUM_OF_BONUS_TYPES; //choose one of three enemy types
//
//	switch ((BonusType)choice)
//	{
//	case BonusType::life:
//		return std::make_unique<LifeBonus>(icon, position, mapW, mapH);
//	case BonusType::score:
//		return std::make_unique<ScoreBonus>(icon, position, mapW, mapH);
//	case BonusType::time:
//		return std::make_unique<TimeBonus>(icon, position, mapW, mapH);
//	case BonusType::bad:
//		return std::make_unique<BadBonus>(icon, position, mapW, mapH);
//	}
//	return nullptr;
//}

//std::unique_ptr<StaticObject>  Controller::createStaticObject(Elements type, sf::Texture* icon, sf::Vector2f position, int mapW, int mapH)
//{
//	switch (type)
//	{
//	case Elements::wall:
//	case Elements::floor:
//		return std::make_unique<Wall>(icon, position, mapW, mapH);
//	case Elements::ladder:
//		return std::make_unique<Ladder>(icon, position, mapW, mapH);
//	case Elements::bar:
//		return std::make_unique<Bar>(icon, position, mapW, mapH);
//	case Elements::coin:
//		return std::make_unique<Coin>(icon, position, mapW, mapH);
//	case Elements::bonus:
//		return selectBonusType(icon, position, mapW, mapH);
//	
//	}
//	return nullptr;
//}

