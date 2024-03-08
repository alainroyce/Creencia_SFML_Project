#include "HomeText.h"
#include <iostream>

HomeText::HomeText(sf::String name) : AGameObject(name)
{
    if (!tex.loadFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Textures\\EnterSong.png")) {
        std::cerr << "Failed to load loading bar texture!" << std::endl;
    }
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(tex);
    this->sprite->setOrigin(tex.getSize().x / 2.f, tex.getSize().y / 2.f);
}

void HomeText::initialize()
{
}

void HomeText::processInput(sf::Event event)
{
}

void HomeText::update(sf::Time deltaTime)
{
}
