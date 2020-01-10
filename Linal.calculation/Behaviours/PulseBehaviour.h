#pragma once
#include "BaseBehaviour.h"

class PulseBehaviour : public BaseBehaviour
{
protected:
	Matrix3d prevScale;

public:
	PulseBehaviour(Object3d parent);
	~PulseBehaviour();

	PulseBehaviour(const PulseBehaviour& toCopy) noexcept = delete;
	PulseBehaviour(PulseBehaviour&& toMove) noexcept;
	PulseBehaviour& operator=(const PulseBehaviour& toCopy) noexcept = delete;
	PulseBehaviour& operator=(PulseBehaviour&& toMove) noexcept;

	void Update(double deltatime) override;
};

