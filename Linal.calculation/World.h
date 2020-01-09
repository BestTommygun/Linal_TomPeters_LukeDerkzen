#pragma once
#include <vector>
#include "Camera.h"
#include "GameObject.h"

class World
{
protected:
	std::vector<GameObject> worldObjects;
	Camera* camera;

	GameObject makeCube(Vector3d position);
public:
	World();
	~World();

	void prepareWorld();
	void moveCamera(Vector3d movement);

	std::vector<GameObject> getWorldObjects() {
		return worldObjects;
	}
};

