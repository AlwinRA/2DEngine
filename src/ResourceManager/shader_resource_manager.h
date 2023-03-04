#ifndef SHADER_RESOURCE_MANAGER
#define SHADER_RESOURCE_MANAGER
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <glad/glad.h>

#include "../Shader/shader.h"

class ShaderResourceManager
{
public:
    // resource storage
    static std::map<std::string, Shader>    Shaders;
    // loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not nullptr, it also loads a geometry shader
    static Shader    LoadShader(const char *vShaderFile, const char *fShaderFile, std::string name);
    // retrieves a stored sader
    static Shader    GetShader(std::string name);
    static void      Clear();
private:
    // private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
    ShaderResourceManager() { }
    // loads and generates a shader from file
    static Shader    loadShaderFromFile(const char *vShaderFile, const char *fShaderFile);
};

#endif