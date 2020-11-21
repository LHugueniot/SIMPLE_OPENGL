#include "MeshViewer.h"

MeshViewer::MeshViewer(std::string const & _name,                
                       Eigen::Matrix4f _model) : 
    m_name(_name),
    m_model(_model){}

void MeshViewer::init(Container<float> const & verticesData = nullptr, 
					  Container<uint> const & faceIndicesData = nullptr){

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


bool MeshViewer::load(Container<float> const & verticesData, 
					  Container<uint> const & faceIndicesData){
    loadVerticesData(verticesData);
    loadFacesData(facesIndicesData);
}

void MeshViewer::loadVerticesData(Container<float> const & verticesData){
    // Gen VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 verticesData.size() * sizeof(float),
                 &verticesData.data(), GL_STATIC_DRAW);

    glEnableVertexArrayAttrib(m_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
}

void MeshViewer::loadFacesIndicesData(Container<float> const & facesIndicesData){
    // Gen IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 
                 faceIndicesDataSize.size() * sizeof(uint), 
                 &faceIndicesData.data(), GL_STATIC_DRAW);
}

void MeshViewer::draw(Eigen::Matrix4f const & viewProj){

    Eigen::Matrix4f mvp = viewProj;

    if(m_model)
        mvp = model * mvp;

    // Use our shader
    m_shader.bind();

    // Load VP mat into MVP
    m_shader.setMat4f("MVP", &mvp);

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

    m_shader.unBind();
}