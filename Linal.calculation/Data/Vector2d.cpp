#include "Vector2d.h"

const Vector2d Vector2d::zero = Vector2d(0, 0);
const Vector2d Vector2d::xAxis = Vector2d(1, 0);
const Vector2d Vector2d::yAxis = Vector2d(0, 1);

Vector2d::Vector2d() : Vector2d(0, 0) {}
Vector2d::Vector2d(double x, double y) : x{ x }, y{ y } {}

double Vector2d::length() const
{
	return sqrt((x * x) + (y * y));
}

Vector2d Vector2d::normalize() const
{
	auto len = length();
	if (abs(len) < 0.000000001)
	{
		return Vector2d(0, 0);
	}
	len = 1 / len;
	auto x = this->x * len;
	auto y = this->y * len;
	if (abs(x - 1) < 0.000000001)
		return Vector2d(sign(x), 0);
	if (abs(y - 1) < 0.000000001)
		return Vector2d(0, sign(y));
	return Vector2d(x, y);
}
