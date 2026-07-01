#include "Player.h"
#include "TextureManager.h"
#include <raylib.h>

void Player::Load() {
    playerTexture=TextureManager::GetTexture("player");
    position={210.0f,800.0f};
}

void Player::Update(float deltaTime) {
    HandleInput(deltaTime);
    HandleBounds();
}

void Player::Draw() const {
    const float scale=WIDTH/playerTexture.width;

    DrawTextureEx(playerTexture,position,0.0f,scale, WHITE);
}

void Player::HandleInput(float deltaTime) {
    if(IsKeyDown(KEY_RIGHT))
        position.x+=moveSpeed*deltaTime;

    if(IsKeyDown(KEY_LEFT))
        position.x-=moveSpeed*deltaTime;
}

void Player::HandleBounds() {
    const float scale=WIDTH/playerTexture.width;
    const float playerWidth=playerTexture.width*scale;

    if(position.x<0.0f)
        position.x=0.0f;

    if(position.x+playerWidth>SCREEN_WIDTH)
        position.x=SCREEN_WIDTH-playerWidth;
}

void Player::HandleShooting(std::vector<Bullet> &bullets,float deltaTime) {
    shootTimer=std::max(0.0f,shootTimer-deltaTime);

    if(IsKeyPressed(KEY_SPACE)&&shootTimer==0.0f) {
        bullets.push_back({
            {position.x+WIDTH/2.0f-2.5f,position.y},
            {0.0f,-700.0f}
        });

        shootTimer=shootCooldown;
    }
}

void Player::Respawn() {
    position={210.0f,800.0f};
}
