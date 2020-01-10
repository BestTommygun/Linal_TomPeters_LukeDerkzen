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

Matrix3d Camera::getPerspectiveMatrix()
{
	double scale = near * std::tan(((fov / 360.0) * 2.0 * PI) * 0.5);
	double m33 = -far / (far - near);
	double m43 = (-far * near) / (far - near);
	return Matrix3d(
		scale, 0, 0, 0,
		0, scale, 0, 0,
		0, 0, m33, m43,
		0, 0, -1, 0
	);
}

void Camera::moveCamera(Vector3d movement)
{
	this->cameraMatrix = this->cameraMatrix *  Matrix3d(movement);
}

void Camera::rotateAroundX(double radAngle)
{
	this->cameraMatrix.rotateAroundXAxis(radAngle);
}

void Camera::rotateAroundY(double radAngle)
{
	this->cameraMatrix.rotateAroundYAxis(radAngle);
}

void Camera::rotateAroundZ(double radAngle)
{
	this->cameraMatrix.rotateAroundZAxis(radAngle);
}