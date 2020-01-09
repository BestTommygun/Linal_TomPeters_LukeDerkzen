#include "Mesh.h"
#include <iostream>

Mesh::Mesh() :
	vertexes{ new std::vector<Vector3d>() },
	triangles{ nullptr },
	vertexesSize{ 0 },
	trianglesSize{ 0 }
{}

Mesh::Mesh(const std::vector<Vector3d>& vertexes, const std::vector<size_t>& triangles)
{
	this->vertexesSize = vertexes.size();
	this->vertexes = new std::vector<Vector3d>();
	for (size_t i = 0; i < vertexesSize; i++) {
		this->vertexes->push_back(vertexes.at(i));
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
	this->vertexes = new std::vector<Vector3d>();
	for (size_t i = 0; i < this->vertexesSize; i++) {
		this->vertexes->push_back(toCopy.vertexes->at(i));
	}
	this->triangles = new size_t[this->trianglesSize];
	for (size_t i = 0; i < this->trianglesSize; i++) {
		this->triangles[i] = toCopy.triangles[i];
	}
}

Mesh::Mesh(Mesh&& toMove) noexcept
{
	this->vertexesSize = toMove.vertexesSize;
	this->vertexes = toMove.vertexes;
	toMove.vertexes = nullptr;
	this->trianglesSize = toMove.trianglesSize;
	this->triangles = toMove.triangles;
	toMove.triangles = nullptr;
}

Mesh::~Mesh() noexcept
{
	delete[] triangles;
	delete vertexes;
}

Mesh& Mesh::operator=(const Mesh& toCopy) noexcept
{
	if (this != &toCopy) {
		delete[] triangles;

		this->vertexesSize = toCopy.vertexesSize;
		this->vertexes = new std::vector<Vector3d>();
		for (size_t i = 0; i < this->vertexesSize; i++) {
			this->vertexes->push_back(toCopy.vertexes->at(i));
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
		delete vertexes;

		this->vertexesSize = toMove.vertexesSize;
		this->vertexes = toMove.vertexes;
		toMove.vertexes = nullptr;
		this->trianglesSize = toMove.trianglesSize;
		this->triangles = toMove.triangles;
		toMove.triangles = nullptr;
	}
	return *this;
}

size_t Mesh::getTrianglesSize()
{
	return trianglesSize;
}

std::vector<size_t> Mesh::getTriangleAt(size_t index)
{
	if (index < trianglesSize - 3) {
		//if(index % 3 == 0)
		std::vector<size_t> returnTriangles = std::vector<size_t>();

		size_t i = index;
		while (i < index + 3) {
			returnTriangles.push_back(triangles[i]);
			i++;
		}
		return returnTriangles;
	}
	throw std::exception("index out of range at Mesh::getTriangleAt()");
}
