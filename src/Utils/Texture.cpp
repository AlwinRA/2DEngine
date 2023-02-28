#include "Texture.h"

Texture::Texture()
    :Width(0), Height(0), Texture_Format(GL_RGB), Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR), Filter_Max(GL_LINEAR)
{
    glGenTextures(1, &this->ID);
}

Texture::~Texture()
{
}

void Texture::Generate(unsigned int width, unsigned int height, const char *data)
{
    this->Width = width;
    this->Height = height;
    //info create texture
    glBindTexture(GL_TEXTURE_2D, this->ID);
    glTexImage2D(GL_TEXTURE_2D, 0, this->Texture_Format, width, height, 0, this->Image_Format, GL_UNSIGNED_INT, data);
    //info set Texture wrap and filter modes
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Filter_Min);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Filter_Max);
    //info unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->ID);
}
