#include <iostream>
#include "../src/fenorama.h"

#define WINDOW_WIDTH    960
#define WINDOW_HEIGHT 720

int main() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    SDL_Window* window = SDL_CreateWindow("Fenorama Test", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_UTILITY);

    FNGui test(window, nullptr);
    std::cout << "Hello, World!" << std::endl;

    SDL_Event e;
    bool quit = false;
    SDL_Surface * ssurface = SDL_GetWindowSurface(window);
    while(!quit) {
        SDL_FillRect(ssurface, nullptr, SDL_MapRGB( ssurface->format, 0xFF, 0xFF, 0xFF));
        SDL_UpdateWindowSurface(window);
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT)
                quit = true;
        }
        test.process();
    }

    SDL_DestroyWindow( window );
    SDL_Quit();

    return 0;
}
