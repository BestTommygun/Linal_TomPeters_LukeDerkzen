#include "Object3d.h"


Object3d::Object3d(const Object3d& toCopy) noexcept
{
	this->mesh = new Mesh(*toCopy.mesh);
	this->position = toCopy.position;
}

Object3d::Object3d(Object3d&& toMove) noexcept
{
	this->mesh = toMove.mesh;
	toMove.mesh = nullptr;
	this->position = toMove.position;
	this->behaviours = std::move(toMove.behaviours);

	size_t behavioursSize = this->behaviours.size();
	for (size_t i = 0; i < behavioursSize; i++) {
		this->behaviours[i]->setParent(*this);
	}
}

Object3d::Object3d(const Vector3d& newPosition)
{
	position = Matrix3d(newPosition);
	mesh = new Mesh();
}

Object3d::~Object3d()
{
	delete mesh;
	mesh = nullptr;
}

Object3d& Object3d::operator=(const Object3d& toCopy) noexcept
{
	if (this != &toCopy) {
		delete this->mesh;

		this->mesh = new Mesh(*toCopy.mesh);
		this->position = toCopy.position;
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
}

const Matrix3d& Object3d::getPosition() const
{
	return this->position;
}

void Object3d::setPosition(const Matrix3d& newPosition)
{
	this->position = newPosition;
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
}
