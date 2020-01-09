#pragma once
#include "Vector3d.h"

class Matrix3d
{
private:
	double m11, m12, m13, m14;
	double m21, m22, m23, m24;
	double m31, m32, m33, m34;
	double m41, m42, m43, m44;

	const static double minValue;
	const static Matrix3d identity;

public:
	Matrix3d();
	Matrix3d(Vector3d offset);
	Matrix3d(
		double m11, double m12, double m13, double m14, 
		double m21, double m22, double m23, double m24, 
		double m31, double m32, double m33, double m34, 
		double m41, double m42, double m43, double m44);

	//rotates matrix, degrees are counter-clockwise
	void rotate(double degrees);
	void translate(Vector3d translation);
	void scale(Vector3d scalar);

	bool operator==(const Matrix3d&) const;
	Vector3d operator*(const Vector3d& vector) const;
	Matrix3d operator*(const Matrix3d& other) const;
	void operator*=(const Matrix3d& other);
	
	Vector3d getPosition() const;
	bool isIdentity() const;
	bool isAffine() const;
};