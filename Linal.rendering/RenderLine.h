#pragma once
#include "../Linal.calculation/Data/LineColours.h"

public value struct RenderLine
{
protected:
	System::Drawing::PointF point1, point2;
	LineColour lineColour;

public:
	RenderLine(System::Drawing::PointF point1, System::Drawing::PointF point2, LineColour lineColour) :
		point1{ point1 },
		point2{ point2 },
		lineColour{ lineColour }
	{}

	System::Tuple<System::Drawing::PointF, System::Drawing::PointF>^ getPoints();
	System::Drawing::Pen^ getLineColour();
};

