#include "../inc/game.h"

void mx_menu(SDL_Window *window, SDL_Renderer *renderer) {
    
    bool is_menu = true;
    
    SDL_Surface *menu = IMG_Load("resources/background.jpg");
    
    SDL_Texture *start = IMG_LoadTexture(renderer, "resources/start.jpg");
    SDL_Texture *exit = IMG_LoadTexture(renderer, "resources/exit.jpg");
    SDL_Rect start_rect = {230, 200, 314, 94};
    SDL_Rect exit_rect = {230, 320, 314, 94};


    SDL_Texture *menu_txtr = SDL_CreateTextureFromSurface(renderer, menu);
    SDL_FreeSurface(menu);
    SDL_RenderPresent(renderer);
    
    while (is_menu == true) {
        SDL_Event event;
 
        // Events management
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
 
            case SDL_QUIT:                 
               is_menu = false;
                break;
                
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT && event.button.x >= 230 && event.button.y >= 200 && event.button.y < 296 && event.button.x < 514 ) {
                		if ( mx_game(window, renderer)) {
                   		
                   	}
                   	else {
                   		is_menu = false;
                   	}
                    
                }
                if(event.button.button == SDL_BUTTON_LEFT && event.button.x >= 230 && event.button.y >= 320 && event.button.y < 414 && event.button.x < 514 ) {
                    is_menu = false;
                }
                
                
 
            
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, menu_txtr, NULL, NULL);
        SDL_RenderCopy(renderer, start, NULL, &start_rect);
        SDL_RenderCopy(renderer, exit, NULL, &exit_rect);
        SDL_RenderPresent(renderer);
     }
     }
     
    SDL_DestroyTexture(menu_txtr);
    SDL_DestroyTexture(start);
    SDL_DestroyTexture(exit);
}

