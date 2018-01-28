// this is file of global variables

int mapNum=0;

int getFrameWidth()
{
    return (3700);
}

int getFrameHeight()
{
    return (2000);
}

int getMaxNumOFplayer()
{
	return(4);
}

int getMaxNumOFmap()
{
	return(4);
}
int numbersOFplayerINgame=1;
SDL_Event event;
SDL_Surface* SCREEN = NULL;
SDL_Surface** tankScreen = new SDL_Surface*[getMaxNumOFplayer()];
SDL_Surface** mapScreen = new SDL_Surface*[getMaxNumOFmap()];
