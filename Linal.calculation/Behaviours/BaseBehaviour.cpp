#include "BaseBehaviour.h"

BaseBehaviour::BaseBehaviour(Object3d& object) noexcept : 
	parent{ &object }
{ }

BaseBehaviour::~BaseBehaviour() noexcept
{ }

