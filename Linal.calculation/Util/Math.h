#pragma once

constexpr double PI = 3.14159265358979323846;

inline int sign(int number){
	if (number > 0) return 1;
	if (number < 0) return -1;
	return 0;
}
inline int sign(float number){
	if (number > 0) return 1;
	if (number < 0) return -1;
	return 0;
}
inline int sign(double number)
{
	if (number > 0) return 1;
	if (number < 0) return -1;
	return 0;
}