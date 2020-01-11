#pragma once
#include "BaseBehaviour.h"
#include "../Data/RotationDirection.h"

class RotationBehaviour : public BaseBehaviour
{
protected:
	double RotationInRad;
	RotationDirection rotationAxis;
public:
	/// <summary>
	/// rotates an object along one of 3 axis, add multiple RotationBehaviours for more axises
	/// </summary>
	/// <params name="parent"> the parent object </params>
	/// <params name="rotationAxis"> the axis the parent object will rotate along </params>
	/// <params name="RotationDegrees"> the degrees the object will rotate each frame, will be saved in radians because C++ math </params>
	RotationBehaviour(Object3d& parent, const RotationDirection& rotationAxis, const double RotationDegrees);
	~RotationBehaviour();

	RotationBehaviour(const RotationBehaviour& toCopy) noexcept = delete;
	RotationBehaviour(RotationBehaviour&& toMove) noexcept;
	RotationBehaviour& operator=(const RotationBehaviour& toCopy) noexcept = delete;
	RotationBehaviour& operator=(RotationBehaviour&& toMove) noexcept;

	void Update(double deltatime) override;

	void setRotationDegrees(double newRotationDegrees);
	const double getRotationDegrees();
};

