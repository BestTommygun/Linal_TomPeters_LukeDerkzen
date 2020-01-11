#include "PulseBehaviour.h"

PulseBehaviour::PulseBehaviour(Object3d& parent) :
	BaseBehaviour(parent)
{
}

PulseBehaviour::~PulseBehaviour()
{
}

PulseBehaviour::PulseBehaviour(PulseBehaviour&& toMove) noexcept :
	BaseBehaviour(*toMove.parent)
{
	this->prevScale = toMove.prevScale;
}

PulseBehaviour& PulseBehaviour::operator=(PulseBehaviour&& toMove) noexcept
{
	if (this != &toMove) {
		this->parent = toMove.parent;
		toMove.parent = nullptr;
		this->prevScale = toMove.prevScale;
	}
	return *this;
}

void PulseBehaviour::Update(double deltatime)
{
	std::vector<Vector3d> parentVertexes = parent->getMesh().vertexes;
	double scale = 1.1;
	Matrix3d scaleMatrix = Matrix3d(
		scale, 0, 0, 0,
		0, scale, 0, 0,
		0, 0, scale, 0,
		0,  0,  0,   1
	);
	std::vector<Vector3d> updatedVertexes;
	size_t parentVertexesSize = parentVertexes.size();
	for (size_t i = 0; i < parentVertexesSize; i++) {
		auto& curVertex = parentVertexes[i];

		updatedVertexes.push_back(curVertex * scaleMatrix);
	}

	parent->getMesh().setVertexes(updatedVertexes);
}
