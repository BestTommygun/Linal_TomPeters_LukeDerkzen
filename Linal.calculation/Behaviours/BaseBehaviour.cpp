#include "BaseBehaviour.h"

BaseBehaviour::BaseBehaviour(Object3d& object) noexcept : 
	object{ &object }
{ }

BaseBehaviour::~BaseBehaviour() noexcept
{ }

