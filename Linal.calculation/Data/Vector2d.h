#pragma once
#include <cmath>
#include "../Util/Math.h"

struct Vector2d
{
	static const Vector2d zero;
	static const Vector2d xAxis;
	static const Vector2d yAxis;

	double x;
	double y;

	Vector2d();
	Vector2d(double x, double y);

	double length() const;
	Vector2d normalize() const;

	inline Vector2d operator+(const Vector2d& other) const {
		return Vector2d(
			this->x + other.x,
			this->y + other.y
		);
	}

	inline void operator+=(const Vector2d& other) {
		this->x += other.x;
		this->y += other.y;
	}

	inline Vector2d operator-(const Vector2d& other) const {
		return Vector2d(
			this->x - other.x,
			this->y - other.y
		);
	}

	inline void operator-=(const Vector2d& other) {
		this->x -= other.x;
		this->y -= other.y;
	}

	inline Vector2d operator*(const Vector2d& other) const {
		return Vector2d(
			this->x * other.x,
			this->y * other.y
		);
	}

	inline void operator*=(const Vector2d& other) {

		this->x *= other.x;
		this->y *= other.y;
	}

	inline Vector2d operator*(const double& factor) const {
		return Vector2d(
			this->x * factor,
			this->y * factor
		);
	}

	inline void operator*=(const double& factor) {
		this->x *= factor;
		this->y *= factor;
	}

	inline Vector2d operator/(const Vector2d& other) const {
		return Vector2d(
			this->x / other.x,
			this->y / other.y
		);
	}

	inline void operator/=(const Vector2d& other) {

		this->x /= other.x;
		this->y /= other.y;
	}
};

