#include "../inc/game.h"

void mx_render_tower_selection(SDL_Renderer *renderer, int m_x, int m_y, int s_x) {
    int x5 = 0;
    int x1 = 0;
    int x2 = 0;
    if (m_x == 0) { // ->
        x1 = 75;
    }
    else if (m_x == 9) { // <- 
        x1 = -75;
    }
    else { // m_x -> 50/2 + 75 * m_x            m_y -> 75/2 + 75*m_y         10 + 75 + 10 + (m_x)75 + 10 + 75 + 10        
        x1 = 0;
    }
    if (s_x == 0) 
        x5 = -85;
    else if (s_x == 2) 
        x5 = 85;
    
    if (m_y != 6) { 
        x2 = 0;
    }
    else if (m_y == 6) { //  ^
        x2 = - 190;
    }
        SDL_Rect rec1m = {50/2 + 75*m_x - 95 + x1,   75/2 + 75*(m_y+1) + 10 + x2,     10 + 75 + 10 + 75 + 10 + 75 + 10, 10 + 75 + 10 + 20 + 10};
        SDL_Rect rec2t1 = {50/2 + 75*m_x - 85 + x1,  75/2 + 75*(m_y+1) + 20 + x2,     75, 75};
        SDL_Rect rec3t2 = {50/2 + 75*m_x + x1,      75/2 + 75*(m_y+1) + 20 + x2,           75, 75};
        SDL_Rect rec4t3 = {50/2 + 75*m_x + 85 + x1,  75/2 + 75*(m_y+1) + 20 + x2,          75, 75};

        SDL_Surface *surface1 = IMG_Load("resources/grey.png");
        SDL_Surface *surface2 = IMG_Load("resources/tower1.png");
        SDL_Surface *surface3 = IMG_Load("resources/tower3.png");
        SDL_Surface *surface4 = IMG_Load("resources/tower2.png");
        SDL_Texture *rec1m_txtr = SDL_CreateTextureFromSurface(renderer, surface1);
        SDL_Texture *rec2t1_txtr = SDL_CreateTextureFromSurface(renderer, surface2);
        SDL_Texture *rec3t2_txtr = SDL_CreateTextureFromSurface(renderer, surface3);
        SDL_Texture *rec4t3_txtr = SDL_CreateTextureFromSurface(renderer, surface4);
        
        SDL_RenderCopy(renderer, rec1m_txtr, NULL, &rec1m);
        SDL_RenderCopy(renderer, rec2t1_txtr, NULL, &rec2t1);
        SDL_RenderCopy(renderer, rec3t2_txtr, NULL, &rec3t2);
        SDL_RenderCopy(renderer, rec4t3_txtr, NULL, &rec4t3);
        SDL_FreeSurface(surface1);
        SDL_FreeSurface(surface2);
        SDL_FreeSurface(surface3);
        SDL_FreeSurface(surface4);
        SDL_DestroyTexture(rec1m_txtr);
        SDL_DestroyTexture(rec2t1_txtr);
        SDL_DestroyTexture(rec3t2_txtr);

            TTF_Font* font1 = TTF_OpenFont("resources/font1.ttf", 20);
            SDL_Color color1 = { 255, 255, 65, 255};
            SDL_Surface* surface11 = TTF_RenderText_Solid( font1, "5", color1);
            SDL_Texture* text1_texture = SDL_CreateTextureFromSurface( renderer, surface11);
            SDL_Rect rec11 = { 50/2 + 75*m_x - 55 + x1,             75/2 + 75*(m_y+1) + 20 + 85 + x2, 15, 20 };
            SDL_RenderCopy( renderer, text1_texture, NULL, &rec11);
            SDL_FreeSurface(surface11);
            SDL_DestroyTexture(text1_texture);
            
            TTF_Font* font2 = TTF_OpenFont("resources/font1.ttf", 20);
            SDL_Color color2 = { 255, 255, 65, 255};
            SDL_Surface* surface12 = TTF_RenderText_Solid( font2, "10", color2);
            SDL_Texture* text2_texture = SDL_CreateTextureFromSurface( renderer, surface12);
            SDL_Rect rec12 = { 50/2 + 75*m_x + x1 + 22,             75/2 + 75*(m_y+1) + 20 + 85 + x2, 30, 20 };
            SDL_RenderCopy( renderer, text2_texture, NULL, &rec12);
            SDL_FreeSurface(surface12);
            SDL_DestroyTexture(text2_texture);

            TTF_Font* font3 = TTF_OpenFont("resources/font1.ttf", 20);
            SDL_Color color3 = { 255, 255, 65, 255};
            SDL_Surface* surface13 = TTF_RenderText_Solid( font3, "20", color3);
            SDL_Texture* text3_texture = SDL_CreateTextureFromSurface( renderer, surface13);
            SDL_Rect rec13 = { 50/2 + 75*m_x + 107 + x1,             75/2 + 75*(m_y+1) + 20 + 85 + x2, 30, 20 };
            SDL_RenderCopy( renderer, text3_texture, NULL, &rec13);
            SDL_FreeSurface(surface13);
            SDL_DestroyTexture(text3_texture);
    
    SDL_Rect rec1 = {50/2 + 75*m_x + x5 + x1,      75/2 + 75*(m_y+1) + 20 + x2,     75, 75};
    SDL_Surface *surface5 = IMG_Load("resources/uiselection.png");
    SDL_Texture *rec1_txtr = SDL_CreateTextureFromSurface(renderer, surface5);
    SDL_RenderCopy(renderer, rec1_txtr, NULL, &rec1);
    SDL_FreeSurface(surface5);
    SDL_DestroyTexture(rec1_txtr);
    TTF_CloseFont(font1);
    TTF_CloseFont(font2);
    TTF_CloseFont(font3);
}

