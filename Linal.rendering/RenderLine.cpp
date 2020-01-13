#include "pch.h"
#include "RenderLine.h"

System::Tuple<System::Drawing::PointF, System::Drawing::PointF>^ RenderLine::getPoints()
{
	return gcnew System::Tuple<System::Drawing::PointF, System::Drawing::PointF>(point1, point2);
}

System::Drawing::Pen^ RenderLine::getLineColour()
{
	 switch (lineColour)
	 {
	 case LineColour::RED:
		 return System::Drawing::Pens::Red;
	 case LineColour::BLACK:
		 return System::Drawing::Pens::Black;
	 case LineColour::BLUE:
		 return System::Drawing::Pens::Blue;
	 case LineColour::GREEN:
		 return System::Drawing::Pens::Green;
	 case LineColour::UNDEFINED:
		 return System::Drawing::Pens::Red;
	 case LineColour::WHITE:
		 return System::Drawing::Pens::White;
	 default:
		 return System::Drawing::Pens::Red;
	 }
}
