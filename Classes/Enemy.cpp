//
// Created by Ollie on 6/29/2026.
//

#include "Enemy.h"

void Enemy::Initialize() {
    enemyImage = LoadImage("resources/enemy.png");
    enemyTexture = LoadTextureFromImage(enemyImage);

    UnloadImage(enemyImage);
}

void Enemy::Update(const float deltaTime) {
    position.x+=velocity.x*deltaTime;
    position.y+=velocity.y*deltaTime;
}

