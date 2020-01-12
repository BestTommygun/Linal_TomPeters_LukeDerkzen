#pragma once
#include "Object3d.h"
#include "Behaviours/VelocityBehaviour.h"

class PlayerObject : public Object3d
{
protected:
	double cooldownTimer, reloadSpeed;
public:
	PlayerObject() : PlayerObject(Vector3d(0, 0, 0), 0) {};
	PlayerObject(const Vector3d& newPosition, const double reloadSpeed);
	~PlayerObject();

	PlayerObject(const PlayerObject& toCopy) noexcept;
	PlayerObject(PlayerObject&& toMove) noexcept;
	PlayerObject& operator=(const PlayerObject& toCopy) noexcept;
	PlayerObject& operator=(PlayerObject&& toMove) noexcept;

	virtual Object3d getPrefab() override; //TODO: denk aan een andere naamgeving, naamgeving suggereerd volkomen andere functionaliteit

	const bool getIsPlayer() const override;
};

