#ifndef PARTICLE_VIEWER_H
#define PARTICLE_VIEWER_H

#include "Common.h"

template<typename Container>
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

    void draw();
}

#endif /* PARTICLE_VIEWER_H */