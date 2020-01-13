#pragma once
#include "Object3d.h"

class TargetObject : public Object3d
{
public:
	TargetObject() : TargetObject(Vector3d(0, 0, 0)) {};
	TargetObject(const Vector3d& newPosition);
	~TargetObject();

	TargetObject(const TargetObject& toCopy) noexcept;
	TargetObject(TargetObject&& toMove) noexcept;
	TargetObject& operator=(const TargetObject& toCopy) noexcept;
	TargetObject& operator=(TargetObject&& toMove) noexcept;

	const bool getIsTarget() const override;
};

