#include "texture_resource_manager.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

// Instantiate static variables
std::map<std::string, Texture>    TextureResourceManager::Textures;

Texture TextureResourceManager::LoadTexture(const char *file, bool alpha, std::string name)
{
    Textures[name] = loadTextureFromFile(file, alpha);
    return Textures[name];
}

Texture TextureResourceManager::GetTexture(std::string name)
{
    return Textures[name];
}

void TextureResourceManager::Clear()
{
    // (properly) delete all textures
    for (auto iter : Textures)
        glDeleteTextures(1, &iter.second.ID);
}

Texture TextureResourceManager::loadTextureFromFile(const char *file, bool alpha)
{
    // create texture object
    Texture texture;
    if (alpha)
    {
        texture.Texture_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }
    // load image
    int width, height, nrChannels;
    unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);
    // now generate texture
    // and finally free image data
    if (data)
    {
        texture.Generate(width, height, data);
    }
    else
    {
        std::cout << "Failed::Texture.Load : " << file << "\n"  << std::endl;
    }
    stbi_image_free(data);
    return texture;
}