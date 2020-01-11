#pragma once
#include <vector>
#include "PointXYW.h"
#include "RenderLine.h"
#include "../Linal.calculation/Camera.h"
#include "../Linal.calculation/Object3d.h"

class Renderer
{
private:
	Camera& camera;
public:
	Renderer(Camera& camera);

	/// <Summary> converts all vertexes of objects to actual positions to be ready for render </Summary>
	System::Collections::Generic::List<RenderLine>^ calculateFrame(const std::vector<std::unique_ptr<Object3d>>& toRenderObjects, double screenWidth, double screenHeight);
};

