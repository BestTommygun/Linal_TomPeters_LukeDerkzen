#include "Camera.h"

Camera::Camera(Vector3d cameraPos, double fov, double near, double far) : 
	fov{ fov }
{
	double scale = near * std::tan(fov * 0.5);
	double m33 = -far/(far - near);
	double m34 = (-far * near) / (far - near);

	Matrix3d camMatrix = Matrix3d(
		scale, 0,     0,   0,
		0,	   scale, 0,   0,
		0,	   0,     m33, -1,
		0,	   0,     m34, 0
	);
	this->cameraPos = camMatrix * cameraPos;
}

void Camera::setCameraPos()
{
}

Matrix3d& Camera::getCameraPos()
{
	return cameraPos;
}

void Camera::moveCamera(Vector3d movement)
{
}
