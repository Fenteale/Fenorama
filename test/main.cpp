#include <iostream>
#include "../src/fenorama.h"

#define WINDOW_WIDTH    960
#define WINDOW_HEIGHT 720

int main() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT,
                                SDL_WINDOW_SHOWN | SDL_WINDOW_UTILITY, &window, &renderer);
    FNGui test(window, renderer);
    std::cout << "Current path: " << fs::current_path().string() << std::endl;
    test.loadLayout("test.html", 0, 0, 0, 0);

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
