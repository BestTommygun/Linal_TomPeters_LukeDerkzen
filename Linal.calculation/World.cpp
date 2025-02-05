#include "World.h"

PlayerObject World::makePlayer(Vector3d position) 
{
	std::vector<Vector3d> vertexes = std::vector<Vector3d>();
	vertexes.push_back(Vector3d(0, 0, 0));
	vertexes.push_back(Vector3d(-0.004318,-0.520436,-3.430470));
	vertexes.push_back(Vector3d(-0.500000,0.500000,1.779767	 ));
	vertexes.push_back(Vector3d(0.500000,0.500000,1.779766	 ));
	vertexes.push_back(Vector3d(-0.500000,-0.500000,1.779767 ));
	vertexes.push_back(Vector3d(0.500000,-0.500000,1.779766	 ));
	vertexes.push_back(Vector3d(0.000000,0.500000,2.115000	 ));
	vertexes.push_back(Vector3d(0.000000,-0.500000,2.115000	 ));
	vertexes.push_back(Vector3d(-0.500000,0.000000,2.115000	 ));
	vertexes.push_back(Vector3d(0.500000,-0.000000,2.115000	 ));
	vertexes.push_back(Vector3d(0.000000,-0.000000,2.999330	 ));
	vertexes.push_back(Vector3d(0.628495,0.628495,0.488807	 ));
	vertexes.push_back(Vector3d(-0.628495,0.628495,0.488808	 ));
	vertexes.push_back(Vector3d(0.628495,-0.628495,0.488807	 ));
	vertexes.push_back(Vector3d(-0.628496,-0.628495,0.488808 ));
	vertexes.push_back(Vector3d(-0.000000,-0.628495,0.501953 ));
	vertexes.push_back(Vector3d(0.000000,0.734441,0.501953	 ));
	vertexes.push_back(Vector3d(0.844413,-0.000000,0.501953	 ));
	vertexes.push_back(Vector3d(-0.844413,0.000000,0.501953	 ));
	vertexes.push_back(Vector3d(-0.000000,-0.633387,-0.003829));
	vertexes.push_back(Vector3d(0.633387,0.633387,-0.004714	 ));
	vertexes.push_back(Vector3d(-0.633387,0.633387,-0.004714 ));
	vertexes.push_back(Vector3d(0.633386,-0.633387,-0.004714 ));
	vertexes.push_back(Vector3d(-0.633387,-0.633387,-0.004713));
	vertexes.push_back(Vector3d(-0.000000,0.739333,-0.003829 ));
	vertexes.push_back(Vector3d(1.696315,-0.000000,-0.003829 ));
	vertexes.push_back(Vector3d(-1.696316,0.000000,-0.003829 ));
	vertexes.push_back(Vector3d(-0.000000,-0.718534,-1.299123));
	vertexes.push_back(Vector3d(0.506737,0.294940,-1.299801	 ));
	vertexes.push_back(Vector3d(-0.506737,0.294940,-1.299801 ));
	vertexes.push_back(Vector3d(0.506737,-0.718534,-1.299802 ));
	vertexes.push_back(Vector3d(-0.506737,-0.718534,-1.299801));
	vertexes.push_back(Vector3d(-0.000000,0.400886,-1.299123 ));
	vertexes.push_back(Vector3d(1.359127,-0.211797,-1.299123 ));
	vertexes.push_back(Vector3d(-1.359128,-0.211797,-1.299123));
	vertexes.push_back(Vector3d(-0.000000,-0.599662,-2.292157));
	vertexes.push_back(Vector3d(0.225512,-0.148638,-2.292435 ));
	vertexes.push_back(Vector3d(-0.225512,-0.148638,-2.292435));
	vertexes.push_back(Vector3d(0.225512,-0.599662,-2.292435 ));
	vertexes.push_back(Vector3d(-0.225512,-0.599662,-2.292434));
	vertexes.push_back(Vector3d(-0.000000,-0.042692,-2.292157));
	vertexes.push_back(Vector3d(0.606505,-0.374150,-2.292157 ));
	vertexes.push_back(Vector3d(-0.606506,-0.374150,-2.292157));

	std::vector<size_t> triangles = std::vector<size_t>();
	triangles.push_back(16);
	triangles.push_back(2);
	triangles.push_back(6);

	triangles.push_back(15);
	triangles.push_back(4);
	triangles.push_back(14);

	triangles.push_back(18);
	triangles.push_back(4);
	triangles.push_back(8);

	triangles.push_back(7);
	triangles.push_back(9);
	triangles.push_back(10);

	triangles.push_back(17);
	triangles.push_back(9);
	triangles.push_back(10);

	triangles.push_back(17);
	triangles.push_back(3);
	triangles.push_back(9);

	triangles.push_back(8);
	triangles.push_back(7);
	triangles.push_back(10);

	triangles.push_back(5);
	triangles.push_back(15);
	triangles.push_back(13);

	triangles.push_back(16);
	triangles.push_back(3);
	triangles.push_back(11);

	triangles.push_back(8);
	triangles.push_back(6);
	triangles.push_back(2);

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

	triangles.push_back(23);
	triangles.push_back(18);
	triangles.push_back(26);

	triangles.push_back(19);
	triangles.push_back(14);
	triangles.push_back(23);

	triangles.push_back(24);
	triangles.push_back(12);
	triangles.push_back(16);

	triangles.push_back(32);
	triangles.push_back(21);
	triangles.push_back(24);

	triangles.push_back(19);
	triangles.push_back(31);
	triangles.push_back(27);

	triangles.push_back(34);
	triangles.push_back(23);
	triangles.push_back(26);

	triangles.push_back(33);
	triangles.push_back(20);
	triangles.push_back(25);

	triangles.push_back(30);
	triangles.push_back(19);
	triangles.push_back(27);

	triangles.push_back(32);
	triangles.push_back(20);
	triangles.push_back(28);

	triangles.push_back(33);
	triangles.push_back(22);
	triangles.push_back(30);

	triangles.push_back(34);
	triangles.push_back(21);
	triangles.push_back(29);

	triangles.push_back(42);
	triangles.push_back(29);
	triangles.push_back(37);

	triangles.push_back(41);
	triangles.push_back(30);
	triangles.push_back(38);

	triangles.push_back(40);
	triangles.push_back(28);
	triangles.push_back(36);

	triangles.push_back(38);
	triangles.push_back(27);
	triangles.push_back(35);

	triangles.push_back(41);
	triangles.push_back(28);
	triangles.push_back(33);

	triangles.push_back(42);
	triangles.push_back(31);
	triangles.push_back(34);

	triangles.push_back(27);
	triangles.push_back(39);
	triangles.push_back(35);

	triangles.push_back(40);
	triangles.push_back(29);
	triangles.push_back(32);

	triangles.push_back(1);
	triangles.push_back(37);
	triangles.push_back(40);

	triangles.push_back(1);
	triangles.push_back(35);
	triangles.push_back(39);

	triangles.push_back(1);
	triangles.push_back(39);
	triangles.push_back(42);

	triangles.push_back(1);
	triangles.push_back(36);
	triangles.push_back(41);

	triangles.push_back(1);
	triangles.push_back(38);
	triangles.push_back(35);

	triangles.push_back(1);
	triangles.push_back(40);
	triangles.push_back(36);

	triangles.push_back(1);
	triangles.push_back(41);
	triangles.push_back(38);

	triangles.push_back(1);
	triangles.push_back(42);
	triangles.push_back(37);

	triangles.push_back(16);
	triangles.push_back(12);
	triangles.push_back(2);

	triangles.push_back(15);
	triangles.push_back(7);
	triangles.push_back(4);

	triangles.push_back(18);
	triangles.push_back(14);
	triangles.push_back(4);

	triangles.push_back(7);
	triangles.push_back(5);
	triangles.push_back(9);

	triangles.push_back(17);
	triangles.push_back(11);
	triangles.push_back(3);

	triangles.push_back(8);
	triangles.push_back(4);
	triangles.push_back(7);

	triangles.push_back(5);
	triangles.push_back(7);
	triangles.push_back(15);

	triangles.push_back(16);
	triangles.push_back(6);
	triangles.push_back(3);

	triangles.push_back(8);
	triangles.push_back(10);
	triangles.push_back(6);

	triangles.push_back(17);
	triangles.push_back(9);
	triangles.push_back(5);

	triangles.push_back(6);
	triangles.push_back(10);
	triangles.push_back(9);

	triangles.push_back(18);
	triangles.push_back(8);
	triangles.push_back(2);

	triangles.push_back(21);
	triangles.push_back(26);
	triangles.push_back(18);

	triangles.push_back(22);
	triangles.push_back(25);
	triangles.push_back(17);

	triangles.push_back(24);
	triangles.push_back(16);
	triangles.push_back(11);

	triangles.push_back(13);
	triangles.push_back(15);
	triangles.push_back(19);

	triangles.push_back(20);
	triangles.push_back(11);
	triangles.push_back(17);

	triangles.push_back(23);
	triangles.push_back(14);
	triangles.push_back(18);

	triangles.push_back(19);
	triangles.push_back(15);
	triangles.push_back(14);

	triangles.push_back(24);
	triangles.push_back(21);
	triangles.push_back(12);

	triangles.push_back(32);
	triangles.push_back(29);
	triangles.push_back(21);

	triangles.push_back(19);
	triangles.push_back(23);
	triangles.push_back(31);

	triangles.push_back(34);
	triangles.push_back(31);
	triangles.push_back(23);

	triangles.push_back(33);
	triangles.push_back(28);
	triangles.push_back(20);

	triangles.push_back(30);
	triangles.push_back(22);
	triangles.push_back(19);

	triangles.push_back(32);
	triangles.push_back(24);
	triangles.push_back(20);

	triangles.push_back(33);
	triangles.push_back(25);
	triangles.push_back(22);

	triangles.push_back(34);
	triangles.push_back(26);
	triangles.push_back(21);

	triangles.push_back(42);
	triangles.push_back(34);
	triangles.push_back(29);

	triangles.push_back(41);
	triangles.push_back(33);
	triangles.push_back(30);

	triangles.push_back(40);
	triangles.push_back(32);
	triangles.push_back(28);

	triangles.push_back(38);
	triangles.push_back(30);
	triangles.push_back(27);

	triangles.push_back(41);
	triangles.push_back(36);
	triangles.push_back(28);

	triangles.push_back(42);
	triangles.push_back(39);
	triangles.push_back(31);

	triangles.push_back(27);
	triangles.push_back(31);
	triangles.push_back(39);

	triangles.push_back(40);
	triangles.push_back(37);
	triangles.push_back(29);



	Mesh cubeMesh = Mesh(vertexes, triangles);
	BoundingBox cubeHitBox = BoundingBox(Vector3d(-4.5, -4.5, -4.5), Vector3d(2.0, 2.0, 2.0));

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
	triangles.push_back(0);
	triangles.push_back(1);
	triangles.push_back(2);

	triangles.push_back(1);
	triangles.push_back(2);
	triangles.push_back(3);

	triangles.push_back(0);
	triangles.push_back(4);
	triangles.push_back(2);

	triangles.push_back(2);
	triangles.push_back(6);
	triangles.push_back(4);

	triangles.push_back(2);
	triangles.push_back(3);
	triangles.push_back(6);

	triangles.push_back(6);
	triangles.push_back(3);
	triangles.push_back(7);

	triangles.push_back(0);
	triangles.push_back(1);
	triangles.push_back(4);

	triangles.push_back(1);
	triangles.push_back(4);
	triangles.push_back(5);

	triangles.push_back(1);
	triangles.push_back(3);
	triangles.push_back(5);

	triangles.push_back(1);
	triangles.push_back(5);
	triangles.push_back(7);

	triangles.push_back(4);
	triangles.push_back(5);
	triangles.push_back(6);

	triangles.push_back(5);
	triangles.push_back(6);
	triangles.push_back(7);

	Mesh cubeMesh = Mesh(vertexes, triangles);
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
	triangles.push_back(0);
	triangles.push_back(1);
	triangles.push_back(2);

	triangles.push_back(1);
	triangles.push_back(2);
	triangles.push_back(3);

	triangles.push_back(0);
	triangles.push_back(4);
	triangles.push_back(2);

	triangles.push_back(2);
	triangles.push_back(6);
	triangles.push_back(4);

	triangles.push_back(2);
	triangles.push_back(3);
	triangles.push_back(6);

	triangles.push_back(6);
	triangles.push_back(3);
	triangles.push_back(7);

	triangles.push_back(0);
	triangles.push_back(1);
	triangles.push_back(4);

	triangles.push_back(1);
	triangles.push_back(4);
	triangles.push_back(5);

	triangles.push_back(1);
	triangles.push_back(3);
	triangles.push_back(5);

	triangles.push_back(1);
	triangles.push_back(5);
	triangles.push_back(7);

	triangles.push_back(4);
	triangles.push_back(5);
	triangles.push_back(6);

	triangles.push_back(5);
	triangles.push_back(6);
	triangles.push_back(7);

	Mesh cubeMesh = Mesh(vertexes, triangles);
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
	camera = new Camera(Vector3d(0, -2, -10), 175, 1, 100);

	worldObjects.push_back(std::make_unique<PlayerObject>(std::move(makePlayer(Vector3d(0, 0, 2)))));
	//worldObjects.push_back(std::make_unique<Object3d>(std::move(makeCube(Vector3d(8, 4, 10)))));
	//worldObjects.push_back(std::make_unique<Object3d>(std::move(makeCube(Vector3d(-16, 0, 0)))));
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
