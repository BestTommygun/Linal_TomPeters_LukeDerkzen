#pragma once

public value struct RenderLine
{
protected:
	System::Drawing::PointF point1, point2;

public:
	//TODO: add a colour way (int with lineType, maybe enum), add thickness?
	RenderLine(System::Drawing::PointF point1, System::Drawing::PointF point2) :
		point1{ point1 },
		point2{ point2 }
	{}

	System::Tuple<System::Drawing::PointF, System::Drawing::PointF>^ getPoints();
};

