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

const bool TargetObject::getIsTarget() const
{
	return true;
}
