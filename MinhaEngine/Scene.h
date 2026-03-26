#pragma once
#include <SDL3/SDL.h>

class Scene {
public:
    virtual void init(SDL_Renderer* renderer) = 0;
    virtual void handleInput(const bool* keystate, float deltaTime) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void clean() = 0;

    virtual ~Scene() {}
};