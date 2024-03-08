#include "KaraokeNumber.h"
#include "BaseRunner.h"
#include<iostream>

KaraokeNumber::KaraokeNumber() :AGameObject(name)
{
}

KaraokeNumber::~KaraokeNumber()
{
    delete this->statsText->getFont();
    delete this->statsText;
    AGameObject::~AGameObject();
}

void KaraokeNumber::initialize()
{
    sf::Font* font = new sf::Font();
    font->loadFromFile("Media/digital-7.ttf");

    this->statsText = new sf::Text();
    this->statsText->setFont(*font);
    this->statsText->setPosition(BaseRunner::WINDOW_WIDTH/2 - 300.0f, BaseRunner::WINDOW_HEIGHT/2 - 100);
    this->statsText->setOutlineColor(sf::Color(1.0f, 1.0f, 1.0f));
    this->statsText->setOutlineThickness(2.5f);
    this->statsText->setCharacterSize(200);
    updateNumber();
    //this->statsText->setString("0 0 0 0");

}

void KaraokeNumber::processInput(sf::Event event)
{


    if ((event.key.code >= sf::Keyboard::Num0 && event.key.code <= sf::Keyboard::Num9) ||
        (event.key.code >= sf::Keyboard::Numpad0 && event.key.code <= sf::Keyboard::Numpad9)) {

        // Convert key code to number
        int newDigit = (event.key.code >= sf::Keyboard::Num0 && event.key.code <= sf::Keyboard::Num9) ?
            event.key.code - sf::Keyboard::Num0 :
            event.key.code - sf::Keyboard::Numpad0;

        // Shift existing digits to the left
        this->number = (this->number * 10) % 10000;

        // Add the new digit
        this->number += newDigit;

        updateNumber(); // Update the displayed number
        std::cout << "Input: " << number << std::endl;
    }
}

void KaraokeNumber::update(sf::Time deltaTime)
{
    
}

void KaraokeNumber::draw(sf::RenderWindow* targetWindow)
{
    AGameObject::draw(targetWindow);

    if (this->statsText != nullptr)
        targetWindow->draw(*this->statsText);
}

void KaraokeNumber::updateNumber()
{
    // Convert number to string with 4 digits
    std::string numberString = std::to_string(this->number);
    numberString = std::string(4 - numberString.length(), '0') + numberString; // Pad with zeros if necessary

    // Insert spaces between digits
    for (int i = 1; i < numberString.length(); i += 2) {
        numberString.insert(i, " ");
    }

    // Set the displayed number
    this->statsText->setString(numberString);
}
