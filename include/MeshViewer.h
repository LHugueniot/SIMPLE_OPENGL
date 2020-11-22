#ifndef MESH_VIEWER_H
#define MESH_VIEWER_H

#include "Shader.h"
#include "Common.h"

template<template <typename... Args> class Container>
struct MeshViewer{

    MeshViewer(std::string const & _name, 
               Eigen::Matrix4f const & _model = Eigen::Matrix4f::Identity());

    // Mesh name
    std::string m_name;

    // Vertex Array Object
    GLuint m_vao = 0;

    // Vertex Buffer Object
    GLuint m_vbo = 0;
    uint m_vbSize = 0;

    // Index Buffer Object
    GLuint m_ibo = 0;
    uint m_ibSize = 0;

    Eigen::Matrix4f m_model;

    std::shared_ptr<Shader> m_shaderProgram;

    void init(Container<float> const & verticesData = nullptr, 
              Container<uint> const & facesIndicesData = nullptr);

    void draw(Eigen::Matrix4f const & viewProj);

    void load(Container<float> const & verticesData,
              Container<uint> const & facesIndicesData);

    void loadVerticesData(Container<float> const & verticesData);
    void loadFacesIndicesData(Container<float> const & facesIndicesData);
};

//typedef HostMeshViewer = MeshViewer<std::vector>;

#endif /* MESH_VIEWER_H */