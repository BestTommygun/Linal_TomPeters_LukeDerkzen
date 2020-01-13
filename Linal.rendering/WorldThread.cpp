#include "pch.h"
#include <iostream>
#include "WorldThread.h"

void WorldThread::checkCollisions()
{
	std::vector<std::unique_ptr<Object3d>>& worldObjectsCopy = world->getWorldObjects();
	size_t worldObjectsSize = worldObjectsCopy.size();
	for (size_t i = 0; i < worldObjectsSize; i++) { // if performance becomes an issue this should be replaced with a call each object in Update();
		auto& curObjectI = worldObjectsCopy[i];

		if (!curObjectI->getShouldDestroy()) {
			for (size_t j = i + 1; j < worldObjectsSize; j++) {
				auto& curObjectJ = worldObjectsCopy[j];

				if (i != j && !curObjectJ->getShouldDestroy()) {
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
	auto test = 0;

	for (size_t i = 0; i < worldObjectsSize; i++) {
		if (worldObjectsCopy[i]->getShouldDestroy()) {
			test++;
		}
	}
	auto tes23423423w = "";
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

			//do calc stuff
			updateWorld(deltaTime);

			//gib render
			mainView->ToDrawLines = renderer->calculateFrame(world->getWorldObjects(), mainView->Width, mainView->Height);

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
	for (size_t i = 0; i < world->getWorldObjects().size(); i++) {
		if (world->getWorldObjects()[i]->getShouldDestroy()) {
			if (world->getWorldObjects().data()[i]->getIsPlayer()) {
				this->lose();
			}
			world->getWorldObjects().erase(world->getWorldObjects().begin() + i);//if needed the to be deleted object can be accessed here
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
	case 'p':
		world->getPlayerObject()->get()->rotateAroundX(((-5.0 / 360.0) * 2.0 * PI));
		break;
	case ';':
		world->getPlayerObject()->get()->rotateAroundX(((5.0 / 360.0) * 2.0 * PI));
		break;
	case ' ':
		world->addWorldObject(std::move(world->getPlayerObject()->get()->getPrefab())); //TODO: shooting follows camera movement somehow
		break;
	case 't':
		std::cout << "this should enable debug mode which shows us the axis of everything\n";
		break;
	default:
		break;
	}
}
