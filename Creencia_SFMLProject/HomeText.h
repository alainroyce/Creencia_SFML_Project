#pragma once
#include <string>
#include "TextureManager.h"
#include "AGameObject.h"
#include <SFML/Graphics.hpp>

class HomeText :public AGameObject
{
public:
	HomeText(sf::String name);
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);


	sf::Texture tex;

};