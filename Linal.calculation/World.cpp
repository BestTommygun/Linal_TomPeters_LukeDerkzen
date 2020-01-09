#include "World.h"

World::World()
{
	worldObjects = std::vector<GameObject>();
}

World::~World()
{
	delete camera;
}

void World::prepareWorld()
{
	//make objects here
	camera = new Camera(Vector3d(0, 0, 0), 90, 10, 100);
}

void World::moveCamera(Vector3d movement)
{
	camera->moveCamera(movement);
}
