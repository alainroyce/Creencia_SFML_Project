#pragma once
#include "IETThread.h"
class IExecutionEvent;
class StreamAssetLoader : public IETThread
{
private:
	typedef std::string String;
public:
	StreamAssetLoader(String path, IExecutionEvent* executionEvent, int index);
	~StreamAssetLoader();

private:
	void run() override;
	int index;
	String path;
	IExecutionEvent* execEvent;
};