#include "World.h"

PlayerObject World::makePlayer(Vector3d position) 
{
	std::vector<Vector3d> vertexes = std::vector<Vector3d>();
	vertexes.push_back(Vector3d(3.451090, 0.520436, 0.004318));
	vertexes.push_back(Vector3d(-1.759147, - 0.500000, 0.500000));
	vertexes.push_back(Vector3d(-1.759146, - 0.500000, - 0.500000));
	vertexes.push_back(Vector3d(-1.759147, 0.500000, 0.500000));

	vertexes.push_back(Vector3d(-1.759147, 0.500000, - 0.500000));
	vertexes.push_back(Vector3d(-2.094380, - 0.500000, - 0.000000));
	vertexes.push_back(Vector3d(-2.094380, 0.500000, - 0.000000));
	vertexes.push_back(Vector3d(-2.094380, 0.000000, 0.500000));

	vertexes.push_back(Vector3d(-2.094380, 0.000000, - 0.500000));
	vertexes.push_back(Vector3d(-2.978710, 0.000000, - 0.000000));
	vertexes.push_back(Vector3d(-0.468188, - 0.628495, - 0.628495));
	vertexes.push_back(Vector3d(-0.468188, - 0.628495, 0.628495));

	vertexes.push_back(Vector3d(-0.468187, 0.628495, - 0.628495));
	vertexes.push_back(Vector3d(-0.468188, 0.628495, 0.628496));
	vertexes.push_back(Vector3d(-0.481333, 0.628495, 0.000000));
	vertexes.push_back(Vector3d(-0.481333, - 0.734441, - 0.000000));

	vertexes.push_back(Vector3d(-0.481333, 0.000000, - 0.844413));
	vertexes.push_back(Vector3d(-0.481333, 0.000000, 0.844413));
	vertexes.push_back(Vector3d(0.024449, 0.633387, 0.000000));
	vertexes.push_back(Vector3d(0.025334, - 0.633387, - 0.633387));

	vertexes.push_back(Vector3d(0.025334, - 0.633387, 0.633387));
	vertexes.push_back(Vector3d(0.025334, 0.633387, - 0.633386));
	vertexes.push_back(Vector3d(0.025333, 0.633387, 0.633387));
	vertexes.push_back(Vector3d(0.024449, - 0.739333, - 0.000000));

	vertexes.push_back(Vector3d(0.024449, 0.000000, - 1.696315));
	vertexes.push_back(Vector3d(0.024449, 0.000000, 1.696315));
	vertexes.push_back(Vector3d(1.319742, 0.718534, 0.000000));
	vertexes.push_back(Vector3d(1.320421, - 0.294940, - 0.506737));

	vertexes.push_back(Vector3d(1.320421, - 0.294940, 0.506737));
	vertexes.push_back(Vector3d(1.320422, 0.718534, - 0.506737));
	vertexes.push_back(Vector3d(1.320421, 0.718534, 0.506737));
	vertexes.push_back(Vector3d(1.319742, - 0.400886, 0.000000));

	vertexes.push_back(Vector3d(1.319743, 0.211797, - 1.359128));
	vertexes.push_back(Vector3d(1.319742, 0.211797, 1.359128));
	vertexes.push_back(Vector3d(2.312777, 0.599662, 0.000000));
	vertexes.push_back(Vector3d(2.313055, 0.148638, - 0.225512));

	vertexes.push_back(Vector3d(2.313055, 0.148638, 0.225512));
	vertexes.push_back(Vector3d(2.313055, 0.599662, - 0.225512));
	vertexes.push_back(Vector3d(2.313054, 0.599662, 0.225512));
	vertexes.push_back(Vector3d(2.312777, 0.042692, 0.000000));

	vertexes.push_back(Vector3d(2.312777, 0.374150, - 0.606505));
	vertexes.push_back(Vector3d(2.312777, 0.374150, 0.606506));

	std::vector<size_t> triangles = std::vector<size_t>();
	//front side
	triangles.push_back(16);
	triangles.push_back(2);
	triangles.push_back(6);

	triangles.push_back(15);
	triangles.push_back(4);
	triangles.push_back(14);

	//left side
	triangles.push_back(18);
	triangles.push_back(4);
	triangles.push_back(8);

	triangles.push_back(7);
	triangles.push_back(9);
	triangles.push_back(10);

	//top side
	triangles.push_back(17);
	triangles.push_back(9);
	triangles.push_back(10);

	triangles.push_back(17);
	triangles.push_back(3);
	triangles.push_back(9);

	//bottom side
	triangles.push_back(8);
	triangles.push_back(7);
	triangles.push_back(10);

	triangles.push_back(5);
	triangles.push_back(15);
	triangles.push_back(13);

	//right side
	triangles.push_back(16);
	triangles.push_back(3);
	triangles.push_back(11);

	triangles.push_back(8);
	triangles.push_back(6);
	triangles.push_back(2);

	//back side
	triangles.push_back(17);
	triangles.push_back(5);
	triangles.push_back(13);

	triangles.push_back(6);
	triangles.push_back(9);
	triangles.push_back(3);

	triangles.push_back(18);
	triangles.push_back(2);
	triangles.push_back(12);

	triangles.push_back(21);
	triangles.push_back(18);
	triangles.push_back(12);

	triangles.push_back(22);
	triangles.push_back(17);
	triangles.push_back(13);

	triangles.push_back(24);
	triangles.push_back(11);
	triangles.push_back(20);

	triangles.push_back(13);
	triangles.push_back(19);
	triangles.push_back(22);

	triangles.push_back(13);
	triangles.push_back(19);
	triangles.push_back(22);

	triangles.push_back(20);
	triangles.push_back(17);
	triangles.push_back(25);

	triangles.push_back(6);
	triangles.push_back(3);
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
	worldObjects.push_back(std::make_unique<TargetObject>(std::move(makeTarget(Vector3d(-10, -10, 10)))));
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
