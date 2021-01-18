#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Caption
{
public:
	Caption();
	~Caption();
	void updateTime(float);
	void updateLevel(float);
	void updateScore(int);
	int getLvl() const;
	float getTime() const;
	void resetLvl();
	void resetTime(float); 
	void draw(sf::RenderWindow&);
	void resetLevelNum();
	void setTimelessOff();
	void resetScore();
	bool MusicIconContains(const sf::Event&) const;
	void setMusicIcon(bool);
private:
	sf::Clock m_Timer;
	float m_stageTime;
	int m_level;
	int m_score;
	bool m_timelessLevel;
	
	sf::Text m_scoreText;
	sf::Text m_stageTimeText;
	sf::Text m_levelText;

	sf::Sprite m_musicIcon;
};
