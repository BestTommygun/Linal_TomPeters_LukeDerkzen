#pragma once
#include "Data/Matrix3d.h"
#include "Data/Vector3d.h"

class Camera
{
protected:
	Matrix3d cameraPos;
	double fov;

public:
	Camera() : Camera(Vector3d(0, 0, 0), 90, 20, 200) {};
	Camera(Vector3d cameraPos, double fov, double near, double far);
	~Camera();

	void setCameraPos();
	Matrix3d& getCameraPos();
};

