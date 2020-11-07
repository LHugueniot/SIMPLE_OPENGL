#ifndef MESH_VIEWER_H
#define MESH_VIEWER_H

#include "Common.h"

template<typename Container>
struct MeshViewer{

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

    void init(Container<float> * _verticesData, Container<uint> * _faceIndicesData;);

    void draw(Eigen::Matrix4f const & viewProjMat);
}

#endif /* MESH_VIEWER_H */