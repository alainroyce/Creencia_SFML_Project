#include "BouncingDVD.h"

BouncingDVD::BouncingDVD(sf::String name) : AGameObject(name)
{
}

void BouncingDVD::initialize()
{
	if (!logoTexture.loadFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Textures\\Jorbs.png")) {

		std::cout << "Failed to load logo texture!" << std::endl;
	}
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(logoTexture);
	this->sprite->setPosition(100, 100);
	velocity.x = 100.0f;
	velocity.y = 100.0f;
}

void BouncingDVD::processInput(sf::Event event)
{
}

void BouncingDVD::update(sf::Time elapsedTime)
{
	// Update logo position
	this->sprite->move(velocity * elapsedTime.asSeconds());

	// Check for bounds collision and reverse velocity if needed
	if ((sprite->getPosition().x + sprite->getGlobalBounds().width >= 1920 && velocity.x > 0) ||
		(sprite->getPosition().x <= 0 && velocity.x < 0)) {
		velocity.x = -velocity.x; // Reverse X direction
	}
	if ((sprite->getPosition().y + sprite->getGlobalBounds().height >= 1080 && velocity.y > 0) ||
		(sprite->getPosition().y <= 0 && velocity.y < 0)) {
		velocity.y = -velocity.y; // Reverse Y direction
	}
}
