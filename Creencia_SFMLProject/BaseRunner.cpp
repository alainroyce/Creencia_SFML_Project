#include "BaseRunner.h"
#include  "GameObjectManager.h"
#include "BGObject.h"
#include "TextureManager.h"
#include "TextureDisplay.h"
#include "FPSCounter.h"
#include "LoadingScreen.h"
#include "LoadingBar.h"
#include"BouncingDVD.h"
#include "KaraokeNumber.h"
#include "HomeText.h"
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
	loading->setPosition(BaseRunner::WINDOW_WIDTH - 100.f, BaseRunner::WINDOW_HEIGHT - 100.f);
	loading->setScale(0.5, 0.5);
	GameObjectManager::getInstance()->addObject(loading);
	
	/*
	BouncingDVD* dvd = new BouncingDVD("BouncingLogo");
	dvd->setScale(0.5, 0.5);
	GameObjectManager::getInstance()->addObject(dvd);
	*/
	LoadingBar* loadingbar = new LoadingBar("LoadingBar");
	loadingbar->setPosition(BaseRunner::WINDOW_WIDTH/2, BaseRunner::WINDOW_HEIGHT -50.0f);
	GameObjectManager::getInstance()->addObject(loadingbar);
	
	HomeText* hometext = new HomeText("HomeText");
	hometext->setPosition(BaseRunner::WINDOW_WIDTH / 2, BaseRunner::WINDOW_HEIGHT / 2 - 200);
	GameObjectManager::getInstance()->addObject(hometext);

	if (!logoTexture.loadFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Textures\\Jorbs.png")) {

		std::cerr << "Failed to load logo texture!" << std::endl;
	}

	logo.setTexture(logoTexture);
	logo.setScale(currentScale, currentScale);

	velocity.x = 100.0f;
	velocity.y = 100.0f;
	

	
	FPSCounter* fpsCounter = new FPSCounter();
	GameObjectManager::getInstance()->addObject(fpsCounter);

	KaraokeNumber* number = new KaraokeNumber();
	GameObjectManager::getInstance()->addObject(number);

	
	
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
	while (this->window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyPressed:
			// Check if the pressed key is a number key from numpad
			if (event.key.code >= sf::Keyboard::Numpad0 && event.key.code <= sf::Keyboard::Numpad9) {
				// Convert the key code to actual number
				int number = event.key.code - sf::Keyboard::Numpad0;
				//std::cout << "Pressed number: " << number << std::endl;
				// Update display value
				//updateDisplay(number);
			}
			break;
		case sf::Event::Closed:
			this->window.close();
			break;
		default:
			GameObjectManager::getInstance()->processInput(event);
			break;
		}
	}
}

void BaseRunner::update(sf::Time elapsedTime) {
	
	
	GameObjectManager::getInstance()->update(elapsedTime);	
	
	

	
	if (TextureManager::getInstance()->getNumLoadedStreamTextures() != TextureManager::getInstance()->getStreamingAssetCount() && TextureManager::getInstance()->getNumLoadedStreamTextures() >= 1680 && TextureManager::getInstance()->getNumLoadedStreamTextures() < 1850) {
		currentScale += elapsedTime.asSeconds() / 1.5;
		logo.setScale(currentScale,currentScale);
		logo.setOrigin(logoTexture.getSize().x / 2.f, logoTexture.getSize().y / 2.f);
		logo.setPosition(BaseRunner::WINDOW_WIDTH / 2, BaseRunner::WINDOW_HEIGHT / 2);
	}
	else if (TextureManager::getInstance()->getNumLoadedStreamTextures() != TextureManager::getInstance()->getStreamingAssetCount() && TextureManager::getInstance()->getNumLoadedStreamTextures() >= 1850)
	{

		AGameObject* bgObject = GameObjectManager::getInstance()->findObjectByName("BGObject");
		AGameObject* disc = GameObjectManager::getInstance()->findObjectByName("LoadingScreen");
		AGameObject* bar = GameObjectManager::getInstance()->findObjectByName("LoadingBar");

		AGameObject* home = GameObjectManager::getInstance()->findObjectByName("HomeText");



		if (bgObject != nullptr || disc != nullptr || bar != nullptr) {
			bgObject->setScale(0.0f, 0.0f);
			disc->setScale(0.0f, 0.0f);
			bar->setScale(0.0f, 0.0f);
		
			home->setScale(0.0f, 0.0f);
		}

		currentScale -= elapsedTime.asSeconds()/2 ;
		logo.setScale(currentScale, currentScale);
		logo.setOrigin(logoTexture.getSize().x / 2.f, logoTexture.getSize().y / 2.f);
		logo.setPosition(BaseRunner::WINDOW_WIDTH / 2, BaseRunner::WINDOW_HEIGHT / 2);

	}
	else {

		logo.move(velocity * elapsedTime.asSeconds());
	}
	


	if ((logo.getPosition().x + logo.getGlobalBounds().width >= WINDOW_WIDTH && velocity.x > 0) ||
		(logo.getPosition().x <= 0 && velocity.x < 0)) {
		velocity.x = -velocity.x; 
	}
	if ((logo.getPosition().y + logo.getGlobalBounds().height >= WINDOW_HEIGHT && velocity.y > 0) ||
		(logo.getPosition().y <= 0 && velocity.y < 0)) {
		velocity.y = -velocity.y; 
	}

	if (TextureManager::getInstance()->getNumLoadedStreamTextures() == TextureManager::getInstance()->getStreamingAssetCount()) {
	
		
		
	}
	
	
}

void BaseRunner::render() {
	this->window.clear();
	GameObjectManager::getInstance()->draw(&this->window);

	if (TextureManager::getInstance()->getNumLoadedStreamTextures() != TextureManager::getInstance()->getStreamingAssetCount()) {
		window.draw(logo);

	}

	
	
	
	window.draw(cdSprite);

	
	

	this->window.display();
}


