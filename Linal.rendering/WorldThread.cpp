#include "pch.h"
#include <iostream>
#include "WorldThread.h"

WorldThread::WorldThread(View^ mainView)
{
	world = new World();
	world->prepareWorld();
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
			System::Collections::Generic::List<RenderLine>^ test2 = meshToLines();
			mainView->ToDrawLines = test2;
			//mainView->lines = renderer.render(world.getWorldObjects());
		}
		catch(std::exception e) {
			_isRunning = false;
			std::cout << e.what() << std::endl;
			
		}
	}
}

void WorldThread::updateWorld(System::TimeSpan deltaTime)
{
	size_t worldObjectSize = world->getWorldObjects().size();
	if (worldObjectSize > 0) {
		std::cout << "world contains ";
		std::cout << worldObjectSize;
		std::cout << " objects\n";
	}
	else
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
	case 't':
		std::cout << "this should enable debug mode which shows us the axis of everything\n";
		break;
	default:
		break;
	}
}

System::Collections::Generic::List<RenderLine>^ WorldThread::meshToLines()
{
	//TEST CODE
	//build mesh vector
	auto curObject = world->getWorldObjects()[0];
	std::vector<size_t> triangles = curObject.getMesh().getTriangleAt(0);

	System::Collections::Generic::List<RenderLine>^ returnLines = gcnew System::Collections::Generic::List<RenderLine>();

	//drawing of triangle lines
	System::Drawing::PointF point1 = System::Drawing::PointF(curObject.getMesh().vertexes->at(triangles[0]).x, curObject.getMesh().vertexes->at(triangles[0]).y);
	System::Drawing::PointF point2 = System::Drawing::PointF(curObject.getMesh().vertexes->at(triangles[1]).x, curObject.getMesh().vertexes->at(triangles[1]).y);
	System::Drawing::PointF point3 = System::Drawing::PointF(curObject.getMesh().vertexes->at(triangles[2]).x, curObject.getMesh().vertexes->at(triangles[2]).y);
	returnLines->Add(RenderLine(point1, point2));
	returnLines->Add(RenderLine(point1, point3));
	returnLines->Add(RenderLine(point2, point3));

	return returnLines;
}
