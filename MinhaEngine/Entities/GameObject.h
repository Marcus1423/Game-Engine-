#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>


class GameObject {
public:
    float x, y;
    float width, height;

    GameObject(float x, float y, float w, float h);

    void update(float deltaTime);
    void render(SDL_Renderer* renderer, float camX, float camY);

    bool checkCollision(GameObject* other) const;
    bool loadTexture(SDL_Renderer* renderer, const std::string& path);

private:
    SDL_Texture* texture = nullptr;
};