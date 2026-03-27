#include "Engine.h"
#include <iostream>



bool Engine::init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Erro ao iniciar SDL: " << SDL_GetError() << "\n";
        return false;
    }

    // Criar janela
    window = SDL_CreateWindow("Minha Engine", 1000, 800, 0);
    if (!window) {
        std::cout << "Erro ao criar janela: " << SDL_GetError() << "\n";
        return false;
    }

    // Criar renderer
    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        std::cout << "Erro ao criar renderer: " << SDL_GetError() << "\n";
        return false;
    }

    // Criar scene
    

    running = true;

    return true;
}

void Engine::setScene(Scene* newScene) {
    scene = newScene;
    scene->init(renderer);
}

void Engine::run() {
    SDL_Event event;

    Uint64 lastTime = SDL_GetTicks();

    while (running) {

        // INPUT
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        Uint64 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;


        const bool* keystate = SDL_GetKeyboardState(NULL);

        scene->handleInput(keystate, deltaTime);

        // UPDATE
        scene->update(deltaTime);

        // RENDER
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        scene->render(renderer);

        SDL_RenderPresent(renderer);
    }
}

void Engine::clean() {
    scene->clean();
    delete scene;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}