#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <sstream>
#include "global_variables.h"
#include "functions.h"
#include "functions_header.h"
using namespace std;




int main(){
	SDL_Init(SDL_INIT_EVERYTHING);
	// game screen
	SDL_Surface* SCREEN = NULL;
	SCREEN=SDL_SetVideoMode(getFrameWidth(),getFrameHeight(),32,SDL_SWSURFACE);
	//cin >> numberOFplayer;
	const char* tankAdress[4]={"tank1.png","tank2.png","tank3.png","tank4.png"};
	const char* mapAdress[4]={"map1.png","map2.png","map3.png","map4.png"};

	//initial tank screen
	SDL_Surface** tankScreen = new SDL_Surface*[getMaxNumOFplayer()];
	for (int i=0 ; i<getMaxNumOFplayer() ; i++)
	{	
    	tankScreen[i]=IMG_Load(tankAdress[i]);
    	if (!(tankScreen[i]))
    			printf("%s\n",IMG_GetError());
	}

	//initial wall screen
	SDL_Surface** mapScreen = new SDL_Surface*[getMaxNumOFmap()];
	for (int i=0 ; i<getMaxNumOFmap() ; i++)
	{
	    mapScreen[i]=IMG_Load(mapAdress[i]); 
	    if (!(mapScreen[i]))
    			printf("%s\n",IMG_GetError());
	}

	SDL_BlitSurface(mapScreen[0],NULL,SCREEN,NULL);
	SDL_BlitSurface(tankScreen[2],NULL,SCREEN,NULL);	
	SDL_Flip(SCREEN);
	SDL_Delay( 5000 );



	/////////////////////////////////////////////////////////////////////////////////////////////
/*

	while (true)
	{
		//randomlyPicMap
		//move tank














	SDL_Flip( screen );
	for (int i=0 ; i<numberOFplayer ; i++)
	{
		SDL_Flip(tankScreen[i]);
	}



	SDL_Delay( 8000 );
	}
*/
return 0;
}
