#include "GameObject.h"


GameObject::GameObject(Vector3d newPosition)
{
	position = newPosition;
}

Mesh& GameObject::getMesh() {
	return *mesh;
}
void GameObject::setMesh(Mesh newMesh) {
	if(mesh != nullptr)
		delete mesh;
	mesh = new Mesh(newMesh);
}
