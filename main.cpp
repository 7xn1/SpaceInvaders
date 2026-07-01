#include <iostream>

#include "raylib.h"
#include "Classes/Engine.h"
#include "Classes/TextureManager.h"

int main(int argc,char* argv[]) {
    std::cout<<"Loading Game..."<<std::endl;

    // Game Runtime //

    Engine engine;

    engine.Initialize();

    while (!WindowShouldClose()) {
        engine.Update();
        engine.Render();
    }

    // Application Close //

    TextureManager::UnloadAll();

    CloseWindow();

    return 0;
}
