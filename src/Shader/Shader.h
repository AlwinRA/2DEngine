#ifndef SHADER_H
#define SHADER_H
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

//  General Shader object. Compiles from file
//  Generates compile/link-time errors messages and log 
//  Hosts several utility functions for easy management.
class Shader
{
public:
    // info State_variable
    unsigned int ID;
    // info Constructor 
    Shader() {  };
    // info Sets the current shader as active
    Shader &Use();

    /// @brief Compile shader with vertex path and fragment path
    /// @param vertexSource 
    /// @param fragmentSource 
    void Compile(const char *vertexSource, const char *fragmentSource);

    // group utility functions
    // group =======================START========================
    // info float setting functions , with overloading
    void SetFloat(const char *name, GLfloat v0, bool useShader = false);
    void SetFloat(const char *name, GLfloat v0, GLfloat v1, bool useShader = false);
    void SetFloat(const char *name, GLfloat v0, GLfloat v1, GLfloat v2, bool useShader = false);
    void SetFloat(const char *name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3,bool useShader = false);
    // info int setting functions , with overloading
    void SetInteger(const char *name, GLint v0, bool useShader = false);
    void SetInteger(const char *name, GLint v0, GLint v1, bool useShader = false);
    void SetInteger(const char *name, GLint v0, GLint v1, GLint v2, bool useShader = false);
    void SetInteger(const char *name, GLint v0, GLint v1, GLint v2, GLint v3, bool useShader = false);
    // info vector setting functions, with overloading
    void SetVector1f(const char *name, const glm::vec1 &vector, bool useShader = false);
    void SetVector1f(const char *name, GLfloat x, bool useShader = false);
    void SetVector2f(const char *name, const glm::vec2 &vector, bool useShader = false);
    void SetVector2f(const char *name, GLfloat x, GLfloat y, bool useShader = false);
    void SetVector3f(const char *name, const glm::vec3 &vector, bool useShader = false);
    void SetVector3f(const char *name, GLfloat x, GLfloat y, GLfloat z, bool useShader = false);
    void SetVector4f(const char *name, const glm::vec4 &vector, bool useShader = false);
    void SetVector4f(const char *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, bool useShader = false);
    // info matrix setting functions, no overloading
    void SetMatrix2f(const char *name, const glm::mat2 &matrix, bool useShader = false);
    void SetMatrix3f(const char *name, const glm::mat3 &matrix, bool useShader = false);
    void SetMatrix4f(const char *name, const glm::mat4 &matrix, bool useShader = false);
    // group ========================END============================

private:
    /// @brief Check for compile/link-time error and log
    /// @param object(shader)
    /// @param type
    void checkCompileErrors(unsigned int object, std::string type);
};

#endif