// this is file of global variables
int frame_width=3700;
int frame_height=2000;
int max_numbers_of_player=4;
int max_numbers_of_map=4;
int numbersOFplayerINgame=1;
SDL_Event event;
SDL_Surface* SCREEN = NULL;
SDL_Surface** tankScreen = new SDL_Surface*[max_numbers_of_player];
SDL_Surface** mapScreen = new SDL_Surface*[max_numbers_of_map];
