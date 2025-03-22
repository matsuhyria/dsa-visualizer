#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_hints.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#define W_WIDTH 800
#define W_HEIGHT 600

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;

App app;

void mainLoop(void);
void initSDL(void);
void getInput(void);
void cleanupSDL(void);

int main(void) {
    initSDL();

    mainLoop();
    cleanupSDL();
    return 0;
}

void mainLoop() {
    int running = 1;

    while(running) {
        getInput();
    }
}

void initSDL(void) {
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    app.window = SDL_CreateWindow("DSA-Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W_WIDTH, W_HEIGHT, windowFlags);

    if(!app.window) {
        printf("Failed to open SDL window: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    if(!app.renderer) {
        printf("Failed to create SDL renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
}

void getInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                cleanupSDL();
                exit(0);

            default:
                break;
        }
    }
}

void cleanupSDL(void) {
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
}
