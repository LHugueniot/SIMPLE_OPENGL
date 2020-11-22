#ifndef PARTICLE_VIEWER_H
#define PARTICLE_VIEWER_H

#include "Common.h"

template<template <typename... Args> class Container>
struct ParticleViewer{

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
    uint m_verticesDataSize;
    // Vertex data buffer
    Container<float> * m_verticesData;

    // Total number of elements for m_faceIndices
    uint m_faceIndicesDataSize;
    // Ptr to face indices data
    Container<uint> * m_faceIndicesData;

    void init(Container<float> const & verticesData = nullptr, 
              Container<uint> const & facesIndicesData = nullptr);

    void draw(Eigen::Matrix4f const & viewProj);

    void load(Container<float> const & verticesData,
              Container<uint> const & facesIndicesData);

    bool loadVerticesData(Container<float> const & verticesData);
    bool loadFacesIndicesData(Container<float> const & facesIndicesData);
};

#endif /* PARTICLE_VIEWER_H */