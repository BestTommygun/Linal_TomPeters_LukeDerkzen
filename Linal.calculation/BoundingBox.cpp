#include "BoundingBox.h"

BoundingBox::BoundingBox(Vector3d point1, Vector3d point2) :
	points{ std::make_pair(point1, point2) }
{ }

BoundingBox::~BoundingBox()
{
}

BoundingBox::BoundingBox(const BoundingBox& toCopy) noexcept
{
	this->points = toCopy.points;
}

BoundingBox::BoundingBox(BoundingBox&& toMove) noexcept
{
	this->points = toMove.points;
}

BoundingBox& BoundingBox::operator=(const BoundingBox& toCopy) noexcept
{
	if (this != &toCopy) {
		this->points = toCopy.points;
	}
	return *this;
}

BoundingBox& BoundingBox::operator=(BoundingBox&& toMove) noexcept
{
	if (this != &toMove) {
		this->points = toMove.points;
	}
	return *this;
}

bool BoundingBox::intersects(Vector3d point1, Vector3d point2)
{
	bool xtest = (
		this->points.first.x < point1.x && this->points.second.x > point1.x
		|| this->points.first.x < point2.x && this->points.second.x > point2.x
		|| point1.x < this->points.first.x && point2.x > this->points.first.x
		|| point1.x < this->points.second.x && point2.x >this->points.second.x
		);
	bool test = (
		(
			this->points.first.x < point1.x     && this->points.second.x > point1.x
			|| this->points.first.x < point2.x  && this->points.second.x > point2.x
			|| point1.x < this->points.first.x  && point2.x > this->points.first.x
			|| point1.x < this->points.second.x && point2.x >this->points.second.x
			)
		&&
		(
			this->points.first.y < point1.y     && this->points.second.y > point1.y
			|| this->points.first.y < point2.y  && this->points.second.y > point2.y
			|| point1.y < this->points.first.y  && point2.y > this->points.first.y
			|| point1.y < this->points.second.y && point2.y >this->points.second.y
			)
		&&
		(
			this->points.first.z < point1.z     && this->points.second.z > point1.z
			|| this->points.first.z < point2.z  && this->points.second.z > point2.z
			|| point1.z < this->points.first.z  && point2.z > this->points.first.z
			|| point1.z < this->points.second.z && point2.z >this->points.second.z
			)
		);
	return test;
}

void BoundingBox::move(const Matrix3d& translationMatrix)
{
	points.first += translationMatrix.getPosition();
	points.second += translationMatrix.getPosition();
}

const std::pair<Vector3d, Vector3d>& BoundingBox::getPoints() const
{
	return points;
}

void BoundingBox::setPoints(const std::pair<Vector3d, Vector3d>& newPoints)
{
	points = newPoints;
}
