#pragma once
#include "AGameObject.h"
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
	

};

