#include "Shader.h"

Shader::Shader()
{
}

Shader &Shader::Use()
{
    glUseProgram(this->ID);
    return *this;
}

void Shader::Compile(const char *vertexSource, const char *fragmentSource)
{
    unsigned int vertexShader, fragmentShader;
    //info Vertex shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    checkCompileErrors(vertexShader, "VERTEX");

    //info Fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    checkCompileErrors(fragmentShader, "FRAGMENT");

    //info Shader Program
    this->ID = glCreateProgram();
    glAttachShader(this->ID, vertexShader);
    glAttachShader(this->ID, fragmentShader);
    glLinkProgram(this->ID);
    checkCompileErrors(this->ID, "PROGRAM");

    // * delete the shaders as they're linked into program and no longer necessary
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::SetFloat(const char *name, GLfloat v0, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform1f(glGetUniformLocation(this->ID, name), v0);
}

void Shader::SetFloat(const char *name, GLfloat v0, GLfloat v1, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform2f(glGetUniformLocation(this->ID, name), v0, v1);
}

void Shader::SetFloat(const char *name, GLfloat v0, GLfloat v1, GLfloat v2, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform3f(glGetUniformLocation(this->ID, name), v0, v1, v2);
}

void Shader::SetFloat(const char *name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform4f(glGetUniformLocation(this->ID, name), v0, v1, v2, v3);
}

void Shader::SetInteger(const char *name, GLint v0, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform1i(glGetUniformLocation(this->ID, name), v0);
}

void Shader::SetInteger(const char *name, GLint v0, GLint v1, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform2i(glGetUniformLocation(this->ID, name), v0, v1);
}

void Shader::SetInteger(const char *name, GLint v0, GLint v1, GLint v2, bool useShader)
{
if (useShader)
        this->Use();
    glUniform3i(glGetUniformLocation(this->ID, name), v0, v1, v2);
}

void Shader::SetInteger(const char *name, GLint v0, GLint v1, GLint v2, GLint v3, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform4i(glGetUniformLocation(this->ID, name), v0, v1, v2, v3);
}

void Shader::SetVector1f(const char *name, const glm::vec1 &vector, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform1f(glGetUniformLocation(this->ID, name), vector.x);
}

void Shader::SetVector1f(const char *name, GLfloat x, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform1f(glGetUniformLocation(this->ID, name), x);
}

void Shader::SetVector2f(const char *name, const glm::vec2 &vector, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform2f(glGetUniformLocation(this->ID, name), vector.x, vector.y);
}

void Shader::SetVector2f(const char *name, GLfloat x, GLfloat y, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform2f(glGetUniformLocation(this->ID, name), x, y);
}

void Shader::SetVector3f(const char *name, const glm::vec3 &vector, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform3f(glGetUniformLocation(this->ID, name), vector.x, vector.y, vector.z);
}

void Shader::SetVector3f(const char *name, GLfloat x, GLfloat y, GLfloat z, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
}

void Shader::SetVector4f(const char *name, const glm::vec4 &vector, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform4f(glGetUniformLocation(this->ID, name), vector.x, vector.y, vector.z, vector.w);
}

void Shader::SetVector4f(const char *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform4f(glGetUniformLocation(this->ID, name), x, y, z, w);
}

void Shader::SetMatrix2f(const char *name, const glm::mat2 &matrix, bool useShader)
{
    if (useShader)
        this->Use();
    glUniformMatrix2fv(glGetUniformLocation(this->ID, name), 1, false, glm::value_ptr(matrix));
}

void Shader::SetMatrix3f(const char *name, const glm::mat3 &matrix, bool useShader)
{
    if (useShader)
        this->Use();
    glUniformMatrix3fv(glGetUniformLocation(this->ID, name), 1, false, glm::value_ptr(matrix));
}

void Shader::SetMatrix4f(const char *name, const glm::mat4 &matrix, bool useShader)
{
    if (useShader)
        this->Use();
    glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, false, glm::value_ptr(matrix));
}

void Shader::checkCompileErrors(unsigned int object, std::string type)
{
    int success;
    char infoLog[1024];
    // todo change the error messages to log into a file -> **
    if (type != "PROGRAM")
    {
        glGetShaderiv(object, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(object, 1024, NULL, infoLog);
            std::cout << infoLog << std::endl;  // ! ******
        }
    }
    else
    {
        glGetProgramiv(object, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(object, 1024, NULL, infoLog);
            std::cout << infoLog << std::endl;  // ! ******
        }
    }
    
}
