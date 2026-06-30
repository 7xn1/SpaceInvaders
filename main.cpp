#include <iostream>

#include "raylib.h"
#include "Classes/Engine.h"

int main() {
    std::cout<<"Loading Game..."<<std::endl;

    // Game Runtime //

    Engine engine;

    engine.Initialize();

    while (!WindowShouldClose()) {
        engine.Update();
        engine.Render();
    }

    // Application Close //

    engine.player.Unload();

    CloseWindow();

    return 0;
}
