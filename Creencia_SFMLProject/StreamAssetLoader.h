#pragma once
#include "IETThread.h"
#include "IWorkerAction.h"

class TextureDisplay;
class StreamAssetLoader : public IWorkerAction
{
private:
	typedef std::string String;
public:
	StreamAssetLoader(String path, TextureDisplay* texDisplay);
	~StreamAssetLoader();

private:
	void onStartTask() override;

	String path;
	TextureDisplay* texDisplay;
};

