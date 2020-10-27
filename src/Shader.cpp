#include "Shader.h"

void Shader::bind(){
    glUseProgram(m_program);
}
void Shader::unBind(){
    glUseProgram(0);
}



bool Shader::set1f(std::string const & name, float v0){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform1f(location, v0);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::set2f(std::string const & name, float v0, float v1){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform2f(location, v0, v1);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::set3f(std::string const & name, float v0, float v1, float v2){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform3f(location, v0, v1, v2);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::set4f(std::string const & name, float v0, float v1, float v2, float v3){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform4f(location, v0, v1, v2, v3);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::set1i(std::string const & name, int v0){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform1i(location, v0);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::set2i(std::string const & name, int v0, int v1){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform2i(location, v0, v1);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::set3i(std::string const & name, int v0, int v1, int v2){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform3i(location, v0, v1, v2);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::set4i(std::string const & name, int v0, int v1, int v2, int v3){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform4i(location, v0, v1, v2, v3);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::set1ui(std::string const & name, uint v0){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform1ui(location, v0);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::set2ui(std::string const & name, uint v0, uint v1){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform2ui(location, v0, v1);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::set3ui(std::string const & name, uint v0, uint v1, uint v2){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform3ui(location, v0, v1, v2);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::set4ui(std::string const & name, uint v0, uint v1, uint v2, uint v3){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform4ui(location, v0, v1, v2, v3);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}

bool Shader::setVec1f(std::string const & name, float const * val, size_t count){ 
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform1fv(location, count, val);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}


bool Shader::setVec2f(std::string const & name, Eigen::Vector2f const * val, size_t count){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform2fv(location, count, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setVec3f(std::string const & name, Eigen::Vector3f const * val, size_t count){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform3fv(location, count, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setVec4f(std::string const & name, Eigen::Vector4f const * val, size_t count){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform4fv(location, count, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setVec1i(std::string const & name, int const * val, size_t count){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform1iv(location, count, val);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setVec2i(std::string const & name, Eigen::Vector2i const * val, size_t count){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform2iv(location, count, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setVec3i(std::string const & name, Eigen::Vector3i const * val, size_t count){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform3iv(location, count, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setVec4i(std::string const & name, Eigen::Vector4i const * val, size_t count){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform4iv(location, count, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setVec1ui(std::string const & name, uint const * val, size_t count){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform1uiv(location, count, val);
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setVec2ui(std::string const & name, Eigen::Vector2ui const * val, size_t count){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform2uiv(location, count, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setVec3ui(std::string const & name, Eigen::Vector3ui const * val, size_t count){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform3uiv(location, count, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setVec4ui(std::string const & name, Eigen::Vector4ui const * val, size_t count){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniform4uiv(location, count, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setMat2f(std::string const & name,
                       Eigen::Matrix2f const * val,
                       size_t count,
                 bool transpose){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniformMatrix2fv(location, count, transpose, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setMat3f(std::string const & name, 
                       Eigen::Matrix3f const * val, 
                       size_t count,
                       bool transpose){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniformMatrix3fv(location, count, transpose, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}

bool Shader::setMat2x3f(std::string const & name,
                         Eigen::Matrix2x3f const * val,
                         size_t count,
                         bool transpose){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniformMatrix2x3fv(location, count, transpose, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setMat3x2f(std::string const & name,
                         Eigen::Matrix3x2f const * val,
                         size_t count,
                         bool transpose){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniformMatrix3x2fv(location, count, transpose, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setMat2x4f(std::string const & name, 
                         Eigen::Matrix2x4f const * val,
                         size_t count,
                         bool transpose){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniformMatrix2x4fv(location, count, transpose, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setMat4x2f(std::string const & name, 
                         Eigen::Matrix4x2f const * val,
                         size_t count,
                         bool transpose){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniformMatrix4x2fv(location, count, transpose, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setMat3x4f(std::string const & name, 
                         Eigen::Matrix3x4f const * val,
                         size_t count,
                         bool transpose){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniformMatrix3x4fv(location, count, transpose, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}
 
bool Shader::setMat4x3f(std::string const & name, 
                         Eigen::Matrix4x3f const * val,
                         size_t count,
                         bool transpose){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniformMatrix4x3fv(location, count, transpose, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}

bool Shader::setMat4f(std::string const & name, 
                      Eigen::Matrix4f const * val,
                      size_t count,
                      bool transpose){
    GLint location = glGetUniformLocation(m_program, name.c_str());
    if (location == -1){
        glUniformMatrix4fv(location, count, transpose, val->data());
        return true;
    }
    std::cout<<"Shader uniform location \""<<name<<"\" does not exist in "<<m_shaderName<<std::endl;
    return false;
}


Shader Shader::compileFromSource(std::string_view const & name,
                                 std::string_view const & vertexSource,
                                 std::string_view const & fragmentSource){

    Shader retShader;
    retShader.m_name = name;

    // Create an empty vertex shader handle
    Shader.m_vertexShader = glCreateShader(GL_VERTEX_SHADER);

    const GLchar *vertexSource_c_str = (const GLchar *)vertexSource.c_str();
    // Send the vertex shader source code to GL
    //glShaderSource(retShader.m_vertexShader, 1, &vertexSource_c_str, 0);
    glShaderSource(retShader.m_vertexShader, 1, &(const GLchar *)vertexSource.c_str(), 0);

    // Compile the vertex shader
    glCompileShader(retShader.m_vertexShader);

    GLint isCompiled = 0;

    glGetShaderiv(retShader.m_vertexShader, GL_COMPILE_STATUS, &isCompiled);

    if(isCompiled == GL_FALSE){
        std::cout<<"Vertex shader failed to compile."<<std::endl;
        GLint maxLength = 0;
        glGetShaderiv(retShader.m_vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        char infoLog[maxLength];
        glGetShaderInfoLog(retShader.m_vertexShader, maxLength, &maxLength, &infoLog[0]);

        // We don't need the shader anymore.
        glDeleteShader(retShader.m_vertexShader);

        // Use the infoLog as you see fit.
        std::cout<<infoLog<<std::endl;
        
        // In this simple program, we'll just leave
        return 0;
    }

    retShader.m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    const GLchar * fragmentSource_c_str = (const GLchar *)fragmentSource.c_str();

    // Send the fragment shader source code to GL
    //glShaderSource(retShader.m_fragmentShader, 1, &fragmentSource_c_str, 0);
    glShaderSource(retShader.m_fragmentShader, 1, &(const GLchar *)fragmentSource.c_str(), 0);
    
    // Compile the fragment shader
    glCompileShader(retShader.m_fragmentShader);
    
    glGetShaderiv(retShader.m_fragmentShader, GL_COMPILE_STATUS, &isCompiled);

    if (isCompiled == GL_FALSE){
        std::cout<<"Fragment shader failed to compile."<<std::endl;
        GLint maxLength = 0;
        glGetShaderiv(retShader.m_fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        char infoLog[maxLength];
        //std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(retShader.m_fragmentShader, maxLength, &maxLength, &infoLog[0]);

        // We don't need the shader anymore.
        glDeleteShader(retShader.m_fragmentShader);
        // Either of them. Don't leak shaders.
        glDeleteShader(retShader.m_vertexShader);

        // Use the infoLog as you see fit.
        std::cout<<infoLog<<std::endl;
        
        // In this simple program, we'll just leave
        return 0;
    }

    // Vertex and fragment shaders are successfully compiled.
    // Now time to link them together into a program.
    // Get a program object.
    retShader.m_program = glCreateProgram();
    
    // Attach our shaders to our program
    glAttachShader(retShader.m_program, retShader.m_vertexShader);
    glAttachShader(retShader.m_program, retShader.m_fragmentShader);
    
    // Link our program
    glLinkProgram(retShader.m_program);
    
    // Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(retShader.m_program, GL_LINK_STATUS, (int *)&isLinked);
    if (isLinked == GL_FALSE){
        std::cout<<"Shader failed to link."<<std::endl;
        GLint maxLength = 0;
        glGetProgramiv(retShader.m_program, GL_INFO_LOG_LENGTH, &maxLength);
    
        // The maxLength includes the NULL character
        char infoLog[maxLength];
        glGetProgramInfoLog(retShader.m_program, maxLength, &maxLength, &infoLog[0]);
        
        // We don't need the program anymore.
        glDeleteProgram(retShader.m_program);
        // Don't leak shaders either.
        glDeleteShader(retShader.m_vertexShader);
        glDeleteShader(retShader.m_fragmentShader);
    
        // Use the infoLog as you see fit.
        std::cout<<infoLog<<std::endl;
        
        // In this simple program, we'll just leave
        return 0;
    }
    // Always detach shaders after a successful link.
    glDetachShader(retShader.m_program, retShader.m_vertexShader);
    glDetachShader(retShader.m_program, retShader.m_fragmentShader);

    return retShader;
}

Shader Shader::compileFromFile(std::string_view const & name,
                               std::string_view const & vertexFilePath,
                               std::string_view const & fragmentFilePath){
    std::string_view vertexSource = readFile(vertexFilePath);
    std::string_view vertexSource = readFile(fragmentFilePath);
    return Shader::compileFromSource(name, vertexFilePath, fragmentFilePath);
}