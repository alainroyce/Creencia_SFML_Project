#include "LoadingScreen.h"
#include "TextureManager.h"
#include "BaseRunner.h"
#include <iostream>

LoadingScreen::LoadingScreen(sf::String name) :AGameObject(name)
{
}

void LoadingScreen::initialize()
{
	if (!cdTexture.loadFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Textures\\cd.png")) {

		std::cerr << "Failed to load CD texture!" << std::endl;
	}
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(cdTexture);
	this->sprite->setScale(0.5f, 0.5f);
	this->sprite->setOrigin(cdTexture.getSize().x / 2.f, cdTexture.getSize().y / 2.f);


}

void LoadingScreen::processInput(sf::Event event)
{
    // Process input if needed
}

void LoadingScreen::update(sf::Time deltaTime)
{
	// Update CD rotation (spinning effect)
	this->sprite->rotate(100.f * deltaTime.asSeconds());

}