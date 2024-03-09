#include "FPSCounter.h"
#include <iostream>
#include "BaseRunner.h"
#include <sstream> 
#include <iomanip>

FPSCounter::FPSCounter() : AGameObject("FPSCounter")
{
}

FPSCounter::~FPSCounter()
{
    delete this->statsText->getFont();
    delete this->statsText;
    AGameObject::~AGameObject();
}

void FPSCounter::initialize()
{
    sf::Font* font = new sf::Font();
    font->loadFromFile("Media/Sansation.ttf");

    this->statsText = new sf::Text();
    this->statsText->setFont(*font);
    this->statsText->setPosition(BaseRunner::WINDOW_WIDTH - 180, BaseRunner::WINDOW_HEIGHT - 50);
    this->statsText->setOutlineColor(sf::Color(1.0f, 1.0f, 1.0f));
    this->statsText->setOutlineThickness(2.5f);
    this->statsText->setCharacterSize(35);
}

void FPSCounter::processInput(sf::Event event)
{
}

void FPSCounter::update(sf::Time deltaTime)
{
    this->updateFPS(deltaTime);
}

void FPSCounter::draw(sf::RenderWindow* targetWindow)
{
    AGameObject::draw(targetWindow);

    if (this->statsText != nullptr)
        targetWindow->draw(*this->statsText);
}

void FPSCounter::updateFPS(sf::Time elapsedTime)
{
    std::stringstream fpsStream;
    // Assuming you want to show two decimal places for the FPS value
    fpsStream << std::fixed << std::setprecision(0) << "FPS: " << (1.0 / elapsedTime.asSeconds());
    this->statsText->setString(fpsStream.str() + "\n");
}

