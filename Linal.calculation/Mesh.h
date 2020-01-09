#pragma once
#include <vector>
#include <string>
#include "Data/Vector3d.h";

class Mesh
{
private: 
	size_t* triangles;

	size_t vertexesSize;

	size_t trianglesSize;

public:    

    std::vector<Vector3d>* vertexes;

    Mesh();
    Mesh(const std::vector<Vector3d>& vertexes, const std::vector<size_t>& triangles);
    Mesh(const Mesh& toCopy) noexcept;
    Mesh(Mesh&& toMove) noexcept;
    ~Mesh() noexcept;

    Mesh& operator=(const Mesh& toCopy) noexcept;
    Mesh& operator=(Mesh&& toMove) noexcept;

    size_t getTrianglesSize();

};
