#include "World.h"

PlayerObject World::makePlayer(Vector3d position) 
{
	std::vector<Vector3d> vertexes = std::vector<Vector3d>();
	vertexes.push_back(Vector3d(-1.0, -1.0, -1.0));
	vertexes.push_back(Vector3d(1.0, -1.0, -1.0));
	vertexes.push_back(Vector3d(-1.0, 1.0, -1.0));
	vertexes.push_back(Vector3d(1.0, 1.0, -1.0));

	vertexes.push_back(Vector3d(-1.0, -1.0, 1.0));
	vertexes.push_back(Vector3d(1.0, -1.0, 1.0));
	vertexes.push_back(Vector3d(-1.0, 1.0, 1.0));
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

	Mesh cubeMesh = Mesh(vertexes, triangles); //TODO: one of these triangles is wrong, see the render 
	BoundingBox cubeHitBox = BoundingBox(Vector3d(-1.5, -1.5, -1.5), Vector3d(1.5, 1.5, 1.5));

	PlayerObject object3d = PlayerObject(Vector3d(0.0, 0.0, 0.0), 1);
	object3d.setBoundingBox(cubeHitBox);
	object3d.setMesh(cubeMesh);
	object3d.move(position);

	return object3d;
}

TargetObject World::makeTarget(Vector3d position)
{
	std::vector<Vector3d> vertexes = std::vector<Vector3d>();
	vertexes.push_back(Vector3d(-1.0, -1.0, -1.0));
	vertexes.push_back(Vector3d(1.0, -1.0, -1.0));
	vertexes.push_back(Vector3d(-1.0, 1.0, -1.0));
	vertexes.push_back(Vector3d(1.0, 1.0, -1.0));

	vertexes.push_back(Vector3d(-1.0, -1.0, 1.0));
	vertexes.push_back(Vector3d(1.0, -1.0, 1.0));
	vertexes.push_back(Vector3d(-1.0, 1.0, 1.0));
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

	Mesh cubeMesh = Mesh(vertexes, triangles); //TODO: one of these triangles is wrong, see the render 
	BoundingBox cubeHitBox = BoundingBox(Vector3d(-1.5, -1.5, -1.5), Vector3d(1.5, 1.5, 1.5));

	TargetObject object3d = TargetObject(Vector3d(0.5, 0.5, 0.5));
	object3d.setBoundingBox(cubeHitBox);
	object3d.setMesh(cubeMesh);
	object3d.move(position);

	object3d.addBehaviour(std::make_unique<PulseBehaviour>(object3d, 2, 1, 0.01));
	object3d.addBehaviour(std::make_unique<RotationBehaviour>(object3d, RotationDirection::X, 0.3));
	object3d.addBehaviour(std::make_unique<RotationBehaviour>(object3d, RotationDirection::Y, 1));
	object3d.addBehaviour(std::make_unique<RotationBehaviour>(object3d, RotationDirection::Z, -0.3));
	
	return object3d;
}

Object3d World::makeCube(Vector3d position)
{
	std::vector<Vector3d> vertexes = std::vector<Vector3d>();
	vertexes.push_back(Vector3d(-1.0, -1.0, -1.0));
	vertexes.push_back(Vector3d(1.0,  -1.0, -1.0));
	vertexes.push_back(Vector3d(-1.0, 1.0,  -1.0));
	vertexes.push_back(Vector3d(1.0,  1.0,  -1.0));

	vertexes.push_back(Vector3d(-1.0, -1.0, 1.0));
	vertexes.push_back(Vector3d(1.0,  -1.0, 1.0));
	vertexes.push_back(Vector3d(-1.0, 1.0,  1.0));
	vertexes.push_back(Vector3d(1.0,  1.0,  1.0));

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

	Mesh cubeMesh = Mesh(vertexes, triangles); //TODO: one of these triangles is wrong, see the render 
	BoundingBox cubeHitBox = BoundingBox(Vector3d(-1.5, -1.5, -1.5), Vector3d(1.5, 1.5, 1.5));

	Object3d object3d = Object3d(Vector3d(0.5, 0.5, 0.5));
	object3d.setBoundingBox(cubeHitBox);
	object3d.setMesh(cubeMesh);
	object3d.move(position);
	
	//object3d.addBehaviour(std::make_unique<PulseBehaviour>(object3d, 2, 1, 0.01));
	//object3d.addBehaviour(std::make_unique<RotationBehaviour>(object3d, RotationDirection::Y, 1));
	//object3d.addBehaviour(std::make_unique<RotationBehaviour>(object3d, RotationDirection::Y, 1));
	//object3d.addBehaviour(std::make_unique<RotationBehaviour>(object3d, RotationDirection::Z, 1));
	
	return object3d;
}

World::World() : 
	worldObjects{ std::vector<std::unique_ptr<Object3d>>() },
	camera{ &Camera() }
{ }

World::~World()
{
	delete camera;
}

void World::prepareWorld()
{
	//make objects here
	camera = new Camera(Vector3d(0, 0, 0), 175, 1, 100);

	worldObjects.push_back(std::make_unique<PlayerObject>(std::move(makePlayer(Vector3d(0, -2, 2)))));
	//worldObjects.push_back(std::make_unique<Object3d>(std::move(makeCube(Vector3d(4, 4, 10)))));
	//worldObjects.push_back(std::make_unique<Object3d>(std::move(makeCube(Vector3d(0, 0, 5)))));
	//worldObjects.push_back(std::make_unique<Object3d>(std::move(makeCube(Vector3d(-10, -3, 2)))));
	worldObjects.push_back(std::make_unique<Object3d>(std::move(makeTarget(Vector3d(-10, -10, 10)))));
}

void World::moveCamera(Vector3d movement)
{
	camera->moveCamera(movement);
}

Camera& World::getCamera() const {
	return *camera;
}

std::unique_ptr<Object3d>* World::getPlayerObject() {

	size_t worldObjectsSize = worldObjects.size();
	for (size_t i = 0; i < worldObjectsSize; i++) {
		std::unique_ptr<Object3d>& curObject = worldObjects.at(i);

		if(curObject->getIsPlayer())
			return &curObject;
	}

	return nullptr;
}

std::vector<std::unique_ptr<Object3d>>& World::getWorldObjects() {
	return worldObjects;
}

void World::addWorldObject(Object3d& newObject)
{
	worldObjects.push_back(std::make_unique<Object3d>(std::move(newObject)));
}
