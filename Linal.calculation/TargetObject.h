#pragma once
#include "Object3d.h"

class TargetObject : public Object3d
{
public:
	TargetObject() : TargetObject(Vector3d(0, 0, 0)) {};
	TargetObject(const Vector3d& newPosition);
	~TargetObject();

	const bool getIsTarget() const override;
};

