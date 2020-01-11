#include "PulseBehaviour.h"

PulseBehaviour::PulseBehaviour(Object3d& parent, const double max, const double min, const double growthScale) :
	BaseBehaviour(parent),
	max{ max },
	min{ min },
	growthScale{ growthScale },
	isShrinking{ false },
	scale{ 1 }
{
}

PulseBehaviour::~PulseBehaviour()
{
}

PulseBehaviour::PulseBehaviour(PulseBehaviour&& toMove) noexcept :
	BaseBehaviour(std::move(toMove))
{
	this->prevScale = toMove.prevScale;
	this->growthScale = toMove.growthScale;
	this->isShrinking = toMove.isShrinking;
	this->scale = toMove.scale;
	this->max = toMove.max;
	this->min = toMove.min;
}

PulseBehaviour& PulseBehaviour::operator=(PulseBehaviour&& toMove) noexcept
{
	if (this != &toMove) {
		this->parent = toMove.parent;
		toMove.parent = nullptr;
		this->prevScale = toMove.prevScale;
		this->growthScale = toMove.growthScale;
		this->isShrinking = toMove.isShrinking;
		this->scale = toMove.scale;
		this->max = toMove.max;
		this->min = toMove.min;
	}
	return *this;
}

void PulseBehaviour::Update(double deltatime)
{
	std::vector<Vector3d> parentVertexes = parent->getMesh().vertexes;
	if (isShrinking) {
		scale -= growthScale;
		if(scale < min)
			isShrinking = false;
	}
	else if (!isShrinking)
	{
		scale += growthScale;
		if(scale > max)
			isShrinking = true;
	}
		
	Matrix3d nextScale = Matrix3d(
		scale, 0, 0, 0,
		0, scale, 0, 0,
		0, 0, scale, 0,
		0,  0,  0,   1
	);
	
	//what to do now:
	//do the inverse of the prev transformation
	//now u have the start pos
	//now do the next transformation
	//prev = next
	//this is done to prevent layering transformations, keeping calculations fairly "clean"

	prevScale = Matrix3d::invertMatrix(prevScale);

	std::vector<Vector3d> updatedVertexes;
	size_t parentVertexesSize = parentVertexes.size();
	for (size_t i = 0; i < parentVertexesSize; i++) {
		auto& curVertex = parentVertexes[i];
		curVertex = curVertex * prevScale;
		curVertex = curVertex * nextScale;
		updatedVertexes.push_back(curVertex);

	}

	prevScale = nextScale;

	parent->getMesh().setVertexes(updatedVertexes);
}

void PulseBehaviour::setMax(double newMax)
{
	max = newMax;
}

const double PulseBehaviour::getMax()
{
	return max;
}

void PulseBehaviour::setMin(double newMin)
{
	min = newMin;
}

const double PulseBehaviour::getMin()
{
	return min;
}

void PulseBehaviour::setgrowthScale(double newgrowthScale)
{
	growthScale = newgrowthScale;
}

const double PulseBehaviour::getgrowthScale()
{
	return growthScale;
}
