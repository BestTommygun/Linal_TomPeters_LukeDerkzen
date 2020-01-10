#include "Camera.h"

Camera::Camera(Vector3d cameraPos, double fov, double near, double far) : 
	fov{ fov },
	near{ near },
	far{ far }
{
	this->cameraMatrix = Matrix3d(cameraPos);
}

const double Camera::getNear() const
{
	return near;
}

const double Camera::getFar() const
{
	return far;
}

const double Camera::getFov() const
{
	return fov;
}

void Camera::setCameraPos(Vector3d newPosition)
{
	this->cameraMatrix = Matrix3d(newPosition);
}

Matrix3d& Camera::getMatrix()
{
	return cameraMatrix;
}

void Camera::moveCamera(Vector3d movement)
{
	this->cameraMatrix = this->cameraMatrix *  Matrix3d(movement);
}
