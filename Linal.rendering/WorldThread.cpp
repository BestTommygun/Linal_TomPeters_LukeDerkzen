#include "pch.h"
#include <iostream>
#include "WorldThread.h"

WorldThread::WorldThread(View^ mainView)
{
	world = new World();
	world->prepareWorld();
	this->mainView = mainView;
	renderer = new Renderer(world->getCamera());
}

WorldThread::~WorldThread()
{
	delete world;
	world = nullptr;

	delete renderer;
	renderer = nullptr;
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
			mainView->ToDrawLines = renderer->calculateFrame(world->getWorldObjects(), mainView->Width, mainView->Height);
			//mainView->lines = renderer.render(world.getWorldObjects());
			System::Threading::Thread::Sleep(10);
		}
		catch(std::exception e) {
			_isRunning = false;
			std::cout << e.what() << std::endl;
			
		}
	}
}

void WorldThread::updateWorld(System::TimeSpan deltaTime)
{
	size_t worldObjectsSize = world->getWorldObjects().size();
	for (size_t i = 0; i < worldObjectsSize; i++) {
		world->getWorldObjects()[i].update(deltaTime.TotalMilliseconds);
	}
}

void WorldThread::handleInputs(System::Char input)
{
	input = System::Char::ToLower(input);
	switch (input)
	{
	case 'w':
		world->moveCamera(Vector3d(0, 0, 0.1));
		break;
	case 'a':
		world->moveCamera(Vector3d(-0.1, 0, 0));
		break;
	case 's':
		world->moveCamera(Vector3d(0, 0, -0.1));
		break;
	case 'd':
		world->moveCamera(Vector3d(0.1, 0, 0));
		break;
	case 'q':
		world->getCamera().rotateAroundY(((-5.0 / 360.0) * 2.0 * PI)); //TODO: looks really weird? investigate
		break;
	case 'e':
		world->getCamera().rotateAroundY(((5.0 / 360.0) * 2.0 * PI)); //TODO: looks really weird? investigate
		break;
	case 't':
		std::cout << "this should enable debug mode which shows us the axis of everything\n";
		break;
	default:
		break;
	}
}
