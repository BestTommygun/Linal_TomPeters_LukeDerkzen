#pragma once
#include <cmath>
#include "Vector2d.h"
#include "../Util/Math.h"

struct Matrix3d;
struct Vector3d
{
	static const Vector3d zero;
	static const Vector3d xAxis;
	static const Vector3d yAxis;
	static const Vector3d zAxis;

	double x;
	double y;
	double z;

	Vector3d();
	Vector3d(double x, double y, double z);

	double length() const;
	Vector3d normalize() const;
	Vector3d crossProduct(Vector3d& vec) const;
	double dot(Vector3d& vec) const;
	Vector3d operator+(const Vector3d& other) const;
	void operator+=(const Vector3d& other);
	Vector3d operator-(const Vector3d& other) const;
	void operator-=(const Vector3d& other);
	Vector3d operator*(const Vector3d& other) const;
	void operator*=(const Vector3d& other);
	Vector3d operator*(const Matrix3d& matrix) const;
	Vector3d operator*(const double& other) const;
	void operator*=(const double& other);
	Vector3d operator/(const Vector3d& other) const;
	void operator/=(const Vector3d& other);
	explicit operator Vector2d();
};

#include "Matrix3d.h"
