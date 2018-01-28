#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <sstream>
#include <SDL/SDL_gfxPrimitives.h>
#include "global_variables.h"
#include "functions.h"
#include "functions_header.h"
using namespace std;
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415
class Tank
{
	private:
		int health;
		int Xposition;
		int Yposition;
		int speed;
		int Xspeed;
		int Yspeed;
		int angle;
		int omega;//change speed of angle
		int veapon_kind;//felan ye no tir

	public:
		void set_health(int i);
		void set_Xposition(int i);
		void set_Yposition(int i);
		void set_speed(int i);
		void set_Xspeed(int i);
		void set_Yspeed(int i);
		void set_angle(int i);//degree
		void set_omega(int i);
		void set_veapon_kind(int i);
		int get_health();
		int get_Xposition();
		int get_Yposition();
		int get_speed();
		int get_Xspeed();
		int get_Yspeed();
		int get_angle();
		int get_omega();
		int get_veapon_kind();
		/////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////
		void move();
		void turn_around();
};
void Tank::set_health(int i)
{
	health=i;
}
void Tank::set_Xposition(int i)
{
	Xposition=i;
}
void Tank::set_Yposition(int i)
{
	Yposition=i;
}
void Tank::set_speed(int i)
{
	speed=i;
}
void Tank::set_Xspeed(int i)
{
	if (i==1)
	{	
		Xspeed=(float)get_speed()*cos((float)get_angle()*PI/180.0);
	}
	else if (i==-1)
	{
		Xspeed=(-1)*((float)get_speed()*cos((float)get_angle()*PI/180.0));
	}
	else if (i==0)
	{
		Xspeed=0;

	}
}
void Tank::set_Yspeed(int i)
{
	if (i==1)
	{
		Yspeed=(float)get_speed()*sin((float)get_angle()*PI/180.0);
	}
	else if(i==-1)
	{
		Yspeed=(-1)*((float)get_speed()*sin((float)get_angle()*PI/180.0));
	}
	else if (i==0)
	{
		Yspeed=0;
	}
}
void Tank::set_angle(int i)
{
	angle=i;
}
void Tank::set_veapon_kind(int i)
{
	veapon_kind=i;
}
void Tank::set_omega(int i)
{
	if (i==1)
	{
		omega=10;
	}
	else if (i==-1)
	{
		omega=-10;
	}
	else if (i==0)
	{
		omega=0;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int Tank::get_health()
{
	return(health);
}
int Tank::get_Xposition()
{
	return(Xposition);
}
int Tank::get_Yposition()
{
	return(Yposition);
}
int Tank::get_speed()
{
	return(speed);
}
int Tank::get_Xspeed()
{
	return(Xspeed);
}
int Tank::get_Yspeed()
{
	return(Yspeed);
}
int Tank::get_angle()
{
	return(angle);
}
int Tank::get_omega()
{
	return(omega);
}
int Tank::get_veapon_kind()
{
	return(veapon_kind);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Tank::move()
{
	Xposition+=get_Xspeed();
	Yposition+=get_Yspeed();
}
void Tank::turn_around()
{
	angle+=get_omega();
}
/////////////////////////////////////////////////////////////////////////////
int main(){
	SDL_Init(SDL_INIT_EVERYTHING);
	int numbers_of_player_in_game=1;
	int map_number_in_game=1;
	srand((unsigned)time(NULL));
	// intital game screen
	SCREEN=SDL_SetVideoMode(frame_width,frame_height,32,SDL_SWSURFACE);
	//cin >> numberOFplayerINgame;
	const char* tankAddress[4]={"tank1.png","tank2.png","tank3.png","tank4.png"};
	const char* mapAddress[4]={"map1.png","map2.png","map3.png","map4.png"};

	//initial tank screen
	for (int i=0 ; i<max_numbers_of_player/*4*/; i++)
	{	
    	tankScreen[i]=IMG_Load(tankAddress[i]);
    	if (!(tankScreen[i]))
    			printf("%s\n",IMG_GetError());
	}

	//initial wall screen
	for (int i=0 ; i<max_numbers_of_map/*4*/; i++)
	{
	    mapScreen[i]=IMG_Load(mapAddress[i]); 
	    if (!(mapScreen[i]))
    			printf("%s\n",IMG_GetError());
	}
	//initial tanks //objact definition
	Tank *tank=new Tank[4];
	for (int i=0 ; i<numbers_of_player_in_game ; i++)
	{
		tank[i].set_health(5);
		tank[i].set_Xposition(1000);
		tank[i].set_Yposition(1000);
		tank[i].set_speed(20);
		tank[i].set_angle(90);
		tank[i].set_omega(0);
		tank[i].set_Xspeed(0);
		tank[i].set_Yspeed(0);
		tank[i].set_veapon_kind(1);// 1-> is normal veapon
	}
	/////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////
	map_number_in_game=randomMap(max_numbers_of_map,map_number_in_game);
	bool flag_SDLK_UP[4]={false,false,false,false};
	bool flag_SDLK_DOWN[4]={false,false,false,false};
	bool quit=false;
	SDL_Rect offset;
	while (quit==false)
	{
		if (SDL_PollEvent(&event))
		{
			
			if (event.type==SDL_QUIT)
			{
				quit=true;
			}
			else
			{
    //If a key was pressed
   			 	if( event.type == SDL_KEYDOWN )//in ha rokh dad hastand halat nistand
  				 {
        //Adjust the velocity
      				switch( event.key.keysym.sym )
     				{
            			case SDLK_UP:
            			{
            				flag_SDLK_UP[0]=true;break;
            			}
            			     					
      					case SDLK_DOWN:
       					{
      				    	flag_SDLK_DOWN[0]=true;break;
      					}

            //for determining angle
            			case SDLK_LEFT:
            			{
            				tank[0].set_omega(1);break;
            			}
            			case SDLK_RIGHT:
            			{
                			tank[0].set_omega(-1);break;
            			} 
      				}
    			}
    //If a key was released
    			else if( event.type == SDL_KEYUP )
    			{
        //Adjust the velocit
        			switch( event.key.keysym.sym )
     			   {
            			case SDLK_UP:
            			{
            				flag_SDLK_UP[0]=false;break;
            			}
            			
            			case SDLK_DOWN:
            			{	
            				flag_SDLK_DOWN[0]=false;break;
            			}
            //for determining angle
            			case SDLK_LEFT:
            			{
            				tank[0].set_omega(0);break;
            			}
            			case SDLK_RIGHT:
            			{
            				tank[0].set_omega(0);break;
            			}
       				}
    			}
			}
		}
		tank[0].turn_around();
		if(flag_SDLK_UP[0]==true)
		{
			tank[0].set_Yspeed(-1);
			tank[0].set_Xspeed(1);
		}
		if(flag_SDLK_DOWN[0]==true)
		{
			tank[0].set_Xspeed(-1);
			tank[0].set_Yspeed(1);
		}
		 if (flag_SDLK_UP[0]==false && flag_SDLK_DOWN[0]==false)
		{
			tank[0].set_Xspeed(0);
			tank[0].set_Yspeed(0);
		}
		tank[0].move();
		//SDL_FreeSurface(SCREEN);
		offset.x=tank[0].get_Xposition();
		offset.y=tank[0].get_Yposition();
		//update_monitor(tankScreen,SCREEN,numbersOFplayerINgame,tank);
		boxRGBA(SCREEN,0,0,3200,2000,0,0,0,255);
		/*SDL_BlitSurface(mapScreen[0],NULL,SCREEN,NULL);*/
		SDL_BlitSurface(mapScreen[map_number_in_game],NULL,SCREEN,NULL);
		SDL_BlitSurface(tankScreen[0],NULL,SCREEN,&offset);
		SDL_Flip(SCREEN);
		SDL_Delay(15);
	}
return 0;
}


///////////////////////////////////////////////////////////////////////////
