#pragma once
#include <vector>
#include <string>
#include "Data/Vector3d.h"

class Mesh
{
private: 
	size_t* triangles;

	size_t vertexesSize;

	size_t trianglesSize;

public:    
    Mesh();
    Mesh(const std::vector<Vector3d>& vertexes, const std::vector<size_t>& triangles);
    Mesh(const Mesh& toCopy) noexcept;
    Mesh(Mesh&& toMove) noexcept;
    ~Mesh() noexcept;

    Mesh& operator=(const Mesh& toCopy) noexcept;
    Mesh& operator=(Mesh&& toMove) noexcept;

    std::vector<Vector3d> vertexes;

    size_t getTrianglesSize() const;
    const size_t* getTriangles() const;
    const std::vector<Vector3d>& getVertexes() const;
    void setVertexes(const std::vector<Vector3d>& newVertexes);
};
