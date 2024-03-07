#include "BaseRunner.h"
#include  "GameObjectManager.h"
#include "BGObject.h"
#include "TextureManager.h"
#include "TextureDisplay.h"
#include "FPSCounter.h"
#include "LoadingScreen.h"
#include"BouncingDVD.h"
#include <iostream>

const sf::Time BaseRunner::TIME_PER_FRAME = sf::seconds(1.f / 60.f);

BaseRunner::BaseRunner() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "HO: Entity Component", sf::Style::Close) {




	TextureManager::getInstance()->loadFromAssetList();


	TextureDisplay* display = new TextureDisplay();
	GameObjectManager::getInstance()->addObject(display);

	BGObject* bgObject = new BGObject("BGObject");
	GameObjectManager::getInstance()->addObject(bgObject);

	LoadingScreen* loading = new LoadingScreen("LoadingScreen");
	loading->setPosition(BaseRunner::WINDOW_WIDTH - 1820.f, BaseRunner::WINDOW_HEIGHT - 100.f);
	loading->setScale(0.5, 0.5);
	GameObjectManager::getInstance()->addObject(loading);
	
	BouncingDVD* dvd = new BouncingDVD("BouncingLogo");
	dvd->setScale(0.5, 0.5);
	GameObjectManager::getInstance()->addObject(dvd);

	
	/*if (!logoTexture.loadFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Textures\\Jorbs.png")) {

		std::cerr << "Failed to load logo texture!" << std::endl;
	}

	logo.setTexture(logoTexture);
	logo.setScale(0.5f, 0.5f);
	velocity.x = 100.0f;
	velocity.y = 100.0f;
	*/



	FPSCounter* fpsCounter = new FPSCounter();
	GameObjectManager::getInstance()->addObject(fpsCounter);

}

void BaseRunner::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (this->window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			timeSinceLastUpdate -= TIME_PER_FRAME;

			processEvents();
			update(elapsedTime);
		}

		render();

		window.setFramerateLimit(60);
	}
}

void BaseRunner::processEvents()
{
	sf::Event event;
	if (this->window.pollEvent(event)) {
		switch (event.type) {
		default:
			GameObjectManager::getInstance()->processInput(event);
			break;
		case sf::Event::Closed:
			this->window.close();
			break;
		}
	}
}

void BaseRunner::update(sf::Time elapsedTime) {
	GameObjectManager::getInstance()->update(elapsedTime);
	

	
	
}

void BaseRunner::render() {
	this->window.clear();
	GameObjectManager::getInstance()->draw(&this->window);

	// Draw CD sprite
	window.draw(logo);
	window.draw(cdSprite);


	this->window.display();
}
