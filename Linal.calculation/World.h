#pragma once
#include <vector>
#include "Camera.h"
#include "GameObject.h"

class World
{
protected:
	std::vector<GameObject> worldObjects;
	Camera* camera;

public:
	World();
	~World();

	void prepareWorld();
	void moveCamera(Vector3d movement);
};

