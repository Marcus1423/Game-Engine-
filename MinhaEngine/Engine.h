#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "GameObject.h"
#include "Scene.h"

class Engine {
public:
    bool init();
    void run();
    void clean();
    void setScene(Scene* newScene); 

private:
    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    bool running = false;

    Scene* scene;
};