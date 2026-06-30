#pragma once

#include <vector>

#include "Bullet.h"
#include "Player.h"

struct Engine {
    const int WIDTH=500;
    const int HEIGHT=900;

    float deltaTime{};

    Player player;
    std::vector<Bullet> bullets;

    void Initialize();

    void Update();

    void Render();
};
