#pragma once
#include "BaseBehaviour.h"

class PulseBehaviour : public BaseBehaviour
{
protected:
	Matrix3d prevScale;
	double max, min, growthScale, scale;
	bool isShrinking;
public:
	PulseBehaviour(Object3d& parent, const double max, const double min, const double growthScale);
	~PulseBehaviour();

	PulseBehaviour(const PulseBehaviour& toCopy) noexcept = delete;
	PulseBehaviour(PulseBehaviour&& toMove) noexcept;
	PulseBehaviour& operator=(const PulseBehaviour& toCopy) noexcept = delete;
	PulseBehaviour& operator=(PulseBehaviour&& toMove) noexcept;

	void Update(double deltatime) override;

	void setMax(double newMax);
	const double getMax();
	void setMin(double newMin);
	const double getMin();
	void setgrowthScale(double newgrowthScale);
	const double getgrowthScale();
};

