#include "pch.h"
#include "RenderLine.h"

System::Tuple<System::Drawing::PointF, System::Drawing::PointF>^ RenderLine::getPoints()
{
	return gcnew System::Tuple<System::Drawing::PointF, System::Drawing::PointF>(point1, point2);
}
