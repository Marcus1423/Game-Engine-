#pragma once
#include <SDL3/SDL.h>
#include "GameObject.h"

class Engine {
public:
    bool init();
    void run();
    void clean();
    float x = 300;
    float y = 200;
    float speed = 300.0f;

private:
    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    GameObject* player;
    bool running = false;
};