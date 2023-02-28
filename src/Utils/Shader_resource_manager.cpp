#include "Shader_resource_manager.h"
#include <iostream>
#include <sstream>
#include <fstream>

//info Instantiate static variables
std::map<std::string, Shader>    ShaderResourceManager::Shaders;

Shader ShaderResourceManager::LoadShader(const char *vertexShaderFile, const char *fragmentShaderFile, std::string name)
{
    Shaders[name] = LoadShaderFromFile(vertexShaderFile, fragmentShaderFile);
    return Shaders[name];
}

Shader ShaderResourceManager::GetShader(std::string name)
{
    return Shaders[name];
}

void ShaderResourceManager::Clear()
{
    //info (properly) delete all shaders
    for (auto iter : Shaders)
        glDeleteProgram(iter.second.ID);
    
}

ShaderResourceManager::ShaderResourceManager()
{
}

Shader ShaderResourceManager::LoadShaderFromFile(const char *vertexShaderFile, const char *fragmentShaderFile)
{
    //info 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    try
    {
        // open files
        std::ifstream vertexShaderSourceFile(vertexShaderFile);
        std::ifstream fragmentShaderSourceFile(fragmentShaderFile);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vertexShaderSourceFile.rdbuf();
        fShaderStream << fragmentShaderSourceFile.rdbuf();
        // close file handlers
        vertexShaderSourceFile.close();
        fragmentShaderSourceFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::exception e)
    {
        // todo change the error messages to log into a file
        std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
    }
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
    //info 2. now create shader object from source code
    Shader shader;
    shader.Compile(vShaderCode, fShaderCode);
    return shader;
}
