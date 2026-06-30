#pragma once

#include <vector>

#include "Bullet.h"
#include "Player.h"

struct Enemy;

struct Engine {
    const int WIDTH=500;
    const int HEIGHT=900;

    float deltaTime{};

    Player player;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemys;

    void Initialize();

    void Update();

    void Render();
};
