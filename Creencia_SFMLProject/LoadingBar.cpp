#include "LoadingBar.h"
#include <iostream>
LoadingBar::LoadingBar(sf::String name) :AGameObject(name)
{
    if (!loadingBarTexture.loadFromFile("C:\\Users\\alain\\source\\repos\\Creencia_SFMLProject\\Creencia_SFMLProject\\Media\\Textures\\Loadingbar.png")) {
        std::cerr << "Failed to load loading bar texture!" << std::endl;
    }
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(loadingBarTexture);
    this->sprite->setTextureRect(sf::IntRect(0, 0, newWidth, loadingBarTexture.getSize().y));
    this->sprite->setOrigin(loadingBarTexture.getSize().x / 2.f, loadingBarTexture.getSize().y / 2.f);
}

void LoadingBar::initialize()
{
   

}

void LoadingBar::processInput(sf::Event event)
{
}

void LoadingBar::update(sf::Time deltaTime)
{
    assetCount = TextureManager::getInstance()->getNumLoadedStreamTextures();
    TotalAssetCount = TextureManager::getInstance()->getStreamingAssetCount();
    float progress = 0.0f; // Default to 0 if TotalAssetCount is 0 to avoid division by zero
    if (TotalAssetCount > 0) {
        progress = static_cast<float>(assetCount) / static_cast<float>(TotalAssetCount);
    }

    int newWidth = static_cast<int>(progress * loadingBarTexture.getSize().x);

    // Update the texture rectangle to reflect current progress
    this->sprite->setTextureRect(sf::IntRect(0, 0, newWidth, loadingBarTexture.getSize().y));
}


