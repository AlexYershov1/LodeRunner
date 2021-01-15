#pragma once
#include <SFML/Graphics.hpp>
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
	sf::Font* getFont();
private:
	TextureHolder();
	TextureHolder(const TextureHolder&) = default;
	TextureHolder& operator=(const TextureHolder&) = default;

	void setImagesForObj();
	void createSwitchingIcons();
	void createEnemySwitchingIcons();
	std::vector<sf::Texture> m_textures;
	std::vector<sf::Texture> m_iconVec;

	std::vector<sf::Texture> m_enemyAnime;
	sf::Font m_font;

	int m_enemySerialNumber;
	sf::Clock enemyAnimetionTimer;
};

