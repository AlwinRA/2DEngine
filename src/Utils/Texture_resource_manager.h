#ifndef TEXTURE_RESOURCE_MANAGER
#define TEXTURE_RESOURCE_MANAGER

#include <map>
#include <string>
#include <glad/glad.h>
#include <stb_image.h>
#include "Texture.h"


class TextureResourceManager
{
public:
    //info resource storage
    static std::map<std::string, Texture> Textures;
    //info loads (and generates) a texture from file
    static Texture LoadTexture(const char *file, bool alpha, std::string name);
    //info retrieves a stored texture
    static Texture GetTexture(std::string name);
    //info properly de-allocates all loaded Textures
    static void Clear();

private:
    //info private constructor,do not want any actual resource manager objects. Its members and functions should be publicly available (static)
    TextureResourceManager();
    //info loads a single texture from file
    static Texture loadTextureFromFile(const char *file, bool alpha);
};

#endif