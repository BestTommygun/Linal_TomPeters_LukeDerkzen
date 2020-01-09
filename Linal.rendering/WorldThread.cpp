#include "pch.h"
#include <iostream>
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
	System::TimeSpan deltaTime = System::TimeSpan::Zero;


	while (_isRunning) {
		try {
			//handle inputs
			if(mainView->KeysPressed->Count > 0)
				handleInputs(mainView->KeysPressed->Dequeue());

			//do calc stuff
			updateWorld(deltaTime);

			//gib render
			
		}
		catch(std::exception e) {
			_isRunning = false;
			std::cout << e.what() << std::endl;
			
		}
	}
}

void WorldThread::updateWorld(System::TimeSpan deltaTime)
{
	std::cout << "world is empty" << '\n';
}

void WorldThread::handleInputs(System::Char input)
{
	input = System::Char::ToLower(input);
	switch (input)
	{
	case 'w':
		world->moveCamera(Vector3d(0, 0, 1));
		break;
	case 'a':
		world->moveCamera(Vector3d(-1, 0, 0));
		break;
	case 's':
		world->moveCamera(Vector3d(0, 0, -1));
		break;
	case 'd':
		world->moveCamera(Vector3d(1, 0, 0));
		break;
	default:
		break;
	}
}

