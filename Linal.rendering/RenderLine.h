#pragma once

public value struct RenderLine
{
protected:
	System::Drawing::PointF point1, point2;

public:
	RenderLine(System::Drawing::PointF point1, System::Drawing::PointF point2) :
		point1{ point1 },
		point2{ point2 }
	{}
};

