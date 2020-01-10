#pragma once
#include "../Object3d.h"

class BaseBehaviour
{
protected:
	Object3d* object;

public:
	BaseBehaviour(Object3d& object) noexcept;
	virtual ~BaseBehaviour() noexcept;

	BaseBehaviour(const BaseBehaviour& toCopy) noexcept = delete;
	BaseBehaviour(BaseBehaviour&& toMove) noexcept = delete;
	BaseBehaviour& operator=(const BaseBehaviour& toCopy) noexcept = delete;
	BaseBehaviour& operator=(BaseBehaviour&& toMove) noexcept = delete;

};

