#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Macros.h"

class TextureHolder
{
public:
	~TextureHolder();
	static TextureHolder& instance();
	
	// get functions
	sf::Texture* getIcon(const Elements);
	sf::Texture* getChangingIcon(MovingObjTexture);
	sf::Texture* getEnemyChangingIcon();
	sf::SoundBuffer* getSound(Recording);
	sf::Texture* getMusicIcon(bool);
	sf::Font* getFont();
private:
	TextureHolder();
	TextureHolder(const TextureHolder&) = default;
	TextureHolder& operator=(const TextureHolder&) = default;

	void setImagesForObj();
	void createSwitchingIcons();
	void createEnemySwitchingIcons();
	void createAudio();
	void createMusicIcon();
	std::vector<sf::Texture> m_textures;
	std::vector<sf::Texture> m_iconVec;
	std::vector<sf::SoundBuffer> m_audioVec;

	std::vector<sf::Texture> m_enemyAnime;
	sf::Font m_font;
	std::vector<sf::Texture> m_musicTextureVec;

	int m_enemySerialNumber;
	sf::Clock enemyAnimetionTimer;
};

