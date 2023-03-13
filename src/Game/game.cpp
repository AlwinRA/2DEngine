#include "game.h"
#include "../ResourceManager/texture_resource_manager.h"
// Game-related State data
SpriteRenderer  *Renderer;
// Initial size of the player paddle
const glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
// Initial velocity of the player paddle
const float PLAYER_VELOCITY(500.0f);
// Initial velocity of the Ball
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// Radius of the ball object
const float BALL_RADIUS = 12.5f;

Ball   *Ball_o; 
Entity  *Player;

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
    TextureResourceManager::LoadTexture("../Texture/background.jpg", false, "background");
    TextureResourceManager::LoadTexture("../Texture/block.png", false, "block");
    TextureResourceManager::LoadTexture("../Texture/block_solid.png", false, "block_solid");
    TextureResourceManager::LoadTexture("../Texture/paddle.png", true, "paddle");
    TextureResourceManager::LoadTexture("../Texture/awesomeface.png", true, "face");
    // load levels
    GameLevel one; one.Load("../src/one.lvl", this->Width, this->Height / 2);
    this->Levels.push_back(one);
    this->Level = 0;

    glm::vec2 playerPos = glm::vec2(
        this->Width / 2.0f - PLAYER_SIZE.x / 2.0f, 
        this->Height - PLAYER_SIZE.y
    );
    Player = new Entity(TextureResourceManager::GetTexture("paddle"), playerPos, PLAYER_SIZE, 0.0f, glm::vec3(1.0f));
    glm::vec2 ballPos = playerPos + glm::vec2(PLAYER_SIZE.x / 2.0f - BALL_RADIUS, -BALL_RADIUS * 2.0f);
    Ball_o = new Ball(TextureResourceManager::GetTexture("face"), ballPos, BALL_RADIUS, INITIAL_BALL_VELOCITY);
}

void Game::Update(float dt)
{
    Ball_o->Move(dt, this->Width);
}

void Game::ProcessInput(float dt)
{
 if (this->State == GAME_ACTIVE)
    {
        float velocity = PLAYER_VELOCITY * dt;
        // move playerboard
        if (this->Keys[GLFW_KEY_A])
        {
            if (Player->Position.x >= 0.0f)
            {
                Player->Position.x -= velocity;
                if (Ball_o->Stuck)
                    Ball_o->Position.x -= velocity;
            }
        }
        if (this->Keys[GLFW_KEY_D])
        {
            if (Player->Position.x <= this->Width - Player->Size.x)
            {
                Player->Position.x += velocity;
                if (Ball_o->Stuck)
                    Ball_o->Position.x += velocity;
            }
        }
        if (this->Keys[GLFW_KEY_SPACE])
            Ball_o->Stuck = false;
    }
}

void Game::Render()
{
    if(this->State == GAME_ACTIVE)
    {
        // draw background
        Renderer->DrawSprite(TextureResourceManager::GetTexture("background"), 
            glm::vec2(0.0f, 0.0f), glm::vec2(this->Width, this->Height), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
        // draw level
        this->Levels[this->Level].Draw(*Renderer);
    }
    Player->Draw(*Renderer);
    Ball_o->Draw(*Renderer);
}