#include "StreamAssetLoader.h"
#include <iostream>
#include "TextureManager.h"
#include "StringUtils.h"
#include "IExecutionEvent.h"
#include <random>

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

	std::random_device seed;
	std::mt19937 eng(seed());
	std::uniform_int_distribution<> distr(50, 5000);

	IETThread::sleep(distr(eng));

	std::vector<String> tokens = StringUtils::split(path, '/');
	String name = "Frame" + std::to_string(this->index);
	TextureManager::getInstance()->instantiateAsTexture(path, name, true);

	this->execEvent->onFinishedExecution();
	
	delete this;
}