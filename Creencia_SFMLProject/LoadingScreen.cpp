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

	cdSprite.setTexture(cdTexture);
	cdSprite.setScale(0.5f, 0.5f);
	cdSprite.setOrigin(cdTexture.getSize().x / 2.f, cdTexture.getSize().y / 2.f);
	cdSprite.setPosition(BaseRunner::WINDOW_WIDTH - 100.f,BaseRunner:: WINDOW_HEIGHT - 100.f);
}

void LoadingScreen::processInput(sf::Event event)
{
    // Process input if needed
}

void LoadingScreen::update(sf::Time deltaTime)
{
	// Update CD rotation (spinning effect)
	cdSprite.rotate(100.f * deltaTime.asSeconds());

}