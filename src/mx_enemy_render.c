#include "../inc/game.h"


void mx_enemy_render(SDL_Renderer *renderer, enemy_t **enemy ) {
    for(int i = 0; enemy[i] != NULL; i++) {
        SDL_Rect test1 = {enemy[i]->x - 50 / 2, enemy[i]->y - 50 / 2, 50, 50};       //start cordinates of enemy and two last args = width and height
    
        SDL_Surface *tempSurface = IMG_Load(enemy[i]->tex_main_path); 
        SDL_Texture *test_txtr = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);

        SDL_RenderCopy(renderer, test_txtr, NULL, &test1);

        SDL_DestroyTexture(test_txtr);
    }


}

