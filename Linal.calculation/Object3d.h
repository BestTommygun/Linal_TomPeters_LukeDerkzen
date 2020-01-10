#pragma once
#include <memory>
#include <vector>
#include "Data/Vector3d.h"
#include "Mesh.h"

class Object3d
{
private:
	Matrix3d position;
	Mesh* mesh;

public:

	Object3d() : Object3d(Vector3d(0, 0, 0)) {};
	Object3d(const Object3d& toCopy) noexcept;
	Object3d(Object3d&& toMove) noexcept;
	Object3d(const Vector3d& newPosition);
	~Object3d();

	Object3d& operator=(const Object3d& toCopy) noexcept;
	Object3d& operator=(Object3d&& toMove) noexcept;

	void move(const Matrix3d& translationMatrix);

	const Matrix3d& getPosition() const;
	void setPosition(const Matrix3d& newPosition);
	const Mesh& getMesh() const;
	void setMesh(const Mesh& newMesh);
};

