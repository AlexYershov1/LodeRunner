#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Macros.h"

class resourcesManager
{
public:
	~resourcesManager();
	static resourcesManager& instance();
	
	// get functions
	sf::Texture* getIcon(const Elements);
	sf::Texture* getChangingIcon(MovingObjTexture);
	sf::Texture* getEnemyChangingIcon();
	sf::Texture* getPlayerRunningIcon();
	sf::SoundBuffer* getSound(Recording);
	sf::Texture* getMusicIcon(bool);
	const sf::Texture* getbackGround(bool);
	sf::Font* getFont();
private:
	resourcesManager();
	resourcesManager(const resourcesManager&) = default;
	resourcesManager& operator=(const resourcesManager&) = default;

	void setImagesForObj();
	void createSwitchingIcons();
	void createEnemySwitchingIcons();
	void createPlayerSwitchingIcons();
	void createAudio();
	void createMusicIcon();
	void createBackgrounds();

	std::vector<sf::Texture> m_textures;
	std::vector<sf::Texture> m_iconVec;
	std::vector<sf::Texture> m_backgroundVec;
	std::vector<sf::SoundBuffer> m_audioVec;

	std::vector<sf::Texture> m_playerAnime;
	std::vector<sf::Texture> m_enemyAnime;
	sf::Font m_font;
	std::vector<sf::Texture> m_musicTextureVec;

	//members to aid in crearing a "run" effect
	int m_enemySerialNumber;
	int m_playerIconSerialNum;
	sf::Clock enemyAnimetionTimer;
	sf::Clock playerAnimationTimer;
};

