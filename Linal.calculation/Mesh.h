#pragma once
#include <vector>
#include <string>
#include "Data/Vector3d.h"

// when making a mesh keep in mind that the parent object sees 0, 0, 0 as its center
class Mesh
{
private: 
	size_t* triangles;

	size_t vertexesSize;

	size_t trianglesSize;

public:    
    Mesh();
    Mesh(const std::vector<Vector3d>& vertexes, const std::vector<size_t>& triangles);
    ~Mesh() noexcept;

    Mesh(const Mesh& toCopy) noexcept;
    Mesh(Mesh&& toMove) noexcept;
    Mesh& operator=(const Mesh& toCopy) noexcept;
    Mesh& operator=(Mesh&& toMove) noexcept;

    std::vector<Vector3d> vertexes;

    size_t getTrianglesSize() const;
    const size_t* getTriangles() const;
    const std::vector<Vector3d>& getVertexes() const;
    void setVertexes(const std::vector<Vector3d>& newVertexes);
};
