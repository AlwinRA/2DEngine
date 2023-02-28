#ifndef SHADER_RESOURCE_MANAGER
#define SHADER_RESOURCE_MANAGER

#include <map>
#include <string>
#include "../../lib/glad/glad.h"
#include "Shader.h"


class ShaderResourceManager
{
public:
    //info resource storage
    static std::map<std::string, Shader>    Shaders;
    //info loads (and generates) a shader program from file loading vertex, fragment shader's source code
    static Shader LoadShader(const char *vertexShaderFile, const char *fragmentShaderFile, std::string name);
    //info retrives a stored Shader
    static Shader GetShader(std::string name);
    //info properly de-allocates all loaded shaders
    static void Clear();

private:
    //info private constructor,do not want any actual resource manager objects. Its members and functions should be publicly available (static)
    ShaderResourceManager();
    //info load and generates a shader from file
    static Shader LoadShaderFromFile(const char *vertexShaderFile, const char *fragmentShaderFile);
};

#endif