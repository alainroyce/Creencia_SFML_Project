#pragma once
#include <string>
#include "TextureManager.h"
#include "AGameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class BouncingDVD :public AGameObject
{
public:
	BouncingDVD(sf::String name);
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
	sf::Texture logoTexture;
	sf::Vector2f velocity;
	
};