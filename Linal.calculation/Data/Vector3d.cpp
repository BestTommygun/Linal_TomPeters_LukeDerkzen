#pragma once
#include "Vector3d.h"

const Vector3d Vector3d::zero = Vector3d(0, 0, 0);
const Vector3d Vector3d::xAxis = Vector3d(1, 0, 0);
const Vector3d Vector3d::yAxis = Vector3d(0, 1, 0);
const Vector3d Vector3d::zAxis = Vector3d(0, 0, 1);

Vector3d::Vector3d() : Vector3d(0, 0, 0) {}
Vector3d::Vector3d(double x, double y, double z) : 
	x{ x }, 
	y{ y }, 
	z{ z }
 {}

double Vector3d::length() const
{
	return sqrt((x * x) + (y * y) + (z * z));
}

Vector3d Vector3d::normalize() const
{
	auto len = length();
	if (abs(len) < 0.000000001)
	{
		return Vector3d(0, 0, 0);
	}
	len = 1 / len;
	auto x = this->x * len;
	auto y = this->y * len;
	auto z = this->z * len;
	if (abs(x - 1) < 0.000000001)
		return Vector3d(sign(x), 0, 0);
	if (abs(y - 1) < 0.000000001)
		return Vector3d(0, sign(y), 0);
	if (abs(z - 1) < 0.000000001)
		return Vector3d(0, 0, sign(z));
	return Vector3d(x, y, z);
}

Vector3d Vector3d::crossProduct(Vector3d& vec) const {

	double newX = (vec.y * this->z) - (vec.z * this->y);
	double newY = (vec.z * this->x) - (vec.x * this->z);
	double newZ = (vec.x * this->y) - (vec.y * this->x);

	return Vector3d(newX, newY, newZ);
}

double Vector3d::dot(Vector3d& vec) const
{
	double x = this->x * vec.x;
	double y = this->y * vec.y;
	double z = this->z * vec.z;
	return x + y + z;
}

Vector3d Vector3d::operator+(const Vector3d& other) const
{
	return Vector3d(
		this->x + other.x,
		this->y + other.y,
		this->z + other.z
	);
}

void Vector3d::operator+=(const Vector3d& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
}

Vector3d Vector3d::operator-(const Vector3d& other) const
{
	return Vector3d(
		this->x - other.x,
		this->y - other.y,
		this->z - other.z
	);
}

void Vector3d::operator-=(const Vector3d& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
}

Vector3d Vector3d::operator*(const Vector3d& other) const
{
	return Vector3d(
		this->x * other.x,
		this->y * other.y,
		this->z * other.z
	);
}

void Vector3d::operator*=(const Vector3d& other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
}

Vector3d Vector3d::operator*(const Matrix3d& matrix) const
{
	return matrix * *this;
}

Vector3d Vector3d::operator*(const double& factor) const
{
	return Vector3d(
		this->x * factor,
		this->y * factor,
		this->z * factor
	);
}

void Vector3d::operator*=(const double& factor)
{
	this->x *= factor;
	this->y *= factor;
	this->z *= factor;
}

Vector3d Vector3d::operator/(const Vector3d& other) const
{
	return Vector3d(
		this->x / other.x,
		this->y / other.y,
		this->z / other.z
	);
}

void Vector3d::operator/=(const Vector3d& other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
}

Vector3d::operator Vector2d()
{
	return Vector2d(x, y);
}
