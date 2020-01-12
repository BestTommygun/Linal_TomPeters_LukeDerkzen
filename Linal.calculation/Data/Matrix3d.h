#pragma once
#include <iostream>
#include "Vector3d.h"

struct Matrix3d
{
private:
	const static double minValue;
	const static Matrix3d identity;

public:
	double m11, m12, m13, m14;
	double m21, m22, m23, m24;
	double m31, m32, m33, m34;
	double m41, m42, m43, m44;

	Matrix3d();
	Matrix3d(Vector3d offset);
	Matrix3d(
		double m11, double m12, double m13, double m14, 
		double m21, double m22, double m23, double m24, 
		double m31, double m32, double m33, double m34, 
		double m41, double m42, double m43, double m44);	

	bool operator==(const Matrix3d&) const;
	Vector3d operator*(const Vector3d& vector) const;
	Matrix3d operator*(const Matrix3d& other) const;
	void operator*=(const Matrix3d& other);
	
	Vector3d getRightDirection() const;
	Vector3d getLeftDirection() const;
	Vector3d getUpDirection() const;
	Vector3d getDownDirection() const;
	Vector3d getFrontDirection() const;
	Vector3d getBackDirection() const;

	static Matrix3d createLookAt(Vector3d cameraPosition, Vector3d cameraTarget, Vector3d cameraUpVector);
	//static Matrix3d& createRotateMatrix(const double scale, const double m33, const double m43);
	static Matrix3d& createScaleMatrix(const double scale);
	static Matrix3d& createTransMatrix(const double scale);
	static Matrix3d& invertMatrix(Matrix3d toInvert);
	void rotateAroundXAxis(double radAngle);
	void rotateAroundYAxis(double radAngle);
	void rotateAroundZAxis(double radAngle);
	Vector3d getPosition() const;
	bool isIdentity() const;
	bool isAffine() const;
};