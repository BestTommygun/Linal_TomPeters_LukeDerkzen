#include "Matrix3d.h"


const double Matrix3d::minValue = 0.000001;
const Matrix3d Matrix3d::identity = Matrix3d();

Matrix3d::Matrix3d()
{
	m12 = m13 = m14
  = m21 = m23 = m24
  = m31 = m32 = m34
  = m41 = m42 = m43 = 0;

	m11 = m22 = m33 = m44 = 1;
}

Matrix3d::Matrix3d(Vector3d offset) :
	m11{ 1 },        m12{ 0 },        m13{ 0 },        m14{ 0 },
	m21{ 0 },        m22{ 1 },        m23{ 0 },        m24{ 0 },
	m31{ 0 },        m32{ 0 },        m33{ 1 },        m34{ 0 },
	m41{ offset.x }, m42{ offset.y }, m43{ offset.z }, m44{ 1 }
{ }

Matrix3d::Matrix3d(double m11, double m12, double m13, double m14, double m21, double m22, double m23, double m24, double m31, double m32, double m33, double m34, double m41, double m42, double m43, double m44) :
	m11{ m11 }, m12{ m12 }, m13{ m13 }, m14{ m14 },
	m21{ m21 }, m22{ m22 }, m23{ m23 }, m24{ m24 },
	m31{ m31 }, m32{ m32 }, m33{ m33 }, m34{ m34 },
	m41{ m41 }, m42{ m42 }, m43{ m43 }, m44{ m44 }
{}

bool Matrix3d::operator==(const Matrix3d& other) const
{
	return
		abs(this->m11 - other.m11) < minValue &&
		abs(this->m12 - other.m12) < minValue &&
		abs(this->m13 - other.m13) < minValue &&
		abs(this->m14 - other.m14) < minValue &&
		abs(this->m21 - other.m21) < minValue &&
		abs(this->m22 - other.m22) < minValue &&
		abs(this->m23 - other.m23) < minValue &&
		abs(this->m24 - other.m24) < minValue &&
		abs(this->m31 - other.m31) < minValue &&
		abs(this->m32 - other.m32) < minValue &&
		abs(this->m33 - other.m33) < minValue &&
		abs(this->m34 - other.m34) < minValue &&
		abs(this->m41 - other.m41) < minValue &&
		abs(this->m42 - other.m42) < minValue &&
		abs(this->m43 - other.m43) < minValue &&
		abs(this->m44 - other.m44) < minValue;
}

Vector3d Matrix3d::operator*(const Vector3d& vector) const
{
	double x = vector.x;
	double y = vector.y;
	double z = vector.z;

	Vector3d pRet = Vector3d(
		m11 * x + m21 * y + m31 * z + m41,
		m12 * x + m22 * y + m32 * z + m42,
		m13 * x + m23 * y + m33 * z + m43
	);
	if (isAffine()) { return pRet; }
	double affineRatio = x * m14 + y * m24 + z * m34 + m44;
	x = pRet.x / affineRatio;
	y = pRet.y / affineRatio;
	z = pRet.z / affineRatio;
	return Vector3d(x, y, z);
}

Matrix3d Matrix3d::operator*(const Matrix3d& other) const
{
	if (this->isIdentity())
	{
		return other;
	}
	else if (other.isIdentity())
	{
		return *this;
	}
	else
	{
		return Matrix3d(
			this->m11 * other.m11 + this->m12 * other.m21 + this->m13 * other.m31 + this->m14 * other.m41,
			this->m11 * other.m12 + this->m12 * other.m22 + this->m13 * other.m32 + this->m14 * other.m42,
			this->m11 * other.m13 + this->m12 * other.m23 + this->m13 * other.m33 + this->m14 * other.m43,
			this->m11 * other.m14 + this->m12 * other.m24 + this->m13 * other.m34 + this->m14 * other.m44,
			this->m21 * other.m11 + this->m22 * other.m21 + this->m23 * other.m31 + this->m24 * other.m41,
			this->m21 * other.m12 + this->m22 * other.m22 + this->m23 * other.m32 + this->m24 * other.m42,
			this->m21 * other.m13 + this->m22 * other.m23 + this->m23 * other.m33 + this->m24 * other.m43,
			this->m21 * other.m14 + this->m22 * other.m24 + this->m23 * other.m34 + this->m24 * other.m44,
			this->m31 * other.m11 + this->m32 * other.m21 + this->m33 * other.m31 + this->m34 * other.m41,
			this->m31 * other.m12 + this->m32 * other.m22 + this->m33 * other.m32 + this->m34 * other.m42,
			this->m31 * other.m13 + this->m32 * other.m23 + this->m33 * other.m33 + this->m34 * other.m43,
			this->m31 * other.m14 + this->m32 * other.m24 + this->m33 * other.m34 + this->m34 * other.m44,
			this->m41 * other.m11 + this->m42 * other.m21 + this->m43 * other.m31 + this->m44 * other.m41,
			this->m41 * other.m12 + this->m42 * other.m22 + this->m43 * other.m32 + this->m44 * other.m42,
			this->m41 * other.m13 + this->m42 * other.m23 + this->m43 * other.m33 + this->m44 * other.m43,
			this->m41 * other.m14 + this->m42 * other.m24 + this->m43 * other.m34 + this->m44 * other.m44);
	}
}

void Matrix3d::operator*=(const Matrix3d& other)
{
	Matrix3d newMatrix = *this * other;
	m11 = newMatrix.m11;
	m12 = newMatrix.m12;
	m13 = newMatrix.m13;
	m14 = newMatrix.m14;

	m21 = newMatrix.m21;
	m22 = newMatrix.m22;
	m23 = newMatrix.m23;
	m24 = newMatrix.m24;

	m31 = newMatrix.m31;
	m32 = newMatrix.m32;
	m33 = newMatrix.m33;
	m34 = newMatrix.m34;

	m41 = newMatrix.m41;
	m42 = newMatrix.m42;
	m43 = newMatrix.m43;
	m44 = newMatrix.m44;
}

Vector3d Matrix3d::getRightDirection() const
{
	return Vector3d(m11, m12, m13);
}

Vector3d Matrix3d::getLeftDirection() const
{
	return Vector3d(-m11, -m12, -m13);
}

Vector3d Matrix3d::getUpDirection() const
{
	return Vector3d(m21, m22, m23);
}

Vector3d Matrix3d::getDownDirection() const
{
	return Vector3d(-m21, -m22, -m23);
}

Vector3d Matrix3d::getFrontDirection() const
{
	return Vector3d(m31, m32, m33);
}

Vector3d Matrix3d::getBackDirection() const
{
	return Vector3d(-m31, -m32, -m33);
}

Matrix3d Matrix3d::createLookAt(Vector3d cameraPosition, Vector3d cameraTarget, Vector3d cameraUpVector)
{
	Vector3d vector = (cameraPosition - cameraTarget).normalize();
	Vector3d vector2 = cameraUpVector.crossProduct(vector).normalize();
	Vector3d vector3 = vector.crossProduct(vector2);

	return Matrix3d(
		vector2.x, vector3.x, vector.x, 0.0,
		vector2.y, vector3.y, vector.y, 0.0,
		vector2.z, vector3.z, vector.z, 0.0,
		-vector2.dot(cameraPosition), -vector3.dot(cameraPosition), -vector.dot(cameraPosition), 1.0);
}

void Matrix3d::rotateAroundXAxis(double radAngle)
{
	//get trig values
	double sinValue = std::sin(radAngle); 
	double cosValue = std::cos(radAngle);

	//save values for matrix as it now stands
	double m21 = this->m21;
	double m22 = this->m22;
	double m23 = this->m23;
	double m24 = this->m24;
	double m31 = this->m31;
	double m32 = this->m32;
	double m33 = this->m33;
	double m34 = this->m34;

	if (this->isIdentity())
	{
		this->m22 = cosValue;
		this->m23 = sinValue;
		this->m32 = -sinValue;
		this->m33 = cosValue;
	}
	else
	{
		//since we rotate around the x axis we only need 2 (y) and 3(z)
		this->m21 = m21 * cosValue + m31 * sinValue;
		this->m22 = m22 * cosValue + m32 * sinValue;
		this->m23 = m23 * cosValue + m33 * sinValue;
		this->m24 = m24 * cosValue + m34 * sinValue;

		this->m31 = m21 * -sinValue + m31 * cosValue;
		this->m32 = m22 * -sinValue + m32 * cosValue;
		this->m33 = m23 * -sinValue + m33 * cosValue;
		this->m34 = m24 * -sinValue + m34 * cosValue;
	}
}

void Matrix3d::rotateAroundYAxis(double radAngle)
{
	//get trig values
	double sinValue = std::sin(radAngle);
	double cosValue = std::cos(radAngle);

	//save values for matrix as it now stands
	double m11 = this->m11;
	double m12 = this->m12;
	double m13 = this->m13;
	double m14 = this->m14;
	double m31 = this->m31;
	double m32 = this->m32;
	double m33 = this->m33;
	double m34 = this->m34;

	if (this->isIdentity())
	{
		this->m11 = cosValue;
		this->m13 = -sinValue;
		this->m31 = sinValue;
		this->m33 = cosValue;
	}
	else
	{
		//since we rotate around y we only need 1 (x) and 3 (z)
		this->m11 = m11 * cosValue + m31 * -sinValue;
		this->m12 = m12 * cosValue + m32 * -sinValue;
		this->m13 = m13 * cosValue + m33 * -sinValue;
		this->m14 = m14 * cosValue + m34 * -sinValue;

		this->m31 = m11 * sinValue + m31 * cosValue;
		this->m32 = m12 * sinValue + m32 * cosValue;
		this->m33 = m13 * sinValue + m33 * cosValue;
		this->m34 = m14 * sinValue + m34 * cosValue;
	}
}

void Matrix3d::rotateAroundZAxis(double radAngle)
{
	//get trig values
	double sinValue = std::sin(radAngle);
	double cosValue = std::cos(radAngle);

	//save values for matrix as it now stands
	double m11 = this->m11;
	double m12 = this->m12;
	double m13 = this->m13;
	double m14 = this->m14;
	double m21 = this->m21;
	double m22 = this->m22;
	double m23 = this->m23;
	double m24 = this->m24;

	if (this->isIdentity())
	{
		this->m11 = cosValue;
		this->m12 = sinValue;
		this->m21 = -sinValue;
		this->m22 = cosValue;
	}
	else
	{
		//since we are rotating z we only need 1 (x) and 2 (y)
		this->m11 = m11 * cosValue + m21 * sinValue;
		this->m12 = m12 * cosValue + m22 * sinValue;
		this->m13 = m13 * cosValue + m23 * sinValue;
		this->m14 = m14 * cosValue + m24 * sinValue;

		this->m21 = m11 * -sinValue + m21 * cosValue;
		this->m22 = m12 * -sinValue + m22 * cosValue;
		this->m23 = m13 * -sinValue + m23 * cosValue;
		this->m24 = m14 * -sinValue + m24 * cosValue;
	}
}


Vector3d Matrix3d::getPosition() const
{
	return Vector3d(m41, m42, m43);
}

bool Matrix3d::isIdentity() const
{
	return *this == Matrix3d::identity;
}

bool Matrix3d::isAffine() const
{
	return abs(m14) < minValue && abs(m24) < minValue && abs(m34) < minValue && abs(m44 - 1.0) < minValue;
}
