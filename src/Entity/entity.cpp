#include "entity.h"

Entity::Entity() 
    : Position(0.0f, 0.0f), Size(10.0f, 10.0f), Velocity(0.0f), Color(1.0f), Rotation(0.0f), Sprite(), IsSolid(false), Destroyed(false) { }

Entity::Entity(Texture sprite, glm::vec2 pos, glm::vec2 size, float rotation, glm::vec3 color, glm::vec2 velocity) 
    : Position(pos), Size(size), Velocity(velocity), Color(color), Rotation(0.0f), Sprite(sprite), IsSolid(false), Destroyed(false) { }

void Entity::Draw(SpriteRenderer &renderer)
{
    renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}