#include "PlayerObject.h"
#include "Behaviours/RotationBehaviour.h"

PlayerObject::PlayerObject(const Vector3d& newPosition, const double reloadSpeed) : 
	Object3d(Vector3d(0, 0, 0)),
	reloadSpeed{ reloadSpeed },
	cooldownTimer{ 0.0 }
{
}

PlayerObject::~PlayerObject()
{
}

PlayerObject::PlayerObject(const PlayerObject& toCopy) noexcept : 
	Object3d(toCopy)
{
	this->cooldownTimer = toCopy.cooldownTimer;
	this->reloadSpeed = toCopy.reloadSpeed;
}

PlayerObject::PlayerObject(PlayerObject&& toMove) noexcept : 
	Object3d(std::move(toMove))
{
	this->cooldownTimer = toMove.cooldownTimer;
	this->reloadSpeed = toMove.reloadSpeed;
}

PlayerObject& PlayerObject::operator=(const PlayerObject& toCopy) noexcept
{
	if (this != &toCopy) {
		delete this->mesh;

		this->mesh = new Mesh(*toCopy.mesh);
		this->position = toCopy.position;

		this->cooldownTimer = toCopy.cooldownTimer;
		this->reloadSpeed = toCopy.reloadSpeed;
	}
	return *this;
}

PlayerObject& PlayerObject::operator=(PlayerObject&& toMove) noexcept
{
	if (this != &toMove) {
		delete mesh;
		this->mesh = toMove.mesh;
		toMove.mesh = nullptr;
		this->position = toMove.position;
		this->behaviours = std::move(toMove.behaviours);

		size_t behavioursSize = this->behaviours.size();
		for (size_t i = 0; i < behavioursSize; i++) {
			this->behaviours[i]->setParent(*this);
		}

		this->cooldownTimer = toMove.cooldownTimer;
		this->reloadSpeed = toMove.reloadSpeed;
	}
	return *this;
}

Object3d PlayerObject::getProjectilePrefab()
{
	if (this->cooldownTimer <= 0) {
		this->cooldownTimer = reloadSpeed;
		Matrix3d bulletPosition = Matrix3d(this->getPosition());
		bulletPosition = bulletPosition * Matrix3d(this->getPosition().getFrontDirection() * 7);
		Object3d bullet = Object3d(bulletPosition);

		std::vector<Vector3d> vertexes = std::vector<Vector3d>();
		vertexes.push_back(Vector3d(0, 0, 0));
		vertexes.push_back(Vector3d(0.186522,0.186522,0.252910));
		vertexes.push_back(Vector3d(0.186522,0.186522,-0.739093));
		vertexes.push_back(Vector3d(-0.186522,0.186522,-0.739093));
		vertexes.push_back(Vector3d(-0.186522,0.186522,-0.252909));
		vertexes.push_back(Vector3d(0.186522,-0.186522,-0.252910));
		vertexes.push_back(Vector3d(0.186522,-0.186522,-0.739093));
		vertexes.push_back(Vector3d(-0.186522,-0.186522,-0.739093));
		vertexes.push_back(Vector3d(-0.186522,-0.186522,-0.252910));
		vertexes.push_back(Vector3d(0.000000,0.250000,-0.053764));
		vertexes.push_back(Vector3d(0.000000,0.250000,-0.744351));
		vertexes.push_back(Vector3d(0.000000,-0.250000,-0.053764));
		vertexes.push_back(Vector3d(-0.000000,-0.250000,-0.744351));
		vertexes.push_back(Vector3d(0.250000,-0.000000,-0.053764));
		vertexes.push_back(Vector3d(0.250000,0.000000,-0.744351));
		vertexes.push_back(Vector3d(-0.250000,0.000000,-0.744351));
		vertexes.push_back(Vector3d(-0.250000,-0.000000,-0.053764));
		vertexes.push_back(Vector3d(0.000000,-0.000000,0.913445));
		vertexes.push_back(Vector3d(-0.000000,0.000000,-0.744351));

		std::vector<size_t> triangles = std::vector<size_t>();

		triangles.push_back(10);
		triangles.push_back(4);
		triangles.push_back(9);

		triangles.push_back(8);
		triangles.push_back(12);
		triangles.push_back(11);

		triangles.push_back(5);
		triangles.push_back(14);
		triangles.push_back(13);

		triangles.push_back(18);
		triangles.push_back(7);
		triangles.push_back(15);

		triangles.push_back(15);
		triangles.push_back(8);
		triangles.push_back(16);

		triangles.push_back(9);
		triangles.push_back(16);
		triangles.push_back(17);

		triangles.push_back(13);
		triangles.push_back(9);
		triangles.push_back(17);

		triangles.push_back(6);
		triangles.push_back(18);
		triangles.push_back(14);

		triangles.push_back(5);
		triangles.push_back(12);
		triangles.push_back(6);

		triangles.push_back(1);
		triangles.push_back(10);
		triangles.push_back(9);

		triangles.push_back(2);
		triangles.push_back(18);
		triangles.push_back(10);

		triangles.push_back(13);
		triangles.push_back(11);
		triangles.push_back(5);

		triangles.push_back(11);
		triangles.push_back(16);
		triangles.push_back(8);

		triangles.push_back(15);
		triangles.push_back(4);
		triangles.push_back(3);

		triangles.push_back(18);
		triangles.push_back(3);
		triangles.push_back(10);

		triangles.push_back(1);
		triangles.push_back(14);
		triangles.push_back(2);

		triangles.push_back(10);
		triangles.push_back(3);
		triangles.push_back(4);

		triangles.push_back(8);
		triangles.push_back(7);
		triangles.push_back(12);

		triangles.push_back(5);
		triangles.push_back(6);
		triangles.push_back(14);

		triangles.push_back(18);
		triangles.push_back(12);
		triangles.push_back(7);

		triangles.push_back(15);
		triangles.push_back(7);
		triangles.push_back(8);

		triangles.push_back(9);
		triangles.push_back(4);
		triangles.push_back(16);

		triangles.push_back(13);
		triangles.push_back(1);
		triangles.push_back(9);

		triangles.push_back(6);
		triangles.push_back(12);
		triangles.push_back(18);

		triangles.push_back(5);
		triangles.push_back(11);
		triangles.push_back(12);

		triangles.push_back(1);
		triangles.push_back(2);
		triangles.push_back(10);

		triangles.push_back(2);
		triangles.push_back(14);
		triangles.push_back(18);

		triangles.push_back(13);
		triangles.push_back(17);
		triangles.push_back(11);

		triangles.push_back(11);
		triangles.push_back(17);
		triangles.push_back(16);

		triangles.push_back(15);
		triangles.push_back(16);
		triangles.push_back(4);

		triangles.push_back(18);
		triangles.push_back(15);
		triangles.push_back(3);

		triangles.push_back(1);
		triangles.push_back(13);
		triangles.push_back(14);

		Mesh cubeMesh = Mesh(vertexes, triangles);
		BoundingBox cubeHitBox = BoundingBox(Vector3d(-1.5, -1.5, -1.5), Vector3d(1.5, 1.5, 1.5));

		bullet.setMesh(cubeMesh);
		bullet.setBoundingBox(cubeHitBox);
		bullet.addBehaviour(std::make_unique<RotationBehaviour>(bullet, RotationDirection::Z, 4)); 
		bullet.addBehaviour(std::make_unique<VelocityBehaviour>(bullet, this->velocity.length() + 0.5));
   		return bullet;
	}
	else {
		Object3d returnObject = Object3d();
		returnObject.markForDestruction();
		return returnObject;
	}
}

const bool PlayerObject::getIsPlayer() const
{
	return true;
}

void PlayerObject::update(double deltaTime)
{
	size_t behavioursSize = this->behaviours.size();
	for (size_t i = 0; i < behavioursSize; i++) {
		behaviours[i]->Update(deltaTime);
	}
	this->cooldownTimer -= deltaTime;
	move(Matrix3d(velocity));
	velocity = velocity * 0.9;
}