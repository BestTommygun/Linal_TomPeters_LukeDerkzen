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

Object3d PlayerObject::getPrefab()
{
	if (cooldownTimer <= 0) {
		cooldownTimer = reloadSpeed;
		Object3d bullet = Object3d(this->getPosition().getPosition() + this->getPosition().getFrontDirection());

		std::vector<Vector3d> vertexes = std::vector<Vector3d>();
		vertexes.push_back(Vector3d(-0.5, -0.5, -0.5));
		vertexes.push_back(Vector3d(0.5, -0.5, -0.5));
		vertexes.push_back(Vector3d(-0.5, 0.5, -0.5));
		vertexes.push_back(Vector3d(0.5, 0.5, -0.5));

		vertexes.push_back(Vector3d(-0.5, -0.5, 0.5));
		vertexes.push_back(Vector3d(0.5, -0.5, 0.5));
		vertexes.push_back(Vector3d(-0.5, 0.5, 0.5));
		vertexes.push_back(Vector3d(0.5, 0.5, 0.5));

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
		bullet.setMesh(cubeMesh);
		bullet.addBehaviour(std::make_unique<RotationBehaviour>(bullet, RotationDirection::Z, 4));
		bullet.addBehaviour(std::make_unique<VelocityBehaviour>(bullet, 0.5));

   		return bullet;
	}
	else {
		cooldownTimer -= 0.1;
		Object3d returnObject = Object3d();
		returnObject.markForDestruction();
		return returnObject;
	}
}

const bool PlayerObject::getIsPlayer() const
{
	return true;
}
