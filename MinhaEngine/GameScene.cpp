#include "GameScene.h"
#include <SDL3/SDL.h>

void GameScene::init(SDL_Renderer* renderer) {
    GameObject* player = new GameObject(300, 200, 100, 100);
    player->loadTexture(renderer, "player.png");

    objects.push_back(player);

    // Outros objetos (obstáculos)
    objects.push_back(new GameObject(100, 100, 100, 100));
    objects.push_back(new GameObject(500, 300, 150, 150));
}

void GameScene::update(float deltaTime) {

    GameObject* player = objects[0];

    camera.follow(player->x, player->y);

    for (auto obj : objects) {
        obj->update(deltaTime);
    }

    for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = i + 1; j < objects.size(); j++) {

            if (objects[i]->checkCollision(objects[j])) {

                // TESTE VISUAL: mudar cor
                objects[i]->width += 1; // só pra ver que colidiu
            }
        }
    }
}

void GameScene::render(SDL_Renderer* renderer) {
    for (auto obj : objects) {
        obj->render(renderer, camera.x, camera.y);
    }
}

void GameScene::handleInput(const bool* keystate, float deltaTime) {
    GameObject* player = objects[0];

    float oldX = player->x;
    float oldY = player->y;

    if (keystate[SDL_SCANCODE_W]) player->y -= 500 * deltaTime;
    if (keystate[SDL_SCANCODE_S]) player->y += 500 * deltaTime;
    if (keystate[SDL_SCANCODE_A]) player->x -= 500 * deltaTime;
    if (keystate[SDL_SCANCODE_D]) player->x += 500 * deltaTime;

    for (auto obj : objects) {
        if (obj != player && player->checkCollision(obj)) {
            player->x = oldX;
            player->y = oldY;
        }
    }
}

void GameScene::clean() {
    for (auto obj : objects) {
        delete obj;
    }
    objects.clear();
}