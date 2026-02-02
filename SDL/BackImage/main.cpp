#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    // 1. Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    // 2. Initialize SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        cout << "IMG Init Error: " << IMG_GetError() << endl;
        return 1;
    }

    // 3. Create Window
    SDL_Window* window = SDL_CreateWindow(
        "SDL Background Image",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    // 4. Create Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    // 5. Load Image as Surface
    SDL_Surface* bgSurface = IMG_Load("background.png");
    if (!bgSurface) {
        cout << "Image Load Error: " << IMG_GetError() << endl;
        return 1;
    }

    // 6. Convert Surface to Texture
    SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
    SDL_FreeSurface(bgSurface); // Surface دیگه لازم نیست

    // 7. Main Loop
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        // 8. Clear screen
        SDL_RenderClear(renderer);

        // 9. Draw background
        SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
        // NULL, NULL یعنی:
        // کل عکس → کل صفحه

        // 10. Show result
        SDL_RenderPresent(renderer);
    }

    // 11. Cleanup
    SDL_DestroyTexture(bgTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}
