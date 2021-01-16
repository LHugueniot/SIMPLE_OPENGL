#include "MeshViewer.h"

template<template <typename... Args> class Container>
MeshViewer<Container>::MeshViewer(
        std::string const & _name,                
        Eigen::Matrix4f const & _model) : 
    m_name(_name),
    m_model(_model){}

template<template <typename... Args> class Container>
void MeshViewer<Container>::init(
        Container<float> const & verticesData, 
        Container<uint> const & facesIndicesData){

	// Gen VAO
	glCreateVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

    // Gen VBO
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ibo);

    if(verticesData)
    	loadVerticesData(verticesData);
    if(facesIndicesData)
    	loadFacesData(facesIndicesData);
}

template<template <typename... Args> class Container>
void MeshViewer<Container>::load(
        Container<float> const & verticesData, 
        Container<uint> const & facesIndicesData){
    loadVerticesData(verticesData);
    loadFacesData(facesIndicesData);
}

template<template <typename... Args> class Container>
void MeshViewer<Container>::loadVerticesData(
        Container<float> const & verticesData){
    // make vertex buffer the active buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    // send buffer data to gpu
    glBufferData(GL_ARRAY_BUFFER,
                 verticesData.size() * sizeof(float),
                 &verticesData.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
    glEnableVertexAttribArray(0);
}

template<template <typename... Args> class Container>
void MeshViewer<Container>::loadColourData(
        Container<float> const & colourData){
    // Gen IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 
                 facesIndicesData.size() * sizeof(uint), 
                 &facesIndicesData.data(), GL_STATIC_DRAW);
}

template<template <typename... Args> class Container>
void MeshViewer<Container>::loadFacesIndicesData(
        Container<float> const & facesIndicesData){
    // Gen IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 
                 facesIndicesData.size() * sizeof(uint), 
                 &facesIndicesData.data(), GL_STATIC_DRAW);
}

template<template <typename... Args> class Container>
void MeshViewer<Container>::draw(Eigen::Matrix4f const & viewProj){

    Eigen::Matrix4f mvp = m_model * viewProj;

    // Use our shader
    m_shaderProgram->bind();

    // Load VP mat into MVP
    m_shaderProgram->setMat4f("MVP", &mvp);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glVertexAttribPointer(
        0,                      // attribute
        3,                      // size
        GL_FLOAT,               // type
        GL_FALSE,               // normalized?
        0,                      // stride
        (void*)0                // array buffer offset
    );

    // Index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    // Draw the triangles !
    glDrawElements(
        GL_TRIANGLES,           // mode
        m_ibSize,               // count
        GL_UNSIGNED_SHORT,      // type
        (void*)0                // element array buffer offset
    );

    glDisableVertexAttribArray(0);

    m_shaderProgram->unBind();
}

void meshLinkHack(){
    MeshViewer<std::vector> temp("temp");
    temp.draw(Eigen::Matrix4f::Identity());
}