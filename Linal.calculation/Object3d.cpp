#include "Object3d.h"


Object3d::Object3d(Vector3d newPosition)
{
	position = newPosition;
}

void Object3d::move(Vector3d direction)
{
	position += direction;
}

Mesh& Object3d::getMesh() {
	return *mesh;
}
void Object3d::setMesh(Mesh newMesh) {
	if(mesh != nullptr)
		delete mesh;
	mesh = new Mesh(newMesh);
}
