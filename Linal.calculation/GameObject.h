#pragma once
#include <memory>
#include <vector>
#include "Data/Vector3d.h"
#include "Mesh.h"

class GameObject
{
private:
	Vector3d position; //probably should migrate to a transform system
	Mesh* mesh = nullptr;

public:

	GameObject() : GameObject(Vector3d(0, 0, 0)) {};
	GameObject(Vector3d position);

	void move(Vector3d direction);

	Mesh& getMesh();
	void setMesh(Mesh newMesh);
};

