#include "display.h"

bool initDisplay() {

    SCREEN_WIDTH = 640;
    SCREEN_HEIGHT = 320;

    window = NULL;
    screenSurface = NULL;

    // setting up SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("Chip8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            screenSurface = SDL_GetWindowSurface(window);

            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

            SDL_UpdateWindowSurface(window);

            SDL_Delay(2000);
        }
    }

    return true;
}

bool closeDisplay() {

    SDL_DestroyWindow(window);

    SDL_Quit();

    return true;
}
