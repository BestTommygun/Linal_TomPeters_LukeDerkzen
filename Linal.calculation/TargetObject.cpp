#include "TargetObject.h"

TargetObject::TargetObject(const Vector3d& newPosition) :
	Object3d(newPosition)
{
}

TargetObject::~TargetObject()
{
	delete mesh;
	mesh = nullptr;

	delete boundingBox;
	boundingBox = nullptr;
}

TargetObject::TargetObject(const TargetObject& toCopy) noexcept :
	Object3d(toCopy)
{
}

TargetObject::TargetObject(TargetObject&& toMove) noexcept :
	Object3d(std::move(toMove))
{
}

TargetObject& TargetObject::operator=(const TargetObject& toCopy) noexcept
{
	if (this != &toCopy) {
		delete this->mesh;

		this->mesh = new Mesh(*toCopy.mesh);
		this->position = toCopy.position;
		this->coolDowntimer = toCopy.coolDowntimer;
		this->shouldDestroy = toCopy.shouldDestroy;
		this->boundingBox = new BoundingBox(*toCopy.boundingBox);

	}
	return *this;
}

TargetObject& TargetObject::operator=(TargetObject&& toMove) noexcept
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

		size_t behavioursSize = this->behaviours.size();
		for (size_t i = 0; i < behavioursSize; i++) {
			this->behaviours[i]->setParent(*this);
		}
	}
	return *this;
}

const bool TargetObject::getIsTarget() const
{
	return true;
}
