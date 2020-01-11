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
		if (world->getWorldObjects()[i]->getShouldDestroy()) {
			world->getWorldObjects().pop_back(); //if needed the to be deleted object can be accessed here
		}
		else
			world->getWorldObjects()[i]->update(deltaTime.TotalMilliseconds);
	}
}

void WorldThread::handleInputs(System::Char input)
{
	input = System::Char::ToLower(input);
	switch (input)
	{
	case 'w':
		world->moveCamera(world->getCamera().getMatrix().getFrontDirection() * 0.1);
		break;
	case 'a':
		world->moveCamera(world->getCamera().getMatrix().getLeftDirection() * 0.1);
		break;
	case 's':
		world->moveCamera(world->getCamera().getMatrix().getBackDirection() * 0.1);
		break;
	case 'd':
		world->moveCamera(world->getCamera().getMatrix().getRightDirection() * 0.1);
		break;
	case 'q':
		world->getCamera().rotateAroundY(((-5.0 / 360.0) * 2.0 * PI)); //TODO: looks really weird? investigate
		break;
	case 'e':
		world->getCamera().rotateAroundY(((5.0 / 360.0) * 2.0 * PI)); //TODO: looks really weird? investigate
		break;
	case 'i':
		world->getPlayerObject()->get()->move(Matrix3d(world->getPlayerObject()->get()->getPosition().getFrontDirection() * 0.1));
		break;
	case 'j':
		world->getPlayerObject()->get()->move(Matrix3d(world->getPlayerObject()->get()->getPosition().getLeftDirection() * 0.1));
		break;
	case 'k':
		world->getPlayerObject()->get()->move(Matrix3d(world->getPlayerObject()->get()->getPosition().getBackDirection() * 0.1));
		break;
	case 'l':
		world->getPlayerObject()->get()->move(Matrix3d(world->getPlayerObject()->get()->getPosition().getRightDirection() * 0.1));
		break;
	case 'u':
		world->getPlayerObject()->get()->rotateAroundY(((-5.0 / 360.0) * 2.0 * PI));
		break;
	case 'o':
		world->getPlayerObject()->get()->rotateAroundY(((5.0 / 360.0) * 2.0 * PI));
		break;
	case ' ':
		world->setWorldObject(std::move(world->getPlayerObject()->get()->getPrefab()));
		break;
	case 't':
		std::cout << "this should enable debug mode which shows us the axis of everything\n";
		break;
	default:
		break;
	}
}
