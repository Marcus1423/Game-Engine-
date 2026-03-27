#include "GameObject.h"

GameObject::GameObject(float x, float y, float w, float h)
    : x(x), y(y), width(w), height(h) {
}

bool GameObject::loadTexture(SDL_Renderer* renderer, const std::string& path) {

    SDL_Surface* surface = IMG_Load(path.c_str());

    if (!surface) {
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);

    return texture != nullptr;
}

void GameObject::update(float deltaTime) {
    
}

bool GameObject::checkCollision(GameObject* other) const {
    return (
        x < other->x + other->width &&
        x + width > other->x &&
        y < other->y + other->height &&
        y + height > other->y
        );
}

void GameObject::render(SDL_Renderer* renderer, float camX, float camY) {
    SDL_FRect rect = {
        x - camX,
        y - camY,
        width,
        height
    };

    if (texture) {
        SDL_RenderTexture(renderer, texture, NULL, &rect);
    }
    else {
        // fallback (caso não tenha imagem)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}

