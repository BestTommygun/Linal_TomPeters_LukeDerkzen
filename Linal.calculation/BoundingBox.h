#pragma once
#include <memory>
#include "Data/Vector3d.h"

class BoundingBox
{
protected:
	std::pair<Vector3d, Vector3d> points;

public:
	BoundingBox() : BoundingBox(Vector3d(0, 0, 0), Vector3d(0, 0, 0)) {};
	BoundingBox(Vector3d point1, Vector3d point2);
	~BoundingBox();

	BoundingBox(const BoundingBox& toCopy) noexcept;
	BoundingBox(BoundingBox&& toMove) noexcept;
	BoundingBox& operator=(const BoundingBox& toCopy) noexcept;
	BoundingBox& operator=(BoundingBox&& toMove) noexcept;

	/// <summary> 
	/// this compares point1 and point2 to the internal point1 and point2 and returns wether they intersect
	/// </summary>
	/// <param name="point1"> the bottom left closest back point </param>
	/// <param name="point2"> the top right furthest back point </param>
	bool intersects(Vector3d point1, Vector3d point2);
	void move(const Matrix3d& translationMatrix);

	const std::pair<Vector3d, Vector3d>& getPoints() const;
	void setPoints(const std::pair<Vector3d, Vector3d>& newPoints);
};

