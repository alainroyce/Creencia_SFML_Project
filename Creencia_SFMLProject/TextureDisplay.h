#pragma once
#include "AGameObject.h"
#include "IExecutionEvent.h"
#include <mutex>
#include <semaphore>
#include <SFML/Audio.hpp>

class IconObject;
/// <summary>
/// Class that deals with displaying of streamed textures
/// </summary>
class TextureDisplay : public AGameObject, public IExecutionEvent
{
public:
	TextureDisplay();
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
	void onAllAssetsLoaded();
	void onFinishedExecution() override;

private:
	typedef std::vector<IconObject*> IconList;
	typedef std::mutex Mutex;
	IconList iconList;
	int numObjectsToSpawn = 1543;
	enum StreamingType { BATCH_LOAD = 0, SINGLE_STREAM = 1 };
	const float STREAMING_LOAD_DELAY = 25.0f; //greatly reduce streaming load delay to demonstrate performance drop.
	const StreamingType streamingType = SINGLE_STREAM;
	float ticks = 0;
	float ticksPerFrame = 33.33f;
	sf::Music music;
	bool startedStreaming = false;
	int numDisplay = 0;
	int columnGrid = 0; int rowGrid = 0;
	int numDisplayed = 0;
	const int MAX_COLUMN = 28;
	const int MAX_ROW = 22;
	sf::Time spawnTimer;
	Mutex guard; //used to avoid possible race conditions when spawning objects. Not really required for this exercise. Will be explained in future lessons.
	void spawnObject(String name);

	bool loadDone = false;
};