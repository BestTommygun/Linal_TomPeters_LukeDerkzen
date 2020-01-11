#include "VelocityBehaviour.h"

VelocityBehaviour::VelocityBehaviour(Object3d& parent, const double speed) :
	BaseBehaviour(parent),
	speed{ speed }
{
}

VelocityBehaviour::~VelocityBehaviour()
{
}

VelocityBehaviour::VelocityBehaviour(VelocityBehaviour&& toMove) noexcept : 
	BaseBehaviour(std::move(toMove))
{
	this->speed = toMove.speed;
}

VelocityBehaviour& VelocityBehaviour::operator=(VelocityBehaviour&& toMove) noexcept
{
	if (this != &toMove) {
		this->parent = toMove.parent;
		this->speed = toMove.speed;
	}
	return *this;
}

void VelocityBehaviour::Update(double deltatime)
{
	this->parent->move(this->parent->getPosition().getFrontDirection() * speed);
}

void VelocityBehaviour::setSpeed(const double newSpeed)
{
	speed = newSpeed;
}

const double VelocityBehaviour::getSpeed() const
{
	return speed;
}
