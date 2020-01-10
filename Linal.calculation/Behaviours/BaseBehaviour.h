#pragma once

class Object3d;
class BaseBehaviour
{
protected:
	Object3d* parent;

public:
	BaseBehaviour(Object3d& object) noexcept;
	virtual ~BaseBehaviour() noexcept;

	BaseBehaviour(const BaseBehaviour& toCopy) noexcept = delete;
	BaseBehaviour(BaseBehaviour&& toMove) noexcept = delete;
	BaseBehaviour& operator=(const BaseBehaviour& toCopy) noexcept = delete;
	BaseBehaviour& operator=(BaseBehaviour&& toMove) noexcept = delete;

	virtual void Update(double deltaTime) = 0;

};

#include "../Object3d.h"
