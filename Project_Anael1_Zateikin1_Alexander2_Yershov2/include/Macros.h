#pragma once
#include <SFML/Graphics.hpp>


//grapics
const int WINDOW_WIDTH = 1500;
const int WINDOW_HEIGHT = 800;
const int CAPTION_HEIGHT = 100;
const float ICON_SIZE = 512;
const int SEED = 7;

//game statistics
const int NUM_OF_ENEMIE_TYPES = 3;
const int NUM_OF_BONUS_TYPES = 4;
const int COIN_VALUE = 2, STAGE_VALUE = 50;
const float STAGE_TIME = 90;
const float BONUS_TIME = 30;

//moving statistics
const float BASE_SPEED = 100.0;
const float FALL_SPEED = 20.0;
const float STEP = 35.0;
const int NUM_OF_LIVES = 3;

//for functions
const bool GET_WIDTH = true;
const bool GET_HEIGHT = false;
const float SIGMA = 4.0;
const int DELTA_TIME = 5;


// for start screen
const int HEADER_SIZE = 60;
const int REG_CHAR_SIZE = 100;
const float OUTLINE_THICKNESS = 5.0;
const float BOLD_OUTLINE = 10.0;

// for caption
const int CAP_CHAR_SIZE = 30;
const float CAP_OUTLINE_THICKNESS = 3.0;
const int BUFF_DISTANCE = 10;
const int MUSIC_ICON_POS = 40;
const sf::Vector2f MUSIC_ICON_SCALE = { 0.07f, 0.07f };

const char WALL_C = '#', EMPTY_C = ' ', BAR_C = '-', PLAYER_C = '@',
ENEMY_C = '%', LADDER_C = 'H', COIN_C = '*', BONUS_C = '?' ;

const sf::Vector2f STAND = { 0,0 };
const sf::Vector2f DirectionVec[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

enum class Elements
{
	bar, coin, enemy, player, wall, ladder, floor, bonus, empty
};

enum class EnemyType
{
	dumb, mediocre, smart
};
enum class BonusType
{
	life, score, time, bad
};

enum class Direction
{
	Left, Right, Up, Down, 
};

enum class MovingObjTexture
{
	playerDefaultIcon, enemyDefaultIcon,
	playerClimbingIcon, enemyClimbingIcon, 
	charOnBarIcon
};

enum class Recording
{
	bonus, strike, win, background
};

bool isStaticObj(const Elements);