#pragma once

#include <vector>
#include <raylib.h>
#include "Bullet.h"

struct Player {
    Vector2 position{};
    Vector2 velocity{};

    float moveSpeed=350.0f;

    static constexpr float WIDTH=96.0f;
    static constexpr float HEIGHT=96.0f;

    static constexpr float SCREEN_WIDTH=500.0f;

    int lives=3;
    bool alive=true;

    float shootCooldown=0.25f;
    float shootTimer=0.0f;

    Texture2D playerTexture{};

    void Load();

    void Update(float deltaTime);

    void Draw() const;

    void HandleInput(float deltaTime);

    void HandleBounds();

    void HandleShooting(std::vector<Bullet> &bullets,float deltaTime);

    void Respawn();
};
