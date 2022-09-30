#include "../inc/game.h"

int main(int argc, char *argv[]) {
    
    int arg_c = argc;   //probka 
    char *arg = argv[0];
    if(!arg) { arg_c = 0; }
    
    int WIDTH = 800, HEIGHT = 600;
    
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        printf("error init: %s \n", SDL_GetError() );
        exit(-1);
    }
    if (TTF_Init() < 0) {
        printf("error ttf init: %s \n", SDL_GetError() );
    }

    SDL_Window *window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    Uint32 renderer_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, renderer_flags);

    // game funcs
    mx_menu(window, renderer);

   
    return 0;
}
