#pragma once
#include "IETThread.h"

class TextureDisplay;
class StreamAssetLoader : public IETThread
{
private:
	typedef std::string String;
public:
	StreamAssetLoader(String path, TextureDisplay* texDisplay);
	~StreamAssetLoader();

private:
	void run() override;

	String path;
	TextureDisplay* texDisplay;
};

