#include "../inc/game.h"

void mx_projectile_render(SDL_Renderer *renderer, projectile_t **projectile ) {
    for(int i = 0; projectile[i] != NULL; i++) {
        SDL_Rect test1 = {projectile[i]->x - 20 / 2, projectile[i]->y - 20 / 2, 20, 20};  
    
        SDL_Surface *tempSurface = IMG_Load(projectile[i]->tex_main_path);
        SDL_Texture *test_txtr = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);

        SDL_RenderCopy(renderer, test_txtr, NULL, &test1);

        SDL_DestroyTexture(test_txtr);
    }
    
}

