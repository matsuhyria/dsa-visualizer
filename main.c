#include <SDL2/SDL.h>

#define W_WIDTH 800
#define W_HEIGHT 600

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("DSA-Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W_WIDTH, W_HEIGHT, 0);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    while(1) {
        if(SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            break;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
