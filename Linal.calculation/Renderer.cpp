#include "Renderer.h"

Renderer::Renderer() :
camera{ nullptr }
{
}

Renderer::Renderer(Camera* camera) :
camera{ camera }
{
}

std::vector<Object3d> Renderer::renderObjects(std::vector<Object3d> toRenderObjects)
{
	//lets do the calculate thingies
	return toRenderObjects;
}
