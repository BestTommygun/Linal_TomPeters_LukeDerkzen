#include "GameObject.h"


GameObject::GameObject(Vector3d newPosition)
{
	position = newPosition;
}

void GameObject::move(Vector3d direction)
{
	position += direction;
}

Mesh& GameObject::getMesh() {
	return *mesh;
}
void GameObject::setMesh(Mesh newMesh) {
	if(mesh != nullptr)
		delete mesh;
	mesh = new Mesh(newMesh);
}
