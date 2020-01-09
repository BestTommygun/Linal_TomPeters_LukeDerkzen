#include "pch.h"
#include "WorldThread.h"

WorldThread::WorldThread(View^ mainView)
{
	world = new World();
	this->mainView = mainView;
}

WorldThread::~WorldThread()
{
	delete world;
	world = nullptr;
}

void WorldThread::run() {
	bool _isRunning = true;

	while (_isRunning) {
		try {
			//handle inputs

			//do calc stuff

			//gib render

		}
		finally {
			_isRunning = false;
		}
	}
}

void WorldThread::handleInputs(System::Char input)
{

	switch (input)
	{
	case 'w':

		break;
	default:
		break;
	}
}

