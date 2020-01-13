#pragma once
#include <memory>
#include <vector>
#include "Mesh.h"
#include "BoundingBox.h"
#include "Data/Vector3d.h"
#include "Behaviours/BaseBehaviour.h"

class Object3d
{
protected:
	Mesh* mesh;
	Matrix3d position;
	BoundingBox* boundingBox;
	bool shouldDestroy;
	double coolDowntimer;
	std::vector<std::unique_ptr<BaseBehaviour>> behaviours;
	Vector3d velocity;

public:

	Object3d() : Object3d(Vector3d(0, 0, 0)) {};
	Object3d(const Vector3d& newPosition);
	Object3d(const Matrix3d& newPosition);
	~Object3d();

	Object3d(const Object3d& toCopy) noexcept;
	Object3d(Object3d&& toMove) noexcept;
	Object3d& operator=(const Object3d& toCopy) noexcept;
	Object3d& operator=(Object3d&& toMove) noexcept;

	void move(const Matrix3d& translationMatrix);

	const Matrix3d& getPosition() const;
	void setPosition(const Matrix3d& newPosition);
	void rotateAroundX(double radAngle);
	void rotateAroundY(double radAngle);
	void rotateAroundZ(double radAngle);

	const Mesh& getMesh() const;
	Mesh& getMesh();
	void setMesh(const Mesh& newMesh);
	virtual const bool getIsPlayer() const;
	virtual const bool getIsTarget() const;
	virtual const bool getShouldDestroy() const;
	virtual Object3d getProjectilePrefab();

	void setCoolDownTimer(const double newCoolDownTimer);
	const double getCoolDowntimer() const;
	void setBoundingBox(BoundingBox newRoughHitbox);
	const BoundingBox& getBoundingBox() const;
	bool intersects(Vector3d point1, Vector3d point2);
	const Vector3d& getVelocity();
	void setVelocity(const Vector3d& newVelocity);

	void addBehaviour(std::unique_ptr<BaseBehaviour> newBehaviour);
	virtual void update(double deltaTime);
	void markForDestruction();
};

