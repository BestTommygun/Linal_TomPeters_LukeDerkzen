#include "World.h"

Object3d World::makeCube(Vector3d position)
{
	std::vector<Vector3d> vertexes = std::vector<Vector3d>();
	vertexes.push_back(Vector3d(0.0, 0.0, 0.0));
	vertexes.push_back(Vector3d(1.0, 0.0, 0.0));
	vertexes.push_back(Vector3d(0.0, 1.0, 0.0));
	vertexes.push_back(Vector3d(1.0, 1.0, 0.0));

	vertexes.push_back(Vector3d(0.0, 0.0, 1.0));
	vertexes.push_back(Vector3d(1.0, 0.0, 1.0));
	vertexes.push_back(Vector3d(0.0, 1.0, 1.0));
	vertexes.push_back(Vector3d(1.0, 1.0, 1.0));

	std::vector<size_t> triangles = std::vector<size_t>();
	//front side
	triangles.push_back(0);
	triangles.push_back(1);
	triangles.push_back(2);

	triangles.push_back(1);
	triangles.push_back(2);
	triangles.push_back(3);

	//left side
	triangles.push_back(0);
	triangles.push_back(4);
	triangles.push_back(2);

	triangles.push_back(2);
	triangles.push_back(6);
	triangles.push_back(4);

	//top side
	triangles.push_back(2);
	triangles.push_back(3);
	triangles.push_back(6);

	triangles.push_back(6);
	triangles.push_back(3);
	triangles.push_back(7);

	//bottom side
	triangles.push_back(0);
	triangles.push_back(1);
	triangles.push_back(4);

	triangles.push_back(1);
	triangles.push_back(4);
	triangles.push_back(5);

	//right side
	triangles.push_back(1);
	triangles.push_back(3);
	triangles.push_back(5);

	triangles.push_back(1);
	triangles.push_back(5);
	triangles.push_back(7);

	//back side
	triangles.push_back(4);
	triangles.push_back(5);
	triangles.push_back(6);

	triangles.push_back(5);
	triangles.push_back(6);
	triangles.push_back(7);

	Mesh cubeMesh = Mesh(vertexes, triangles);

	Object3d object3d = Object3d();
	object3d.setMesh(cubeMesh);
	object3d.move(position);
	object3d.addBehaviour(std::make_unique<PulseBehaviour>(object3d));

	return object3d;
}

World::World()
{
	worldObjects = std::vector<Object3d>();
}

World::~World()
{
	delete camera;
}

void World::prepareWorld()
{
	//make objects here
	camera = new Camera(Vector3d(0, 0, 0), 90, 1, 100);

	worldObjects.push_back(std::move(makeCube(Vector3d(0, 0, 10))));
	worldObjects.push_back(std::move(makeCube(Vector3d(0, 0, 5))));
	worldObjects.push_back(std::move(makeCube(Vector3d(-10, 0, 2))));
}

void World::moveCamera(Vector3d movement)
{
	camera->moveCamera(movement);
}

Camera& World::getCamera() const {
	return *camera;
}