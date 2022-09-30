#include "../inc/game.h"

void mx_render_ttfs(SDL_Renderer *renderer, int money, int health, int score) {


    char textx[] = { ' ', ' ', ' ', ' ', ' '};

    char *text1 = textx;
    text1 = SDL_itoa(money, text1, 10);
    TTF_Font* font = TTF_OpenFont("resources/font1.ttf", 24);
    SDL_Color color1 = { 255, 255, 65, 255};
    SDL_Surface* surface1 = TTF_RenderText_Solid( font, text1, color1);
    SDL_Texture* text1_texture = SDL_CreateTextureFromSurface( renderer, surface1);

    SDL_Rect rec1 = { 125, 5, surface1->w, 25 };
    SDL_RenderCopy( renderer, text1_texture, NULL, &rec1);


    char textn[] = { ' ', ' ', ' ', ' ', ' '};
    char *text2 = textn;
    text2 = SDL_itoa(health, text2, 10);
    SDL_Color color2 = { 255, 65, 65, 255};
    SDL_Surface* surface2 = TTF_RenderText_Solid( font, text2, color2);
    SDL_Texture* text2_texture = SDL_CreateTextureFromSurface( renderer, surface2);

    SDL_Rect rec2 = { 275, 5, surface2->w, 25 };
    SDL_RenderCopy( renderer, text2_texture, NULL, &rec2);

    char textp[] = { ' ', ' ', ' ', ' ', ' '};
    char *text3 = textp;
    text3 = SDL_itoa(score, text3, 10);
    SDL_Color color3 = { 255, 120, 210, 255};
    SDL_Surface* surface3 = TTF_RenderText_Solid( font, text3, color3);
    SDL_Texture* text3_texture = SDL_CreateTextureFromSurface( renderer, surface3);
    
    SDL_Rect rec3 = { 425, 5, surface3->w, 25 };
    SDL_RenderCopy( renderer, text3_texture, NULL, &rec3);
    SDL_FreeSurface(surface3);
    SDL_DestroyTexture(text3_texture);

    SDL_FreeSurface(surface1);
    SDL_DestroyTexture(text1_texture);
    SDL_FreeSurface(surface2);
    SDL_DestroyTexture(text2_texture);
    TTF_CloseFont(font);

}

