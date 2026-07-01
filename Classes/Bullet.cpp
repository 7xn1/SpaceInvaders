#include "Bullet.h"

#include <raylib.h>

void Bullet::Update(const float deltaTime) {
    position.x+=velocity.x*deltaTime;
    position.y+=velocity.y*deltaTime;
}

void Bullet::Draw() const {
    DrawRectangleV(position,{5,20}, RED);
}
