#include "Engine.h"

#include <algorithm>
#include <raylib.h>

void Engine::Initialize() {
    const int monitorIndex=GetCurrentMonitor();

    InitWindow(WIDTH,HEIGHT,"Space Invaders");
    SetTargetFPS(GetMonitorRefreshRate(monitorIndex));

    player.Load();
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
                               [](const Bullet &b) {
                                   return b.position.y<-20.0f;
                               }
        ).begin(),
        bullets.end()
    );
}

void Engine::Render() {
    BeginDrawing();

    ClearBackground(BLACK);

    player.Draw();

    for(Bullet &bullet: bullets) {
        bullet.Draw();
    }

    EndDrawing();
}
