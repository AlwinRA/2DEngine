#ifndef TEXTURE_RESOURCE_MANAGER
#define TEXTURE_RESOURCE_MANAGER

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <glad/glad.h>

#include "../Texture/texture.h"

class TextureResourceManager
{
public:
    // resource storage
    static std::map<std::string, Texture> Textures;
    // loads (and generates) a texture from file
    static Texture LoadTexture(const char *file, bool alpha, std::string name);
    // retrieves a stored texture
    static Texture GetTexture(std::string name);
    // properly de-allocates all loaded resources
    static void      Clear();
private:
    // private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
    TextureResourceManager() { }
    // loads a single texture from file
    static Texture loadTextureFromFile(const char *file, bool alpha);
};
#endif