#pragma once

#include <raylib.h>
#include <string>
#include <unordered_map>

class TextureManager {
public:
    static void LoadTexture(const std::string &name,const std::string &path);

    static Texture2D &GetTexture(const std::string &name);

    static void UnloadAll();

private:
    static inline std::unordered_map<std::string,Texture2D> textures;
};
