#include "Engine.h"
#include <iostream>



bool Engine::init() {

    player = new GameObject(300, 200, 200, 150);

    // 1. Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Erro ao iniciar SDL\n";
        return false;
    }

    // 2. Criar janela
    window = SDL_CreateWindow("Minha Engine", 800, 600, 0);

    if (!window) {
        std::cout << "Erro ao criar janela\n";
        return false;
    }

    // 3. Criar renderer
    renderer = SDL_CreateRenderer(window, NULL);

    if (!renderer) {
        std::cout << "Erro ao criar renderer\n";
        return false;
    }

    running = true;
    return true;
}

void Engine::run() {
    SDL_Event event;
    

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        // INPUT
        const bool* keystate = SDL_GetKeyboardState(NULL);
        float deltaTime = 0.016f;

        if (keystate[SDL_SCANCODE_W]) player->y -= 300 * deltaTime;
        if (keystate[SDL_SCANCODE_S]) player->y += 300 * deltaTime;
        if (keystate[SDL_SCANCODE_A]) player->x -= 300 * deltaTime;
        if (keystate[SDL_SCANCODE_D]) player->x += 300 * deltaTime;

        // UPDATE
        player->update(deltaTime);

        // RENDER
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        player->render(renderer);

        SDL_RenderPresent(renderer);
    }
}

void Engine::clean() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}