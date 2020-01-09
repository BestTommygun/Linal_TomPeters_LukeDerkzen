#pragma once
#include <memory>
#include <vector>
#include "Data/Vector3d.h"
#include "Mesh.h"

class Object3d
{
private:
	Vector3d position; //probably should migrate to a transform system
	Mesh* mesh = nullptr;

public:

	Object3d() : Object3d(Vector3d(0, 0, 0)) {};
	Object3d(Vector3d position);

	void move(Vector3d direction);

	Mesh& getMesh();
	void setMesh(Mesh newMesh);
};

