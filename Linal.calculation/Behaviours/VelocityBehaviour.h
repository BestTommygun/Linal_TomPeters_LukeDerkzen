#pragma once
#include "BaseBehaviour.h"

class VelocityBehaviour : public BaseBehaviour
{
protected:
	double speed;

public:
	VelocityBehaviour(Object3d& parent, const double speed);
	~VelocityBehaviour();

	VelocityBehaviour(const VelocityBehaviour& toCopy) noexcept = delete;
	VelocityBehaviour(VelocityBehaviour&& toMove) noexcept;
	VelocityBehaviour& operator=(const VelocityBehaviour& toCopy) noexcept = delete;
	VelocityBehaviour& operator=(VelocityBehaviour&& toMove) noexcept;

	void Update(double deltatime) override;

	void setSpeed(const double newSpeed);
	const double getSpeed() const;
};

