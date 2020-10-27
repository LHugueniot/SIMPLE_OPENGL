#ifndef MESH_H
#define MESH_H

#include "Common.h"

struct Mesh{

    // Mesh name
    std::string m_name;

    // Vertex Array Object
    GLuint m_vao;

    // Vertex Buffer Object
    GLuint m_vbo;

    // Index Buffer Object
    GLuint m_ibo;

    // Total number of conceptual vertices
    uint m_verticesNum;
    // Total size of m_vertexPositions (m_verticesNum * 3)
    uint m_verticesSize;
    // Vertex data buffer
    float * m_vertices;

    // Total number of elements for m_faceIndices
    uint m_faceIndicesSize;
    // Ptr to face indices data
    uint * m_faceIndices;
}

#endif /* MESH */