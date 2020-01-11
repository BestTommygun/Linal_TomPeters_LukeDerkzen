#include "RotationBehaviour.h"

RotationBehaviour::RotationBehaviour(Object3d& parent, const RotationDirection& rotationAxis, const double RotationDegrees) :
	BaseBehaviour(parent),
	rotationAxis{ rotationAxis },
	RotationInRad{ ((RotationDegrees / 360.0) * 2.0 * PI) }
{
}

RotationBehaviour::~RotationBehaviour()
{
}

RotationBehaviour::RotationBehaviour(RotationBehaviour&& toMove) noexcept :
	BaseBehaviour(*toMove.parent)
{
	this->parent = toMove.parent;
	this->rotationAxis = toMove.rotationAxis;
	this->RotationInRad = toMove.RotationInRad;

	toMove.parent = nullptr;
}

RotationBehaviour& RotationBehaviour::operator=(RotationBehaviour&& toMove) noexcept
{
	if (this != &toMove) {
		this->parent = toMove.parent;
		this->rotationAxis = toMove.rotationAxis;
		this->RotationInRad = toMove.RotationInRad;

		toMove.parent = nullptr;
	}
	return *this;
}

void RotationBehaviour::Update(double deltatime)
{
	switch (rotationAxis)
	{
	case RotationDirection::X:
		parent->rotateAroundX(RotationInRad);
		break;
	case RotationDirection::Y:
		parent->rotateAroundY(RotationInRad);
		break;
	case RotationDirection::Z:
		parent->rotateAroundZ(RotationInRad);
		break;
	default:
		break;
	}
}

void RotationBehaviour::setRotationDegrees(double newRotationDegrees)
{
	RotationInRad = ((newRotationDegrees / 360.0) * 2.0 * PI);
}

const double RotationBehaviour::getRotationDegrees()
{
	return (RotationInRad * (180 / PI));
}
