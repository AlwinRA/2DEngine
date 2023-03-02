#include "Texture_resource_manager.h"

//info Instantiate static variables
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
    //info (properly) delete all textures
    for (auto iter : Textures)
        glDeleteTextures(1, &iter.second.ID);
}

Texture TextureResourceManager::loadTextureFromFile(const char *file, bool alpha)
{
    //info create texture object
    Texture texture;
    if (alpha)
    {
        texture.Texture_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }
    //info load image
    int width, height, nrChannels;
    unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0);
    //info generate texture
    texture.Generate(width, height, data);
    //info finally free image data
    stbi_image_free(data);
    return texture;
}
