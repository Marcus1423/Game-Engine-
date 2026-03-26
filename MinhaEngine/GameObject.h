#pragma once
#include <SDL3/SDL.h>

class GameObject {
public:
    float x, y;
    float width, height;

    GameObject(float x, float y, float w, float h);

    void update(float deltaTime);
    void render(SDL_Renderer* renderer);
};