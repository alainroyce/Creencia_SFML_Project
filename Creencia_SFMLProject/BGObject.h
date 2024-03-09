#pragma once
#include "AGameObject.h"
#include <SFML/Audio.hpp>

class BGObject : public AGameObject
{
public:
	BGObject(String name);
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
	bool isPlay = false;
private:
	const float SPEED_MULTIPLIER = 3000.0f;
	sf::Music music;
	sf::Music music2;

	
};

