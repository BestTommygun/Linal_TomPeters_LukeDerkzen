#pragma once
#include "Data/Matrix3d.h"
#include "Data/Vector3d.h"

class Camera
{
protected:
	Matrix3d cameraMatrix;
	double fov, near, far;

public:
	Camera() : Camera(Vector3d(0, 0, 0), 90, 20, 200) {};
	Camera(Vector3d cameraPos, double fov, double near, double far);

	const double getNear() const;
	const double getFar() const;
	const double getFov() const;
	void setCameraPos(Vector3d newPosition);
	Matrix3d& getMatrix();
	Matrix3d getPerspectiveMatrix();

	void moveCamera(Vector3d movement);
	void rotateAroundX(double radAngle);
	void rotateAroundY(double radAngle);
	void rotateAroundZ(double radAngle);
};

