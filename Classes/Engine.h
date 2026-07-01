#pragma once

#include <vector>

#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"

struct Engine {
    const int WIDTH=500;
    const int HEIGHT=900;

    float deltaTime{};

    Player player;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;

    Image backgroundImage;
    Texture2D backgroundTexture;

    void Initialize();

    void Update();

    void Render() const;
};
