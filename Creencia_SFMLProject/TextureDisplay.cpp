#include "TextureDisplay.h"
#include <iostream>
#include "TextureManager.h"
#include "BaseRunner.h"
#include "GameObjectManager.h"
#include "IconObject.h"
#include "BGObject.h"
#include "FPSCounter.h"

TextureDisplay::TextureDisplay() : AGameObject("TextureDisplay")
{

}

void TextureDisplay::initialize()
{

}

void TextureDisplay::processInput(sf::Event event)
{

}

void TextureDisplay::update(sf::Time deltaTime)
{
	//std::cout << TextureManager::getInstance()->getNumLoadedStreamTextures() << endl;
	this->ticks += BaseRunner::TIME_PER_FRAME.asMilliseconds();

	if (TextureManager::getInstance()->getNumLoadedStreamTextures() == TextureManager::getInstance()->getStreamingAssetCount()) {
		cout << "ALLASSETSLOADED" << endl;
		this->onAllAssetsLoaded();

	}
	if (this->streamingType == StreamingType::BATCH_LOAD && !this->startedStreaming && this->ticks > this->STREAMING_LOAD_DELAY)
	{
		this->startedStreaming = true;
		this->ticks = 0.0f;
		TextureManager::getInstance()->loadStreamingAssets();

		// Check if all assets have been loaded
		
	}
	else if (this->streamingType == StreamingType::SINGLE_STREAM && this->ticks > this->STREAMING_LOAD_DELAY)
	{
		
		this->ticks = 0.0f;
		TextureManager::getInstance()->loadSingleStreamAsset(this->numDisplayed, this);
		this->numDisplayed++;
	}
}

void TextureDisplay::onAllAssetsLoaded()
{
	BGObject* bgobject = dynamic_cast<BGObject*>(GameObjectManager::getInstance()->findObjectByName("BGObject"));
	

	cout << "Displayed" << numDisplay << " / "  << numObjectsToSpawn << endl;
	// Set the time interval between spawning each object
	static const sf::Time SPAWN_INTERVAL = sf::seconds(0.033f);

	// Update the timer
	this->spawnTimer += BaseRunner::TIME_PER_FRAME;
	String name = "Frame";
	name = name + std::to_string(numDisplay);
	// Check if it's time to spawn a new object
	if (this->spawnTimer >= SPAWN_INTERVAL && numDisplay < numObjectsToSpawn) {
		this->spawnObject(name); // Spawn a new object
		numDisplay++; // Increment the count of displayed objects
		this->spawnTimer = sf::Time::Zero; // Reset the spawn timer
	}
	else if (!loadDone)
	{
		bgobject->isPlay = true;
		loadDone = true;

		
	}
	else if (numDisplay == numObjectsToSpawn)
	{
		numDisplay = 0;
		loadDone = false;
		std::cout << "Before: " << GameObjectManager::getInstance()->activeObjects() << std::endl;
		for (int i = 0; i < numObjectsToSpawn; i++)
		{
			String name = "Frame";
			name = name + std::to_string(i);
			GameObjectManager::getInstance()->deleteObjectByName(name);
		}
		std::cout << "After: " << GameObjectManager::getInstance()->activeObjects() << std::endl;
	}

	
}

void TextureDisplay::onFinishedExecution()
{
	//this->spawnObject(); //executes spawn once the texture is ready.
}

void TextureDisplay::spawnObject(String name)
{
	this->guard.lock();

	//String objectName = "Icon_" + to_string(this->iconList.size());
	IconObject* iconObj = new IconObject(name, this->iconList.size());
	this->iconList.push_back(iconObj);

	//set position
	int IMG_WIDTH = 1920; int IMG_HEIGHT = 1080;
	float x = this->columnGrid * IMG_WIDTH;
	float y = this->rowGrid * IMG_HEIGHT;
	iconObj->setPosition(x, y);
	iconObj->setScale(1.0f,1.0f);
	//std::cout << "Set position: " << x << " " << y << std::endl;

	/*
	this->columnGrid++;
	if (this->columnGrid == this->MAX_COLUMN)
	{
		this->columnGrid = 0;
		this->rowGrid++;
	}
	*/
	GameObjectManager::getInstance()->addObject(iconObj);

	this->guard.unlock();
}