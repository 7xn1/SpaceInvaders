#include "TextureManager.h"

#include <ranges>
#include <stdexcept>

void TextureManager::LoadTexture(const std::string &name,const std::string &path) {
    if(textures.contains(name))
        return;

    const Texture2D tex=::LoadTexture(path.c_str());

    if(tex.id==0)
        throw std::runtime_error("Failed to load texture: "+path);

    textures[name]=tex;
}

Texture2D &TextureManager::GetTexture(const std::string &name) {
    return textures.at(name);
}

void TextureManager::UnloadAll() {
    for(const auto &tex: textures|std::views::values) {
        UnloadTexture(tex);
    }

    textures.clear();
}
