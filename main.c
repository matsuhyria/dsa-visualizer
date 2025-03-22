#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <stdio.h>
#include <SDL3/SDL.h>

#define W_WIDTH 800
#define W_HEIGHT 600

typedef struct AppContext{
    SDL_Window* window;
    SDL_Renderer *renderer;
} App;

App app = {0};

int initSDL(void);
void cleanupSDL(void);
void mainLoop(void);
void prepareScene(void);
void presentScene(void);

int main(void) {
    if(!initSDL()) {
        cleanupSDL();
        return 1;
    }

    mainLoop();

    cleanupSDL();
    return 0;
}

int initSDL(void) {
    unsigned int initFlags = SDL_INIT_VIDEO | SDL_INIT_EVENTS;
    unsigned int windowFlags = SDL_WINDOW_HIDDEN;

    if(!SDL_Init(initFlags)) {
        SDL_Log("SDL_Init error: %s\n", SDL_GetError());
        return 0;
    }

    app.window = SDL_CreateWindow("DSA-Visualizer", W_WIDTH, W_HEIGHT, windowFlags);
    if(!app.window) {
        SDL_Log("SDL_CreateWindow error: %s\n", SDL_GetError());
        return 0;
    }

    app.renderer = SDL_CreateRenderer(app.window, NULL);
    if(!app.renderer) {
        SDL_Log("SDL_CreateRenderer error: %s\n", SDL_GetError());
        return 0;
    }

    SDL_ShowWindow(app.window);

    return 1;
}

void cleanupSDL(void) {
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
}

void mainLoop(void) {
    int running = 1;

    while(running) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_EVENT_QUIT:
                    running = 0;
                    break;
            }
        }

        prepareScene();
        presentScene();
        SDL_Delay(16);
    }
}

void prepareScene(void) {
    SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene(void) {
    SDL_RenderPresent(app.renderer);
}
