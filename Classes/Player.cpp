#include "Player.h"

#include <raylib.h>

void Player::Load() {
    playerImage=LoadImage("resources/ship.png");
    playerTexture=LoadTextureFromImage(playerImage);

    UnloadImage(playerImage);

    position={210.0f,800.0f};
}

void Player::Unload() const {
    UnloadTexture(playerTexture);
}

void Player::Update(float deltaTime) {
    HandleInput(deltaTime);
    HandleBounds();
}

void Player::Draw() const {
    DrawTextureEx(
        playerTexture,
        position,
        0.0f,
        width/playerTexture.width,
        WHITE
    );
}

void Player::HandleInput(float deltaTime) {
    if(IsKeyDown(KEY_RIGHT))
        position.x+=moveSpeed*deltaTime;

    if(IsKeyDown(KEY_LEFT))
        position.x-=moveSpeed*deltaTime;
}

void Player::HandleBounds() {
    if(position.x<0.0f)
        position.x=0.0f;

    float playerWidth=playerTexture.width*(width/playerTexture.width);

    if(position.x+playerWidth>500.0f)
        position.x=500.0f-playerWidth;
}

void Player::HandleShooting(std::vector<Bullet> &bullets,float deltaTime) {
    shootTimer-=deltaTime;

    if(shootTimer<0.0f)
        shootTimer=0.0f;

    if(IsKeyPressed(KEY_SPACE)&&shootTimer<=0.0f) {
        Bullet bullet;

        bullet.position={
            position.x+width/2.0f-2.5f,
            position.y
        };

        bullet.velocity={0.0f,-700.0f};

        bullets.push_back(bullet);

        shootTimer=shootCooldown;
    }
}

void Player::Respawn() {
    position={210.0f,800.0f};
}
