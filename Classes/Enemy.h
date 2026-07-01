#pragma once
#include "raylib.h"

struct Enemy {
    Vector2 position{};
    Vector2 velocity{};

    Texture2D enemyTexture{};

    static constexpr float WIDTH=64.0f;
    static constexpr float HEIGHT=64.0f;
    static constexpr float SCREEN_WIDTH=500.0f;

    int health=100;
    bool alive=true;

    Rectangle GetRect() const {
        return {
            position.x,
            position.y,
            WIDTH,
            HEIGHT
        };
    }

    void Load();

    void Update(float deltaTime);

    void Draw() const;
};
