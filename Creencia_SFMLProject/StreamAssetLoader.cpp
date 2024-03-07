#include "StreamAssetLoader.h"
#include <iostream>
#include "TextureManager.h"
#include "StringUtils.h"
#include "IExecutionEvent.h"

StreamAssetLoader::StreamAssetLoader(String path, IExecutionEvent* executionEvent, int index)
{
	this->path = path;
	this->execEvent = executionEvent;
	this->index = index;
}

StreamAssetLoader::~StreamAssetLoader()
{
	//std::cout << "Destroying stream asset loader. " << std::endl;
}

void StreamAssetLoader::run()
{
	//std::cout << "Running stream asset loader " << std::endl;
	//simulate loading of very large file
	IETThread::sleep(1000);

	std::vector<String> tokens = StringUtils::split(path, '/');
	//String assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
	String name = "Frame" + std::to_string(this->index);
	TextureManager::getInstance()->instantiateAsTexture(path, name, true);
	
	//std::cout << "[TextureManager] Loaded streaming texture: " << name << std::endl;

	this->execEvent->onFinishedExecution();
	//delete after being done
	delete this;
}