#pragma once
#include "AGameObject.h"
#include <SFML/Audio.hpp>
class KaraokeNumber : public AGameObject
{
public:
	KaraokeNumber();
	~KaraokeNumber();
	void initialize() override;
	void processInput(sf::Event event) override;
	void update(sf::Time deltaTime) override;
	void draw(sf::RenderWindow* targetWindow) override;

private:
	sf::Time updateTime;
	sf::Text* statsText;
	int number;
	void updateNumber();

	sf::Music zero;
	sf::Music one;
	sf::Music two;
	sf::Music three;
	sf::Music four;
	sf::Music five;
	sf::Music six;
	sf::Music seven;
	sf::Music eight;
	sf::Music nine;


};

