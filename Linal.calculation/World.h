#pragma once
#include <vector>
#include "Camera.h"
#include "Object3d.h"

class World
{
protected:
	std::vector<Object3d> worldObjects;
	Camera* camera;

	Object3d makeCube(Vector3d position);
public:
	World();
	~World();

	void prepareWorld();
	void moveCamera(Vector3d movement);
	Camera& getCamera() const;

	std::vector<Object3d> getWorldObjects() {
		return worldObjects;
	}
};

