#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H


#include <glm/glm.hpp>
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Utils/Texture.h"
#include "Utils/Shader.h"

class SpriteRenderer
{
public:
    //info Construtor(inits Shaders/shapes)
    SpriteRenderer(Shader &shader);
    //info Deconstructor
    ~SpriteRenderer();
    //info Renders defined quad textured with given sprite
    void DrawSprite(Texture &texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotation = 0.0f, glm::vec3 color = glm::vec3(1.0f));
private:
    //info Render State
    Shader shader;
    unsigned int quadVAO;
    //info Initializes and configures the quad's buffer and vertex attributes
    void initRenderData();
};
#endif