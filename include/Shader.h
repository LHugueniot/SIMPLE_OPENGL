#ifndef SHADER_H
#define SHADER_H

#include "Common.h"
#include "Utilities.h"

struct Shader{

    static Shader compileFromSource(std::string const & name, 
                                    std::string const & vertexSource,
                                    std::string const & fragmentSource);
    static Shader compileFromFile(std::string const & name,
                                  std::string const & vertexFilePath,
                                  std::string const & fragmentFilePath);

    std::string m_name;

    GLuint m_program;

    GLuint m_vertexShader;
    GLuint m_fragmentShader;

    void bind();
    void unBind();

    bool set1f(std::string const & name, float v0);
    bool set2f(std::string const & name, float v0, float v1);
    bool set3f(std::string const & name, float v0, float v1, float v2);
    bool set4f(std::string const & name, float v0, float v1, float v2, float v3);
    bool set1i(std::string const & name, int v0);
    bool set2i(std::string const & name, int v0, int v1);
    bool set3i(std::string const & name, int v0, int v1, int v2);
    bool set4i(std::string const & name, int v0, int v1, int v2, int v3);
    bool set1ui(std::string const & name, uint v0);
    bool set2ui(std::string const & name, uint v0, uint v1);
    bool set3ui(std::string const & name, uint v0, uint v1, uint v2);
    bool set4ui(std::string const & name, uint v0, uint v1, uint v2, uint v3);
    bool setVec1f(std::string const & name, float const * val, size_t count = 1); 
    bool setVec2f(std::string const & name, Eigen::Vector2f const * val, size_t count = 1);
    bool setVec3f(std::string const & name, Eigen::Vector3f const * val, size_t count = 1);
    bool setVec4f(std::string const & name, Eigen::Vector4f const * val, size_t count = 1);
    bool setVec1i(std::string const & name, int const * val, size_t count);
    bool setVec2i(std::string const & name, Eigen::Vector2i const * val, size_t count = 1);
    bool setVec3i(std::string const & name, Eigen::Vector3i const * val, size_t count = 1);
    bool setVec4i(std::string const & name, Eigen::Vector4i const * val, size_t count = 1);
    bool setVec1ui(std::string const & name, uint const * val, size_t count);
    bool setVec2ui(std::string const & name, Eigen::Vector2ui const * val, size_t count = 1);
    bool setVec3ui(std::string const & name, Eigen::Vector3ui const * val, size_t count = 1);
    bool setVec4ui(std::string const & name, Eigen::Vector4ui const * val, size_t count = 1);
    bool setMat2f(std::string const & name, Eigen::Matrix2f const * val, size_t count = 1, bool transpose = false);
    bool setMat3f(std::string const & name,  Eigen::Matrix3f const * val,  size_t count = 1, bool transpose = false);
    bool setMat2x3f(std::string const & name, Eigen::Matrix2x3f const * val, size_t count = 1, bool transpose = false);
    bool setMat3x2f(std::string const & name, Eigen::Matrix3x2f const * val, size_t count = 1, bool transpose = false);
    bool setMat2x4f(std::string const & name, Eigen::Matrix2x4f const * val, size_t count = 1, bool transpose = false);
    bool setMat4x2f(std::string const & name, Eigen::Matrix4x2f const * val, size_t count = 1, bool transpose = false);
    bool setMat3x4f(std::string const & name, Eigen::Matrix3x4f const * val, size_t count = 1, bool transpose = false);
    bool setMat4x3f(std::string const & name, Eigen::Matrix4x3f const * val, size_t count = 1, bool transpose = false);
    bool setMat4f(std::string const & name, Eigen::Matrix4f const * val, size_t count = 1, bool transpose = false);
};


#endif /* SHADER_H */