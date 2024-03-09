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
 
    if (!this->zero.openFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Audio\\zero.wav"))
        std::cout << "Audio file zero not found!";
    this->zero.setLoop(false);
    this->zero.setVolume(50);

    if (!this->one.openFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Audio\\one.wav"))
        std::cout << "Audio file zero not found!";
    this->one.setLoop(false);
    this->one.setVolume(50);

    if (!this->two.openFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Audio\\two.wav"))
        std::cout << "Audio file zero not found!";
    this->two.setLoop(false);
    this->two.setVolume(50);

    if (!this->three.openFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Audio\\three.wav"))
        std::cout << "Audio file zero not found!";
    this->three.setLoop(false);
    this->three.setVolume(50);

    if (!this->four.openFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Audio\\four.wav"))
        std::cout << "Audio file zero not found!";
    this->four.setLoop(false);
    this->four.setVolume(50);
    
    if (!this->five.openFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Audio\\five.wav"))
        std::cout << "Audio file zero not found!";
    this->five.setLoop(false);
    this->five.setVolume(50);
    
    if (!this->six.openFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Audio\\six.wav"))
        std::cout << "Audio file zero not found!";
    this->six.setLoop(false);
    this->six.setVolume(50);
    
    if (!this->seven.openFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Audio\\seven.wav"))
        std::cout << "Audio file zero not found!";
    this->seven.setLoop(false);
    this->seven.setVolume(50);

    if (!this->eight.openFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Audio\\eight.wav"))
        std::cout << "Audio file zero not found!";
    this->eight.setLoop(false);
    this->eight.setVolume(50);

    if (!this->nine.openFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Audio\\nine.wav"))
        std::cout << "Audio file zero not found!";
    this->nine.setLoop(false);
    this->nine.setVolume(50);


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

        // Play the corresponding sound based on the newDigit value
        switch (newDigit) {
        case 0:
            this->zero.play();
            break;
        case 1:
            this->one.play();
            break;
        case 2:
            this->two.play();
            break;
        case 3:
            this->three.play();
            break;
        case 4:
            this->four.play();
            break;
        case 5:
            this->five.play();
            break;
        case 6:
            this->six.play();
            break;
        case 7:
            this->seven.play();
            break;
        case 8:
            this->eight.play();
            break;
        case 9:
            this->nine.play();
            break;
        }

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
