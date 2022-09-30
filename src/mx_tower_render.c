#include "../inc/game.h"


void mx_tower_render(SDL_Renderer *renderer, tower_t **tower ) {
    for(int i = 0; tower[i] != NULL; i++) {
        SDL_Rect test1 = {tower[i]->x - 75 / 2, tower[i]->y - 75 / 2, 75, 75};
    
        SDL_Surface *tempSurface = IMG_Load(tower[i]->tex_frame_path);
        SDL_Texture *test_txtr = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);

        SDL_RenderCopy(renderer, test_txtr, NULL, &test1);

        SDL_DestroyTexture(test_txtr);
    }

}

