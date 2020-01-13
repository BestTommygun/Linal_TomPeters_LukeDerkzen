#include "Object3d.h"


Object3d::Object3d(const Object3d& toCopy) noexcept
{
	this->mesh = new Mesh(*toCopy.mesh);
	this->position = toCopy.position;
	this->shouldDestroy = toCopy.shouldDestroy;
	this->coolDowntimer = toCopy.coolDowntimer;
	this->boundingBox = new BoundingBox(*toCopy.boundingBox);
	this->velocity = toCopy.velocity;
}

Object3d::Object3d(Object3d&& toMove) noexcept
{
	this->mesh = toMove.mesh;
	toMove.mesh = nullptr;
	this->position = toMove.position;
	this->behaviours = std::move(toMove.behaviours);
	this->coolDowntimer = toMove.coolDowntimer;
	this->shouldDestroy = toMove.shouldDestroy;
	this->boundingBox = toMove.boundingBox;
	toMove.boundingBox = nullptr;
	this->velocity = toMove.velocity;

	size_t behavioursSize = this->behaviours.size();
	for (size_t i = 0; i < behavioursSize; i++) {
		this->behaviours[i]->setParent(*this);
	}
}

Object3d::Object3d(const Vector3d& newPosition) : 
	position{ Matrix3d(newPosition) },
	mesh{ new Mesh() },
	shouldDestroy{ false },
	coolDowntimer{ 0.0 },
	boundingBox{ nullptr },
	velocity{Vector3d(0, 0, 0)}
{ }

Object3d::Object3d(const Matrix3d& newPosition) :
	position{ Matrix3d(newPosition) },
	mesh{ new Mesh() },
	shouldDestroy{ false },
	coolDowntimer{ 0.0 },
	boundingBox{ nullptr },
	velocity{ Vector3d(0, 0, 0) }
{
}

Object3d::~Object3d()
{
	delete mesh;
	mesh = nullptr;

	delete boundingBox;
	boundingBox = nullptr;
}

Object3d& Object3d::operator=(const Object3d& toCopy) noexcept
{
	if (this != &toCopy) {
		delete this->mesh;

		this->mesh = new Mesh(*toCopy.mesh);
		this->position = toCopy.position;
		this->coolDowntimer = toCopy.coolDowntimer;
		this->shouldDestroy = toCopy.shouldDestroy;
		this->boundingBox = new BoundingBox(*toCopy.boundingBox);
		this->velocity = toCopy.velocity;

	}
	return *this;
}

Object3d& Object3d::operator=(Object3d&& toMove) noexcept
{
	if (this != &toMove) {
		delete mesh;
		this->mesh = toMove.mesh;
		toMove.mesh = nullptr;
		this->position = toMove.position;
		this->behaviours = std::move(toMove.behaviours);
		this->coolDowntimer = toMove.coolDowntimer;
		this->shouldDestroy = toMove.shouldDestroy;
		this->boundingBox = toMove.boundingBox;
		toMove.boundingBox = nullptr;
		this->velocity = toMove.velocity;

		size_t behavioursSize = this->behaviours.size();
		for (size_t i = 0; i < behavioursSize; i++) {
			this->behaviours[i]->setParent(*this);
		}
	}
	return *this;
}

void Object3d::move(const Matrix3d& translationMatrix)
{
	position = position * translationMatrix;
	if (boundingBox != nullptr) {
		boundingBox->move(translationMatrix);
	}
}

const Matrix3d& Object3d::getPosition() const
{
	return this->position;
}

void Object3d::setPosition(const Matrix3d& newPosition)
{
	this->position = newPosition;
}

void Object3d::rotateAroundX(double radAngle)
{
	this->position.rotateAroundXAxis(radAngle);
}

void Object3d::rotateAroundY(double radAngle)
{
	this->position.rotateAroundYAxis(radAngle);
}

void Object3d::rotateAroundZ(double radAngle)
{
	this->position.rotateAroundZAxis(radAngle);
}

const Mesh& Object3d::getMesh() const {
	return *mesh;
}
Mesh& Object3d::getMesh() 
{
	return *mesh;
}
void Object3d::setMesh(const Mesh& newMesh) {
	delete mesh;
	mesh = nullptr;
	mesh = new Mesh(newMesh);
}

const bool Object3d::getIsPlayer() const
{
	return false;
}

const bool Object3d::getIsTarget() const
{
	return false;
}

const bool Object3d::getShouldDestroy() const
{
	return shouldDestroy;
}

Object3d Object3d::getProjectilePrefab()
{
	return Object3d(this->getPosition().getPosition());;
}

void Object3d::setCoolDownTimer(const double newCoolDownTimer)
{
	coolDowntimer = newCoolDownTimer;
}

const double Object3d::getCoolDowntimer() const
{
	return coolDowntimer;
}

void Object3d::setBoundingBox(BoundingBox newRoughHitbox)
{
	delete boundingBox;
	boundingBox = nullptr;
	//calculate offset aswell
	Vector3d point1 = newRoughHitbox.getPoints().first;
	Vector3d point2 = newRoughHitbox.getPoints().second;
	point1 += this->getPosition().getPosition();
	point2 += this->getPosition().getPosition();
	this->boundingBox = new BoundingBox(point1, point2);
}

const BoundingBox& Object3d::getBoundingBox() const
{
	return *this->boundingBox;
}

bool Object3d::intersects(Vector3d point1, Vector3d point2)
{
	if(boundingBox != nullptr)
		return boundingBox->intersects(point1, point2);
	return false;
}

const Vector3d& Object3d::getVelocity()
{
	return velocity;
}

void Object3d::setVelocity(const Vector3d& newVelocity)
{
	this->velocity = newVelocity;
}

void Object3d::addBehaviour(std::unique_ptr<BaseBehaviour> newBehaviour)
{
	behaviours.push_back(std::move(newBehaviour));
}

void Object3d::update(double deltaTime)
{
	size_t behavioursSize = this->behaviours.size();
	for (size_t i = 0; i < behavioursSize; i++) {
		behaviours[i]->Update(deltaTime);
	}
	move(Matrix3d(velocity));
	velocity = velocity * 0.9;
}

void Object3d::markForDestruction()
{
	shouldDestroy = true;
}
