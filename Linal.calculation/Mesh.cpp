#include "Mesh.h"
#include <iostream>

Mesh::Mesh() :
	vertexes{ std::vector<Vector3d>() },
	triangles{ nullptr },
	vertexesSize{ 0 },
	trianglesSize{ 0 }
{}

Mesh::Mesh(const std::vector<Vector3d>& vertexes, const std::vector<size_t>& triangles)
{
	this->vertexesSize = vertexes.size();
	this->vertexes = std::vector<Vector3d>();
	for (size_t i = 0; i < vertexesSize; i++) {
		this->vertexes.push_back(vertexes.at(i));
	}

	this->trianglesSize = triangles.size();
	if (this->trianglesSize % 3 != 0) {
		throw std::exception("the size of the triangle array needs to be a multiple of 3");
	}
	this->triangles = new size_t[trianglesSize];
	for (size_t i = 0; i < trianglesSize; i++) {
		if (triangles[i] < this->vertexesSize) {
			this->triangles[i] = triangles[i];
		}
		else {
			throw std::exception("triangle index is above vertexes size");
		}
	}
}

Mesh::Mesh(const Mesh& toCopy) noexcept
{
	this->vertexesSize = toCopy.vertexesSize;
	this->trianglesSize = toCopy.trianglesSize;
	this->vertexes = std::vector<Vector3d>();
	for (size_t i = 0; i < toCopy.vertexesSize; i++) {
		this->vertexes.push_back(Vector3d(toCopy.vertexes.at(i)));
	}
	this->triangles = new size_t[this->trianglesSize];
	for (size_t i = 0; i < toCopy.trianglesSize; i++) {
		this->triangles[i] = toCopy.triangles[i];
	}
}

Mesh::Mesh(Mesh&& toMove) noexcept
{
	this->vertexesSize = toMove.vertexesSize;
	this->vertexes = toMove.vertexes;
	this->trianglesSize = toMove.trianglesSize;
	this->triangles = toMove.triangles;
	toMove.triangles = nullptr;
}

Mesh::~Mesh() noexcept
{
	delete[] triangles;
	triangles = nullptr;
}

Mesh& Mesh::operator=(const Mesh& toCopy) noexcept
{
	if (this != &toCopy) {
		delete[] triangles;
		triangles = nullptr;

		this->vertexesSize = toCopy.vertexesSize;
		this->vertexes = std::vector<Vector3d>();
		for (size_t i = 0; i < this->vertexesSize; i++) {
			this->vertexes.push_back(toCopy.vertexes.at(i));
		}
		this->trianglesSize = toCopy.trianglesSize;
		this->triangles = new size_t[this->trianglesSize];
		for (size_t i = 0; i < this->trianglesSize; i++) {
			this->triangles[i] = toCopy.triangles[i];
		}
	}
	return *this;
}

Mesh& Mesh::operator=(Mesh&& toMove) noexcept
{
	if (this != &toMove) {
		delete[] triangles;

		this->vertexesSize = toMove.vertexesSize;
		this->vertexes = toMove.vertexes;
		this->trianglesSize = toMove.trianglesSize;
		this->triangles = toMove.triangles;
		toMove.triangles = nullptr;
	}
	return *this;
}

size_t Mesh::getTrianglesSize() const
{
	return trianglesSize;
}

const size_t* Mesh::getTriangles() const
{
	return triangles;
}

void Mesh::setVertexes(const std::vector<Vector3d>& newVertexes)
{
	vertexes = newVertexes;
}

bool Mesh::checkCollisionDetailed(Object3d& thisObject, Object3d& otherObject)
{
	//objects are passed so the offset can be calculated
	//check for each triangle, stop if there's a collision
	Mesh thisMesh = Mesh(thisObject.getMesh());
	Mesh otherMesh = Mesh(otherObject.getMesh());
	for (size_t thisMeshIndex = 0; thisMeshIndex < thisMesh.vertexesSize; thisMeshIndex++) {
		thisMesh.vertexes.data()[thisMeshIndex] += thisObject.getPosition().getPosition();
	}
	for (size_t thisMeshIndex = 0; thisMeshIndex < otherMesh.vertexesSize; thisMeshIndex++) {
		otherMesh.vertexes.data()[thisMeshIndex] += otherObject.getPosition().getPosition();
	}

	//now that the true location has been calculated we can start with the hitboxes
	for (size_t i = 0; i < thisMesh.trianglesSize; i += 3) {

		//i = a, i + 1 = B, i + 2 = C
		//A = thisMesh.vertexes[triangles[i]];
		//B = thisMesh.vertexes[triangles[i + 1]];
		//C = thisMesh.vertexes[triangles[i + 2]];

		for (size_t j = i; j < otherMesh.trianglesSize; j += 3) {

			//i = a, i + 1 = B, i + 2 = C
			//otherA = otherMesh.vertexes[triangles[i]];
			//otherB = otherMesh.vertexes[triangles[i + 1]];
			//otherC = otherMesh.vertexes[triangles[i + 2]];

			//first we'll need to see if the line even hits the plane
			if (doesLineIntersect(otherMesh.vertexes.data()[triangles[i]], otherMesh.vertexes.data()[triangles[i + 1]], thisMesh.vertexes[triangles[j]], thisMesh.vertexes.data()[triangles[j + 1]], thisMesh.vertexes.data()[triangles[j + 2]])) {
				return true;
			}
			if (doesLineIntersect(otherMesh.vertexes.data()[triangles[i]], otherMesh.vertexes.data()[triangles[i + 2]], thisMesh.vertexes[triangles[j]], thisMesh.vertexes.data()[triangles[j + 1]], thisMesh.vertexes.data()[triangles[j + 2]])) {
				return true;
			}
			if (doesLineIntersect(otherMesh.vertexes.data()[triangles[i + 1]], otherMesh.vertexes.data()[triangles[i + 2]], thisMesh.vertexes[triangles[j]], thisMesh.vertexes.data()[triangles[j + 1]], thisMesh.vertexes.data()[triangles[j + 2]])) {
				return true;
			}
		}
	}
	return false;
}

bool Mesh::doesLineIntersect(const Vector3d& P1, const Vector3d& P2, const Vector3d& A, const Vector3d& B, const Vector3d& C)
{
	Vector3d ab = B - A;
	Vector3d ac = C - A;

	Vector3d planeNormal = ab.outProduct(ac);

	Vector3d u = P2 - P1;
	double dot = planeNormal.inProduct(u);

	if (dot != 0)
		auto wakeMeUp = "";

	if (abs(dot) > 0) {
		Vector3d w = P1 - A;
		double fac = -planeNormal.inProduct(w) / dot;
		u = u * fac;
		Vector3d intersect = P1 + u;

		Vector3d ap = intersect - A;

		Vector3d ba = A - B;
		Vector3d bc = C - B;
		Vector3d bp = intersect - B;

		Vector3d ca = A - C;
		Vector3d cb = B - C;
		Vector3d cp = intersect - C;

		Vector3d outABAC = ab.outProduct(ac);
		Vector3d outBCBA = bc.outProduct(ba);
		Vector3d outCACB = ca.outProduct(cb);

		Vector3d outABAP = ab.outProduct(ac);
		Vector3d outBCBP = bc.outProduct(ba);
		Vector3d outCACP = ca.outProduct(cb);

		double inABAP_ABAC = outABAP.inProduct(outABAC);
		double inBCBP_BCBA = outBCBP.inProduct(outBCBA);
		double inCACP_CACB = outCACP.inProduct(outCACB);
		if (inABAP_ABAC >= 0
			&& inBCBP_BCBA >= 0
			&& inCACP_CACB >= 0
			)
			return true;
			
	}
	return false;
}
