#pragma once
#include <vector>
#include "Camera.h"
#include "Object3d.h"

class Renderer
{
private:
	Camera* camera;
public:
	Renderer();
	Renderer(Camera* camera);

	/// <Summary> converts all vertexes of objects to actual positions to be ready for render </Summary>
	std::vector<Object3d> renderObjects(std::vector<Object3d> toRenderObjects);
};

