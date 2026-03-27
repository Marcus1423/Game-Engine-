#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Camera.h"
#include <vector>

class GameScene : public Scene {
public:
    void init(SDL_Renderer* renderer) override;
    void handleInput(const bool* keystate, float deltaTime) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    void clean() override;

private:
    std::vector<GameObject*> objects;
    Camera camera;
};
