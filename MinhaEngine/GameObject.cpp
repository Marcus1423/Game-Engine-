#include "GameObject.h"

GameObject::GameObject(float x, float y, float w, float h)
    : x(x), y(y), width(w), height(h) {
}

void GameObject::update(float deltaTime) {
    // depois você coloca lógica aqui
}

void GameObject::render(SDL_Renderer* renderer) {
    SDL_FRect rect = { x, y, width, height };

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}