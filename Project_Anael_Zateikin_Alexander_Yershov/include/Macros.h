#pragma once
#include <SFML/Graphics.hpp>


//grapics
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;
const float ICON_SIZE = 512;
const int SEED = 17;
const int NUM_OF_ENEMIE_TYPES = 3;
const int NUM_OF_BONUS_TYPES = 4;
const float BASE_SPEED = 100.0;
const float FALL_SPEED = 20.0;
const float STEP = 35.0;
const int NUM_OF_LIVES = 3;
const int COIN_VALUE = 2, STAGE_VALUE = 50;
const float STAGE_TIME = 90;
const float BONUS_TIME = 30;
const float SIGMA = 4.0;

const int HEADER_SIZE = 60;
const int REG_CHAR_SIZE = 100;
const float OUTLINE_THICKNESS = 5.0;
const float BOLD_OUTLINE = 10.0;

const char WALL_C = '#', EMPTY_C = ' ', BAR_C = '-', PLAYER_C = '@',
ENEMY_C = '%', LADDER_C = 'H', COIN_C = '*', BONUS_C = '?' ;

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

bool isStaticObj(const Elements);