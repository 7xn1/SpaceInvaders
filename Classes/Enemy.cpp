//
// Created by Ollie on 6/29/2026.
//

#include "Enemy.h"

#include "TextureManager.h"

void Enemy::Load() {
    enemyTexture=TextureManager::GetTexture("enemy");
}

void Enemy::Update(const float deltaTime) {
    position.x+=velocity.x*deltaTime;
    position.y+=velocity.y*deltaTime;
}

void Enemy::Draw() const {
    const float scale=WIDTH/enemyTexture.width;

    DrawTextureEx(enemyTexture,position,0.0f,scale, WHITE);
}
