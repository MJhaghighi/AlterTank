#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <sstream>
#include <SDL/SDL_gfxPrimitives.h>
#include "global_variables.h"
#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415

/////////////////////////////////////////////////////////////////////////////



//                             classes                                    //




///////////////////////////////////////////////////////////////////////////
class Tank
{
	private:
		bool flag_UP;
		bool flag_DOWN;
		int health;
		int Xposition;
		int Yposition;
		int Xposition_center;
		int Yposition_center;
		int speed;
		int Xspeed;
		int Yspeed;
		int angle;
		int omega;//change speed of angle
		int veapon_kind;//felan ye no tir

	public:
		void set_flag_UP(bool i);
		void set_flag_DOWN(bool i);

		void set_Xposition_center(int i);
		void set_Yposition_center(int i);
		void set_health(int i);
		void set_Xposition(int i);
		void set_Yposition(int i);
		void set_speed(int i);
		void set_Xspeed(int i);
		void set_Yspeed(int i);
		void set_angle(int i);//degree
		void set_omega(int i);
		void set_veapon_kind(int i);
		
		bool get_flag_UP();
		bool get_flag_DOWN();
		int get_Xposition_center();
		int get_Yposition_center();
		int get_health();
		int get_Xposition();
		int get_Yposition();
		int get_speed();
		int get_Xspeed();
		int get_Yspeed();
		int get_angle();
		int get_omega();
		int get_veapon_kind();
		/////////////////////////////
		void move();
		void turn_around();
};
void Tank::set_flag_UP(bool i)
{
	flag_UP=i;
}
void Tank::set_flag_DOWN(bool i)
{
	flag_DOWN=i;
}
void Tank::set_Xposition_center(int i)
{
	Xposition_center=i;
}
void Tank::set_Yposition_center(int i)
{
	Yposition_center=i;
}
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
////////////////////////////////////////
bool Tank::get_flag_UP()
{
	return(flag_UP);
}
bool Tank::get_flag_DOWN()
{
	return(flag_DOWN);
}
int Tank::get_Xposition_center()
{
	return(Xposition_center);
}
int Tank::get_Yposition_center()
{
	return(Yposition_center);
}
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
//////////////////////////////////////
void Tank::move()
{
	Xposition+=get_Xspeed();
	Yposition+=get_Yspeed();
}
void Tank::turn_around()
{
	angle+=get_omega();
}




///////////////////////////////////////////////////////////////////////////

//                     function headers                                  //

//////////////////////////////////////////////////////////////////////////
int randomMap(int max_numbers_of_map,int mapNum);
void handle_event(Tank*tank,/*int &last_mouse_right_click_Xposition,int &last_mouse_right_click_Yposition,*/int i);


////////////////////////////////////////////////////////////////////////////

//                      global variables                                 //

///////////////////////////////////////////////////////////////////////////
int frame_width=1800;
int frame_height=900;
int max_numbers_of_player=4;
int max_numbers_of_map=4;
SDL_Event event;
SDL_Surface* SCREEN = NULL;
SDL_Surface** tankScreen = new SDL_Surface*[max_numbers_of_player];
SDL_Surface** mapScreen = new SDL_Surface*[max_numbers_of_map];
SDL_Surface** rotatedTank = new SDL_Surface*[max_numbers_of_player];
////////////////////////////////////////////////////////////////////////////////////////////



//                                       main                                            //

////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	int last_mouse_right_click_Xposition=0;
	int last_mouse_right_click_Yposition=0;
	int mouse_Xposition;
	int mouse_Yposition;
	SDL_Init(SDL_INIT_EVERYTHING);
	bool flag_UP[4]={false,false,false,false};
	bool flag_DOWN[4]={false,false,false,false};
	int numbers_of_player_in_game=4;
	int map_number_in_game=1;
	map_number_in_game=randomMap(max_numbers_of_map,map_number_in_game);
	//cin >> numberOFplayerINgame;
	srand((unsigned)time(NULL));
	// intital game screen
	SCREEN=SDL_SetVideoMode(frame_width,frame_height,32,SDL_SWSURFACE);
	const char* tankAddress[4]={"tank1.png","tank2.png","tank3.png","tank4.png"};
	const char* mapAddress[4]={"map1.png","map2.png","map3.png","map4.png"};
	//initial tank screen
	for (int i=0 ; i<max_numbers_of_player/*4*/; i++)
	{	
    	tankScreen[i]=IMG_Load(tankAddress[i]);
    	rotatedTank[i]=rotozoomSurface(tankScreen[i],/*angle*/0,/*zoom*/1.0,0);
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
		tank[i].set_flag_UP(false);
		tank[i].set_flag_DOWN(false);
		tank[i].set_Xposition(1000);
		tank[i].set_Yposition(400);				
		tank[i].set_Xposition_center(tankScreen[i]->w/2+tank[i].get_Xposition());
		tank[i].set_Yposition_center(tankScreen[i]->h/2+tank[i].get_Yposition());
		tank[i].set_health(5);
		tank[i].set_speed(9);
		tank[i].set_angle(90);
		tank[i].set_omega(0);
		tank[i].set_Xspeed(0);
		tank[i].set_Yspeed(0);
		tank[i].set_veapon_kind(1);// 1-> is normal veapon
	}
	/////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////

	bool Continue=true;
	SDL_Rect offset;

	while (Continue)
	{	
////////////////////////////////menu/////////////////////////////////////





////////////////////////////////handle event//////////////////////////////
		if (SDL_PollEvent(&event))
		{
			
			if (event.type==SDL_QUIT)
			{
				Continue=false;
			}
			else
			{
				for (int i=0 ; i<numbers_of_player_in_game ; i++)
				{
					handle_event(tank,/*last_mouse_right_click_Xposition,last_mouse_right_click_Yposition,*/i);
				}
			}
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////make move and rotation/////////////////////////////////////////////////////////
		for (int i=0 ; i<numbers_of_player_in_game ; i++)
		{
			SDL_FreeSurface(rotatedTank[i]);
			tank[i].turn_around();
			rotatedTank[i]=rotozoomSurface(tankScreen[i],tank[i].get_angle()-90,1.0,0);
			if(tank[i].get_flag_UP()==true)
			{
				tank[i].set_Yspeed(-1);
				tank[i].set_Xspeed(1);
			}
			if(tank[i].get_flag_DOWN()==true)
			{
				tank[i].set_Xspeed(-1);
				tank[i].set_Yspeed(1);
			}
			if (tank[i].get_flag_UP()==false  &&  tank[i].get_flag_DOWN()==false)
			{
				tank[i].set_Xspeed(0);
				tank[i].set_Yspeed(0);
			}
			tank[i].move();
		}

			
		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Blitting Surface //////////////////////////////////////////////////////////////////
		boxRGBA(SCREEN,0,0,frame_width,frame_height,0,0,0,255);
		SDL_BlitSurface(mapScreen[map_number_in_game],NULL,SCREEN,NULL);
		for (int i=0;i<numbers_of_player_in_game;i++)
		{
			tank[i].set_Xposition_center(tankScreen[i]->w/2+tank[i].get_Xposition());
			tank[i].set_Yposition_center(tankScreen[i]->h/2+tank[i].get_Yposition());
			offset.x=tank[i].get_Xposition();
			offset.y=tank[i].get_Yposition();
			offset.x-=rotatedTank[i]->w/2-tankScreen[i]->w/2;
			offset.y-=rotatedTank[i]->h/2-tankScreen[i]->h/2;
			SDL_BlitSurface(rotatedTank[i],NULL,SCREEN,&offset);
			filledCircleRGBA(SCREEN,tank[i].get_Xposition_center(),tank[i].get_Yposition_center(),20,100,50,200,255);
		}
		//cout << last_mouse_right_click_Xposition<<" "<<last_mouse_right_click_Yposition<<"\n";
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// go to next frame //////////////////////////////////////////////////////////////////////
		SDL_Flip(SCREEN);
		SDL_Delay(20);
		SDL_FreeSurface(SCREEN);


		
	
	}
return 0;
}
//////////////////////////////////////////////////////////////////////////


//                             functions                                //


//////////////////////////////////////////////////////////////////////////
int randomMap(int max_numbers_of_map,int mapNum)
{
    int p=rand()%max_numbers_of_map;
    if(p==mapNum) randomMap(max_numbers_of_map,mapNum);
    else return p;
}

void handle_event(Tank *tank,/*int &last_mouse_right_click_Xposition,int &last_mouse_right_click_Yposition,*/int i)
{			
	if (i==0)
	    //If a key was pressed
   			 	if( event.type == SDL_KEYDOWN )//in ha rokh dad hastand halat nistand
  				 {
        //Adjust the velocity
      				switch( event.key.keysym.sym )
     				{
            			case SDLK_UP:
            			{
            				tank[i].set_flag_UP(true);break;
            			}
            			     					
      					case SDLK_DOWN:
       					{
      				    	tank[i].set_flag_DOWN(true);break;
      					}

            //for determining angle
            			case SDLK_LEFT:
            			{
            				tank[i].set_omega(1);break;

            			}
            			case SDLK_RIGHT:
            			{
                			tank[i].set_omega(-1);break;
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
            				tank[i].set_flag_UP(false);break;
            			}
            			
            			case SDLK_DOWN:
            			{	
            				tank[i].set_flag_DOWN(false);break;
            			}
            //for determining angle
            			case SDLK_LEFT:
            			{
            				tank[i].set_omega(0);break;
            			}
            			case SDLK_RIGHT:
            			{
            				tank[i].set_omega(0);break;
            			}
       				}
    			}
    if (i==1)
    	if( event.type == SDL_KEYDOWN )//in ha rokh dad hastand halat nistand
  				 {
        //Adjust the velocity
      				switch( event.key.keysym.sym )
     				{
            			case SDLK_w:
            			{
            				tank[i].set_flag_UP(true);break;
            			}
            			     					
      					case SDLK_s:
       					{
      				    	tank[i].set_flag_DOWN(true);break;
      					}

            //for determining angle
            			case SDLK_a:
            			{
            				tank[i].set_omega(1);break;
            			}
            			case SDLK_d:
            			{
                			tank[i].set_omega(-1);break;
            			} 
      				}
    			}
    //If a key was released
    			else if( event.type == SDL_KEYUP )
    			{
        //Adjust the velocit
        			switch( event.key.keysym.sym )
     			   {
            			case SDLK_w:
            			{
            				tank[i].set_flag_UP(false);break;
            			}
            			
            			case SDLK_s:
            			{	
            				tank[i].set_flag_DOWN(false);break;
            			}
            //for determining angle
            			case SDLK_a:
            			{
            				tank[i].set_omega(0);break;
            			}
            			case SDLK_d:
            			{
            				tank[i].set_omega(0);break;
            			}
       				}
    			}
/*
	if (i==3)
    	if (event.type == SDL_MOUSEBUTTONDOWN)//joy stick
    	{	//cout << "OK1";

    		switch(event.button.button)
    		{
    		case SDL_BUTTON_LEFT:
    		{
    			last_mouse_right_click_Yposition=event.button.y;
    			last_mouse_right_click_Xposition=event.button.x;
    			//cout<< "OK2";
    			tank[i].set_angle(180*atan2( tank[i].get_Yposition_center() - last_mouse_right_click_Yposition  ,  last_mouse_right_click_Xposition - tank[i].get_Xposition_center() )/PI);
    			tank[i].set_flag_UP(true);

    		}break;
    		

    		/*case SDL_BUTTON_LEFT:
    		{
				shelik
    		}*/
			//}    
    	//}	
}





void menu(SDL_Surface* SCREEN,int &numbers_of_player_in_game)
{
	SDL_Surface* setting=IMG_Load("setting.png");
	SDL_Surface* play_game=IMG_Load("playgame.png");
	SDL_Surface* single_player=IMG_Load("singleplayer.png");
	SDL_Surface* two_player=IMG_Load("twoplayer.png");
	SDL_Surface* three_player=IMG_Load("threeplayer.png");
	SDL_Surface* four_player=IMG_Load("fourplayer.png");
	bool quit=true;
	while(quit)
	{
		
	}
	return;
}