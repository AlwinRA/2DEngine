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
    delete player;
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
    // player->Sprite = TextureResourceManager::GetTexture("logo");
    Entity obj(TextureResourceManager::GetTexture("logo"), glm::vec2(10.0f, 10.0f), glm::vec2(40.0f, 40.0f), 0.0f, glm::vec3(1.0f,1.0f,1.0f), glm::vec2(0.0f, 0.0f));
    obj.IsSolid = true;
    this->Entitys.push_back(obj);
    player = new Entity(TextureResourceManager::GetTexture("logo"), glm::vec2(100.0f, 10.0f), glm::vec2(40.0f, 40.0f), 0.0f, glm::vec3(1.0f,0.0f,0.0f), glm::vec2(0.0f, 0.0f));
}

void Game::Update(float dt)
{
    
}

void Game::ProcessInput(float dt)
{
    if (this->State == GAME_ACTIVE)
    {
        float velocity = 500 * dt;
        // move playerboard
        if (this->Keys[GLFW_KEY_A])
        {
            if (player->Position.x >= 0.0f)
                player->Position.x -= velocity;
        }
        if (this->Keys[GLFW_KEY_D])
        {
            if (player->Position.x <= this->Width - player->Size.x)
                player->Position.x += velocity;
        }
    }
}

void Game::Render()
{
    // Renderer->DrawSprite(glm::vec2(10.0f, 10.0f), glm::vec2(40.0f, 40.0f), 0.0f, glm::vec3(1.0f,1.0f,1.0f));
    for (Entity&tile : this->Entitys)
            tile.Draw(*Renderer);
    player->Draw(*Renderer);
}