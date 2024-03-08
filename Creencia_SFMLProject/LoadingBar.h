#pragma once
#include <string>
#include "TextureManager.h"
#include "AGameObject.h"
#include <SFML/Graphics.hpp>

class LoadingBar :public AGameObject
{
public:
	LoadingBar(sf::String name);
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

	sf::RectangleShape loadingBarBackground;
	sf::Texture loadingBarTexture;

	sf::Texture barTex;
	int newWidth;
	int assetCount;
	int TotalAssetCount;
};