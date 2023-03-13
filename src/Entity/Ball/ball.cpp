#include "ball.h"


Ball::Ball() 
    : Entity(), Radius(12.5f), Stuck(true) { }

Ball::Ball(Texture sprite, glm::vec2 pos, float radius, glm::vec2 velocity)
    : Entity(sprite, pos, glm::vec2(radius * 2.0f, radius * 2.0f), 0.0f, glm::vec3(1.0f), velocity), Radius(radius), Stuck(true) { }

glm::vec2 Ball::Move(float dt, unsigned int window_width)
{
    // if not stuck to player board
    if (!this->Stuck)
    {
        // move the Ball
        this->Position += this->Velocity * dt;
        // then check if outside window bounds and if so, reverse velocity and restore at correct position
        if (this->Position.x <= 0.0f)
        {
            this->Velocity.x = -this->Velocity.x;
            this->Position.x = 0.0f;
        }
        else if (this->Position.x + this->Size.x >= window_width)
        {
            this->Velocity.x = -this->Velocity.x;
            this->Position.x = window_width - this->Size.x;
        }
        if (this->Position.y <= 0.0f)
        {
            this->Velocity.y = -this->Velocity.y;
            this->Position.y = 0.0f;
        }
    }
    return this->Position;
}

// resets the Ball to initial Stuck Position (if Ball is outside window bounds)
void Ball::Reset(glm::vec2 position, glm::vec2 velocity)
{
    this->Position = position;
    this->Velocity = velocity;
    this->Stuck = true;
}