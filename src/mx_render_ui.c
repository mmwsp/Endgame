#include "../inc/game.h"

void mx_render_ui(SDL_Renderer *renderer, int m_x, int m_y) {
    { // m_x -> 50/2 + 75 * m_x            m_y -> 75/2 + 75*m_y         10 + 75 + 10 + (m_x)75 + 10 + 75 + 10        
        SDL_Rect rec1 = {25 + 75*m_x, 37 + 75*m_y, 75, 75};

        SDL_Surface *surface1 = IMG_Load("resources/uiselection.png");

        SDL_Texture *rec1_txtr = SDL_CreateTextureFromSurface(renderer, surface1);

        SDL_RenderCopy(renderer, rec1_txtr, NULL, &rec1);

        SDL_FreeSurface(surface1);

        SDL_DestroyTexture(rec1_txtr);
    }
    
}

