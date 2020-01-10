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
