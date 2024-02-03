#include "StreamAssetLoader.h"
#include <iostream>
#include <random>

#include "TextureManager.h"
#include "StringUtils.h"
#include "TextureDisplay.h"

StreamAssetLoader::StreamAssetLoader(String path, TextureDisplay* texDisplay)
{
	this->path = path;
	this->texDisplay = texDisplay;
}

StreamAssetLoader::~StreamAssetLoader()
{
	std::cout << "Destroying stream asset loader. " << std::endl;
}

void StreamAssetLoader::run()
{
	std::cout << "Running stream asset loader " << std::endl;
	//simulate loading of very large file
	std::random_device seeder;
	std::mt19937 engine(seeder());
	std::uniform_int_distribution<int> dist(1000, 4000);
	IETThread::sleep(dist(engine));

	std::vector<String> tokens = StringUtils::split(path, '/');
	String assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];

	TextureManager::getInstance()->instantiateAsTexture(path, assetName, true);
	texDisplay->spawnObject();
	std::cout << "[TextureManager] Loaded streaming texture: " << assetName << std::endl;


	//delete after being done
	delete this;
}
