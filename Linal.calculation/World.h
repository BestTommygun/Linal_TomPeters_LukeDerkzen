#pragma once
#include <vector>
#include "Camera.h"
#include "Object3d.h"
#include "Behaviours/PulseBehaviour.h"
#include "Behaviours/RotationBehaviour.h"

class World
{
protected:
	std::vector<std::unique_ptr<Object3d>> worldObjects;
	Camera* camera;

	Object3d makeCube(Vector3d position);
	Object3d makePlayer(Vector3d position);
public:
	World();
	~World();

	void prepareWorld();
	void moveCamera(Vector3d movement);

	Camera& getCamera() const;

	std::vector<std::unique_ptr<Object3d>>& getWorldObjects() {
		return worldObjects;
	}
};

