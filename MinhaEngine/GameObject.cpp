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

void GameObject::setState(AnimState newState) {

    if (currentState != newState) {
        currentState = newState;
        frame = 0;
        currentTime = 0.0f;

        switch (currentState) {
        case AnimState::IDLE:
            frameCount = 2;
            startX = 0;
            break;

        case AnimState::RUN:
            frameCount = 4;
            startX = 2;
            break;
        }
    }
}

void GameObject::update(float deltaTime) {

    currentTime += deltaTime;

    if (currentTime >= frameTime) {
        frame++;
        currentTime = 0.0f;

        if (frame >= frameCount)
            frame = 0;
    }
    

    srcRect.x = (startX + frame) * frameWidth;
    srcRect.y = 0;
    srcRect.w = frameWidth;
    srcRect.h = frameHeight;
    
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
    SDL_FRect destRect = {
        x - camX,
        y - camY,
        width,
        height
    };

    if (texture) {

        SDL_FlipMode flipMode = flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

        SDL_RenderTextureRotated(
            renderer,
            texture,
            &srcRect,
            &destRect,
            0.0,      // rotação
            NULL,     // centro
            flipMode  // 👈 aqui acontece o flip
        );

        SDL_RenderTexture(renderer, texture, &srcRect, &destRect);
    }
    else {
        // fallback (caso não tenha imagem)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &destRect);
        SDL_RenderFillRect(renderer, &destRect);
    }
}

