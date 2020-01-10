#pragma once
struct PointXYW
{
	PointXYW() : PointXYW(0, 0, 0) {}
	PointXYW(double x, double y, double w);
	
	double x, y, w;
};

