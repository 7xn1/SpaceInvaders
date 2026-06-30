#pragma once
#include "raylib.h"

struct Enemy {
    Vector2 position{};
    Vector2 velocity{};

    Image enemyImage{};
    Texture2D enemyTexture{};

    int health=100;

    void Initialize();

    void Update(float deltaTime);

    void HandleBounds();

    void OnBulletCollision();
};
