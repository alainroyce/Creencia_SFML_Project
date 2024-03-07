#pragma once
#include <string>
#include "TextureManager.h"
#include "AGameObject.h"
#include <SFML/Graphics.hpp>

class LoadingScreen :public AGameObject
{
public:
	LoadingScreen(sf::String name);
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

	sf::Sprite cdSprite;
	sf::Texture cdTexture;

};