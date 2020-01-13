#include "pch.h"
#include <iostream>
#include "WorldThread.h"

void WorldThread::checkCollisions()
{
	std::vector<std::unique_ptr<Object3d>>& worldObjectsCopy = world->getWorldObjects();
	size_t worldObjectsSize = worldObjectsCopy.size();
	for (size_t i = 0; i < worldObjectsSize; i++) { // if performance becomes an issue this should be replaced with a call each object in Update();
		auto& curObjectI = worldObjectsCopy[i];

		for (size_t j = i + 1; j < worldObjectsSize; j++) {
			auto& curObjectJ = worldObjectsCopy[j];

			if (i != j) {
				auto& hitbox = curObjectJ->getBoundingBox().getPoints();
				if (curObjectI->intersects(hitbox.first, hitbox.second)) {
					//since we know these objects have a chance of intersecting we now send them to the (expensive/slow) collision check
					
					if (curObjectI->getMesh().checkCollisionDetailed(*curObjectI.get(), *curObjectJ.get())) {
						//detailed collision has registered an hit
						curObjectI->markForDestruction();
						curObjectJ->markForDestruction();
					}
				}
			}
		}
	}
}

void WorldThread::lose()
{
	System::Console::WriteLine("Thanks for playing this demo!");
	mainView->HasLost = true;
}

void WorldThread::win()
{
	System::Console::WriteLine("Thanks for playing this demo!");
	mainView->HasWon = true;
}

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
	mainView->HasLost = false;
	mainView->HasWon = false;

	System::TimeSpan deltaTime = System::TimeSpan::Zero;


	while (_isRunning) {
		try {
			//handle inputs
			if(mainView->KeysPressed->Count > 0)
				handleInputs(mainView->KeysPressed->Dequeue());

			//run behaviours and collisions
			updateWorld(deltaTime);

			//refresh view
			mainView->ToDrawLines = renderer->calculateFrame(world->getWorldObjects(), mainView->Width, mainView->Height);

			System::Threading::Thread::Sleep(10);
		}
		catch (std::exception e) {
			_isRunning = false;
			std::cout << e.what() << std::endl;

		}
	}
}

void WorldThread::updateWorld(System::TimeSpan deltaTime)
{
	for (size_t i = 0; i < world->getWorldObjects().size(); i++) {
		if (world->getWorldObjects()[i]->getShouldDestroy()) {
			if (world->getWorldObjects().data()[i]->getIsPlayer()) {
				this->lose();
			}
			else if (world->getWorldObjects().data()[i]->getIsTarget()) {
				this->win();
			}
			world->getWorldObjects().erase(world->getWorldObjects().begin() + i);
		}
		else
			world->getWorldObjects()[i]->update(deltaTime.TotalMilliseconds);
	}
	checkCollisions();
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
	case 'c':
		world->moveCamera(world->getCamera().getMatrix().getUpDirection() * 0.1);
		break;
	case 'v':
		world->moveCamera(world->getCamera().getMatrix().getDownDirection() * 0.1);
		break;
	case 'q':
		world->getCamera().rotateAroundY(((-1.0 / 360.0) * 2.0 * PI));
		break;
	case 'e':
		world->getCamera().rotateAroundY(((1.0 / 360.0) * 2.0 * PI)); 
		break;
	case 'r':
		world->getCamera().rotateAroundX(((-1.0 / 360.0) * 2.0 * PI));
		break;
	case 'f':
		world->getCamera().rotateAroundX(((1.0 / 360.0) * 2.0 * PI));
		break;
	case 'i':
		if(world->getPlayerObject() != nullptr)
			world->getPlayerObject()->get()->move(world->getPlayerObject()->get()->getPosition().getFrontDirection() * 0.1);
		break;
	case 'j':
		if (world->getPlayerObject() != nullptr)
			world->getPlayerObject()->get()->move(world->getPlayerObject()->get()->getPosition().getLeftDirection() * 0.1);
		break;
	case 'k':
		if (world->getPlayerObject() != nullptr)
			world->getPlayerObject()->get()->move(world->getPlayerObject()->get()->getPosition().getBackDirection() * 0.1);
		break;
	case 'l':
		if (world->getPlayerObject() != nullptr)
			world->getPlayerObject()->get()->move(world->getPlayerObject()->get()->getPosition().getRightDirection() * 0.1);
		break;
	case ',':
		if (world->getPlayerObject() != nullptr)
			world->getPlayerObject()->get()->move(world->getPlayerObject()->get()->getPosition().getDownDirection() * 0.1);
		break;
	case '.':
		if (world->getPlayerObject() != nullptr)
			world->getPlayerObject()->get()->move(Matrix3d(world->getPlayerObject()->get()->getPosition().getUpDirection() * 0.1));
		break;
	case 'u':
		if (world->getPlayerObject() != nullptr)
			world->getPlayerObject()->get()->rotateAroundY(((-2.5 / 360.0) * 2.0 * PI));
		break;
	case 'o':
		if (world->getPlayerObject() != nullptr)
			world->getPlayerObject()->get()->rotateAroundY(((2.5 / 360.0) * 2.0 * PI));
		break;
	case 'p':
		if (world->getPlayerObject() != nullptr)
			world->getPlayerObject()->get()->rotateAroundX(((-2.5 / 360.0) * 2.0 * PI));
		break;
	case ';':
		if (world->getPlayerObject() != nullptr)
			world->getPlayerObject()->get()->rotateAroundX(((2.5 / 360.0) * 2.0 * PI));
		break;
	case 'n':
		if (world->getPlayerObject() != nullptr)
			world->getPlayerObject()->get()->rotateAroundZ(((-2.5 / 360.0) * 2.0 * PI));
		break;
	case 'm':
		if (world->getPlayerObject() != nullptr)
			world->getPlayerObject()->get()->rotateAroundZ(((2.5 / 360.0) * 2.0 * PI));
		break;
	case ' ':
		if (world->getPlayerObject() != nullptr)
			world->addWorldObject(std::move(world->getPlayerObject()->get()->getPrefab()));
		break;
	case 't':
		std::cout << "this should enable debug mode which shows us the axis of everything\n";
		break;
	default:
		break;
	}
}
