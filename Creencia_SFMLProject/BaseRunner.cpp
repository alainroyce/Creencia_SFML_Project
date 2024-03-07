#include "BaseRunner.h"
#include  "GameObjectManager.h"
#include "BGObject.h"
#include "TextureManager.h"
#include "TextureDisplay.h"
#include "FPSCounter.h"
#include "LoadingScreen.h"
#include <iostream>

const sf::Time BaseRunner::TIME_PER_FRAME = sf::seconds(1.f / 60.f);

BaseRunner::BaseRunner() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "HO: Entity Component", sf::Style::Close) {
	if (!logoTexture.loadFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Textures\\Jorbs.png")) {

		std::cerr << "Failed to load logo texture!" << std::endl;
	}

	logo.setTexture(logoTexture);
	logo.setScale(0.5f, 0.5f);
	//logo.setOrigin(logoTexture.getSize().x / 2.f, logoTexture.getSize().y / 2.f);
	//logo.setPosition(WINDOW_WIDTH - 50.f, WINDOW_HEIGHT - 50.f);
	TextureManager::getInstance()->loadFromAssetList();
	LoadingScreen* loading = new LoadingScreen("LoadingScreen");
	GameObjectManager::getInstance()->addObject(loading);

	TextureDisplay* display = new TextureDisplay();
	GameObjectManager::getInstance()->addObject(display);

	BGObject* bgObject = new BGObject("BGObject");
	GameObjectManager::getInstance()->addObject(bgObject);

	
	


	
	
	FPSCounter* fpsCounter = new FPSCounter();
	GameObjectManager::getInstance()->addObject(fpsCounter);

	
	velocity.x = 100.0f;
	velocity.y = 100.0f;
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
	
	
	// Update logo position
	logo.move(velocity * elapsedTime.asSeconds());

	// Check for bounds collision and reverse velocity if needed
	if ((logo.getPosition().x + logo.getGlobalBounds().width >= WINDOW_WIDTH && velocity.x > 0) ||
		(logo.getPosition().x <= 0 && velocity.x < 0)) {
		velocity.x = -velocity.x; // Reverse X direction
	}
	if ((logo.getPosition().y + logo.getGlobalBounds().height >= WINDOW_HEIGHT && velocity.y > 0) ||
		(logo.getPosition().y <= 0 && velocity.y < 0)) {
		velocity.y = -velocity.y; // Reverse Y direction
	}
	
}

void BaseRunner::render() {
	this->window.clear();
	GameObjectManager::getInstance()->draw(&this->window);

	// Draw CD sprite
	window.draw(logo);

	this->window.display();
}
