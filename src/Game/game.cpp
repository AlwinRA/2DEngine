#include "game.h"
#include "../ResourceManager/texture_resource_manager.h"
// Game-related State data
SpriteRenderer  *Renderer;

Game::Game(unsigned int width, unsigned int height) 
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{ 

}

Game::~Game()
{
    delete Renderer;
}

void Game::Init()
{
    // load shaders
    ShaderResourceManager::LoadShader("../Shaders/sprite.vert", "../Shaders/sprite.frag","sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), 
        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ShaderResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ShaderResourceManager::GetShader("sprite").SetMatrix4f("projection", projection);
    // set render-specific controls
    Renderer = new SpriteRenderer(ShaderResourceManager::GetShader("sprite"));
    // load textures
    TextureResourceManager::LoadTexture("../Texture/Logo.png", true, "logo");
    Renderer->defaultTexture = TextureResourceManager::LoadTexture("../Texture/Logo.png", true, "logo");
}

void Game::Update(float dt)
{
    
}

void Game::ProcessInput(float dt)
{
   
}

void Game::Render()
{
    Renderer->DrawSprite( glm::vec2(200.0f, 200.0f), glm::vec2(200.0f, 200.0f), 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    Renderer->DrawSprite( glm::vec2(250.0f, 200.0f), glm::vec2(200.0f, 200.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}