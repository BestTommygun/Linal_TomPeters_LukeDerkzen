#include "BaseBehaviour.h"

BaseBehaviour::BaseBehaviour(Object3d& object) noexcept : 
	parent{ &object }
{ }

BaseBehaviour::~BaseBehaviour() noexcept
{ }

BaseBehaviour::BaseBehaviour(BaseBehaviour&& toMove) noexcept
{
	this->parent = toMove.parent;
	toMove.parent = nullptr;
}

BaseBehaviour& BaseBehaviour::operator=(BaseBehaviour&& toMove) noexcept
{
	if (this != &toMove) {
		this->parent = toMove.parent;
	}
	return *this;
}

void BaseBehaviour::setParent(Object3d& parent)
{
	this->parent = &parent;
}

const Object3d& BaseBehaviour::getParent()
{
	return *parent;
}

