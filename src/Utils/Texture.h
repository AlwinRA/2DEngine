#ifndef TEXTURE_H
#define TEXTURE_H

#include "../../lib/glad/glad.h"

// Texture2D is able to store and configure a texture in OpenGL.
// It also hosts utility functions for easy management.
class Texture
{
public:
    //info ID of texture object
    // used for all texture operations to reference to this particular texture
    unsigned int ID;
    //info image dimensions
    unsigned int Width, Height;
    //info format of texture object
    unsigned int Texture_Format;
    //info format of loaded image
    unsigned int Image_Format;
    //group texture configuration
    //info warpping mode on S-axis
    unsigned int Wrap_S;
    //info warpping mode on T-axis
    unsigned int Wrap_T;
    //info filtering mode if texture pixels < screen pixels
    unsigned int Filter_Min;
    //info filtering mode if texture pixels > screen pixels
    unsigned int Filter_Max;

    Texture();
    ~Texture();
    //info Generate texture from image data
    void Generate(unsigned int width, unsigned int height, const char *data);
    //info binds the texture as the current active GL_TEXTURE_2D texture object
    void Bind() const;
};


#endif