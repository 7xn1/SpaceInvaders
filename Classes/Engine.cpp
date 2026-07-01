#include "Engine.h"

#include <algorithm>
#include <raylib.h>

#include "TextureManager.h"

void Engine::Initialize() {
    InitWindow(WIDTH,HEIGHT,"Space Invaders");

    TextureManager::LoadTexture("player","resources/ship.png");
    TextureManager::LoadTexture("enemy","resources/enemy.png");

    player.Load();

    for(int i=0; i<7; i++) {
        Enemy enemy;
        enemy.Load();

        enemy.position={
            static_cast<float>(GetRandomValue(0,WIDTH-static_cast<int>(Enemy::WIDTH))),
            static_cast<float>(-GetRandomValue(0,500))
        };

        enemy.velocity={0.0f,70.0f};

        enemies.push_back(enemy);
    }
}

void Engine::Update() {
    deltaTime=GetFrameTime();

    player.Update(deltaTime);
    player.HandleShooting(bullets,deltaTime);

    for(Bullet &bullet: bullets)
        bullet.Update(deltaTime);

    bullets.erase(
        std::ranges::remove_if(bullets
                               ,
                               [](const Bullet &bullet) {
                                   return bullet.position.y<-20.0f;
                               }).begin(),
        bullets.end());

    for(Enemy &enemy: enemies)
        enemy.Update(deltaTime);

    for(auto &[position, velocity]: bullets) {
        const Rectangle bulletRect={
            position.x,
            position.y,
            5.0f,
            20.0f
        };

        for(Enemy &enemy: enemies) {
            if(CheckCollisionRecs(bulletRect,enemy.GetRect())) {
                enemy.health-=50;

                position.y=-100.0f;

                break;
            }
        }
    }

    enemies.erase(
        std::ranges::remove_if(enemies
                               ,
                               [](const Enemy &enemy) {
                                   return enemy.health<=0;
                               }).begin(),
        enemies.end());

    while(enemies.size()<7) {
        Enemy enemy;
        enemy.Load();

        enemy.position={
            static_cast<float>(GetRandomValue(0,WIDTH-static_cast<int>(Enemy::WIDTH))),
            -Enemy::HEIGHT
        };

        enemy.velocity={0.0f,80.0f};

        enemies.push_back(enemy);
    }

    for(const Enemy &enemy: enemies) {
        if(enemy.position.y+Enemy::HEIGHT>=player.position.y) {
            player.lives--;
            player.Respawn();

            enemies.clear();

            for(int i=0; i<7; i++) {
                Enemy newEnemy;
                newEnemy.Load();

                newEnemy.position={
                    static_cast<float>(GetRandomValue(0,WIDTH-static_cast<int>(Enemy::WIDTH))),
                    static_cast<float>(-GetRandomValue(0,500))
                };

                newEnemy.velocity={0.0f,80.0f};

                enemies.push_back(newEnemy);
            }

            break;
        }
    }
}

void Engine::Render() const {
    BeginDrawing();
    ClearBackground(BLACK);

    player.Draw();

    for(const Enemy &enemy: enemies)
        enemy.Draw();

    for(const Bullet &bullet: bullets)
        bullet.Draw();

    EndDrawing();
}
