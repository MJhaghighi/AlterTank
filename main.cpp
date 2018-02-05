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
		int tankScreen_width;
		int tankScreen_height;
		int critical_dot[12][2]; // 0 is x  and  1 is y
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
		int variable_for_shoot2;
	public:
		void ser_variable_for_shoot2(int i);
		void set_tankScreen_width(int i);
		void set_tankScreen_height(int i);
		void set_flag_UP(bool i);
		void set_flag_DOWN(bool i);
		void check_collision(SDL_Surface *SCREEN);
		void set_critical_dots(SDL_Surface *SCREEN);
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
		void set_variable_for_shoot2(int i);

        void get_tankScreen_width(int i);
		void get_tankScreen_height(int i);
		bool get_flag_UP();
		bool get_flag_DOWN();
		int get_variable_for_shoot2();
		int get_Xposition_center();
		int get_Yposition_center();
		int get_tankScreen_width();
        int get_tankScreen_height();
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
		void move(int i);
		void turn_around();
};

void Tank::set_variable_for_shoot2(int i)
{
	variable_for_shoot2=i;
}

void Tank::check_collision(SDL_Surface *SCREEN)
{
	bool flag=false;
	Uint32 *pixels = (Uint32 *) SCREEN->pixels;
	for(int j=0 ; j<=4 ; j++)
	{
        for(int k=-2 ; k<=2 ; k++)
        {
		Uint8 *color = (Uint8 *) & ( pixels[(critical_dot[j][1]+k) *SCREEN->w+(critical_dot[j][0]+k)] );
		if(color[2]>240 && color[1]>240 && color[0]>240) flag=true; //move(-1);//flag_UP=0;//
		}
	}

	for(int j=5 ; j<=9 ; j++)
	{
        for(int k=-2 ; k<=2 ; k++)
        {
		Uint8 *color = (Uint8 *) & ( pixels[(critical_dot[j][1]+k) *SCREEN->w+(critical_dot[j][0]+k)] );
		if(color[2]>240 && color[1]>240 && color[0]>240)flag_DOWN=0; //flag=true; //move(-1);
        }
	}
	if (flag==true)
	{
		move(-1);
	}
}
void Tank::set_critical_dots(SDL_Surface *SCREEN)
{
		critical_dot[0][0]=get_Xposition_center()+sqrt(pow((tankScreen_width/2),2)+pow((tankScreen_height/2),2))*cos(get_angle()/180.0*3.1415+atan2((tankScreen_width),(tankScreen_height)));//x   1
		critical_dot[0][1]=get_Yposition_center()-sqrt(pow((tankScreen_width/2),2)+pow((tankScreen_height/2),2))*sin(get_angle()/180.0*3.1415+atan2((tankScreen_width),(tankScreen_height)));//y

		critical_dot[2][0]=get_Xposition_center()+ (tankScreen_height/2)*cos(get_angle()/180.0*3.1415);//x   3
		critical_dot[2][1]=get_Yposition_center()-(tankScreen_height/2)*sin(get_angle()/180.0*3.1415);//y

		critical_dot[4][0]=get_Xposition_center()+sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/2),2))*cos(get_angle()/180.0*3.1415-atan2((tankScreen_width),(tankScreen_height)));//x   5
		critical_dot[4][1]=get_Yposition_center()-sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/2),2))*sin(get_angle()/180.0*3.1415-atan2((tankScreen_width),(tankScreen_height)));//y

		critical_dot[5][0]=get_Xposition_center()+sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/2),2))*cos(PI+get_angle()/180.0*3.1415-atan2((tankScreen_width),(tankScreen_height)));//x   6
		critical_dot[5][1]=get_Yposition_center()-sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/2),2))*sin(PI+get_angle()/180.0*3.1415-atan2((tankScreen_width),(tankScreen_height)));//y

		critical_dot[7][0]=get_Xposition_center()-(tankScreen_height/2)*cos(get_angle()/180.0*3.1415);//x   8
		critical_dot[7][1]=get_Yposition_center()+(tankScreen_height/2)*sin(get_angle()/180.0*3.1415);//y

		critical_dot[9][0]=get_Xposition_center()+sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/2),2))*cos(PI+get_angle()/180.0*3.1415+atan2((tankScreen_width),(tankScreen_height)));//x   10
		critical_dot[9][1]=get_Yposition_center()-sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/2),2))*sin(PI+get_angle()/180.0*3.1415+atan2((tankScreen_width),(tankScreen_height)));//y

		critical_dot[10][0]=get_Xposition_center()+(tankScreen_width/2)*cos(PI/2+get_angle()/180.0*3.1415);//x   11
		critical_dot[10][1]=get_Yposition_center()-(tankScreen_width/2)*sin(PI/2+get_angle()/180.0*3.1415);//y

		critical_dot[11][0]=get_Xposition_center()+(tankScreen_width/2)*cos(get_angle()/180.0*3.1415-PI/2);//x   12
		critical_dot[11][1]=get_Yposition_center()-(tankScreen_width/2)*sin(get_angle()/180.0*3.1415-PI/2);//y

		critical_dot[1][0]=get_Xposition_center()+sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/4),2))*cos(get_angle()/180.0*3.1415+atan2((tankScreen_width),(tankScreen_height*2)));//x   2
		critical_dot[1][1]=get_Yposition_center()-sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/4),2))*sin(get_angle()/180.0*3.1415+atan2((tankScreen_width),(tankScreen_height*2)));//y

		critical_dot[3][0]=get_Xposition_center()+sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/4),2))*cos(get_angle()/180.0*3.1415-atan2((tankScreen_width),(tankScreen_height*2)));//x   4
		critical_dot[3][1]=get_Yposition_center()-sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/4),2))*sin(get_angle()/180.0*3.1415-atan2((tankScreen_width),(tankScreen_height*2)));//y

		critical_dot[6][0]=get_Xposition_center()+sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/4),2))*cos(PI+get_angle()/180.0*3.1415-atan2((tankScreen_width),(tankScreen_height*2)));//x   7
		critical_dot[6][1]=get_Yposition_center()-sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/4),2))*sin(PI+get_angle()/180.0*3.1415-atan2((tankScreen_width),(tankScreen_height*2)));//y

		critical_dot[8][0]=get_Xposition_center()+sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/4),2))*cos(PI+get_angle()/180.0*3.1415+atan2((tankScreen_width),(tankScreen_height*2)));//x   9
        critical_dot[8][1]=get_Yposition_center()-sqrt(pow((tankScreen_height/2),2)+pow((tankScreen_width/4),2))*sin(PI+get_angle()/180.0*3.1415+atan2((tankScreen_width),(tankScreen_height*2)));//y

}
void Tank::set_tankScreen_width(int i)
{
	tankScreen_width=i;
}
void Tank::set_tankScreen_height(int i)
{
	tankScreen_height=i;
}

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
int Tank::get_variable_for_shoot2()
{
	return(variable_for_shoot2);
}
bool Tank::get_flag_UP()
{
	return(flag_UP);
}
bool Tank::get_flag_DOWN()
{
	return(flag_DOWN);
}
int Tank::get_tankScreen_width()
{
    return tankScreen_width;
}
int Tank::get_tankScreen_height()
{
    return tankScreen_height;
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
void Tank::move(int i)
{
	if (i==1)
	{
		Xposition+=get_Xspeed();
		Yposition+=get_Yspeed();
	}
	else if(i==-1)
	{
		Xposition-=get_Xspeed();
		Yposition-=get_Yspeed();
	}

}
void Tank::turn_around()
{
	angle+=get_omega();
}
class Bullet
{
    private:
        int Xposition;
        int Yposition;
        int speed;
        int Xspeed;
        int Yspeed;
        int angle;
        int radius;
        bool flag_exist;
    public:
    	void set_Xposition(int i);
    	void set_Yposition(int i);
    	void set_speed(int i);
    	void set_Xspeed(int i);
    	void set_Yspeed(int i);
       	void set_flag_exist(bool i);
       	void set_angle(int i);
       	void move();
       	void check_collision(SDL_Surface *SCREEN);
       	void set_radius(int i);
       	int get_Xposition();
       	int get_Yposition();
       	int get_speed();
       	int get_Xspeed();
       	int get_Yspeed();
       	int get_angle();
       	int get_radius();
       	bool get_flag_exist();
};


		void Bullet::check_collision(SDL_Surface *SCREEN)
        {
            int x=Xposition;
            int y=Yposition;
            int Vx=Xspeed;
            int Vy=Yspeed;

            Uint32 *pixels = (Uint32 *) SCREEN->pixels;
            Uint8 *color;
            Uint8 *color2;

            if(Vx>=0 && Vy<=0)
            {
                color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x+radius+7)] );
                color2 = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x+radius+1)] );
                if(color[2]>240 && color[1]>240 && color[0]>240) Xspeed*=(-1);
                else if(color2[2]>240 && color2[1]>240 && color2[0]>240) Xspeed*=(-1);


                color = (Uint8 *) & ( pixels[(y-radius-7) *SCREEN->w+(x)] );
                color2 = (Uint8 *) & ( pixels[(y-radius-1) *SCREEN->w+(x)] );
                if(color[2]>240 && color[1]>240 && color[0]>240) Yspeed*=(-1);
                else if(color2[2]>240 && color2[1]>240 && color2[0]>240) Yspeed*=(-1);
            }

            else if(Vx>=0 && Vy>=0)
            {
                color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x+radius+7)] );
                color2 = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x+radius+1)] );
                if(color[2]>240 && color[1]>240 && color[0]>240) Xspeed*=(-1);
                else if(color2[2]>240 && color2[1]>240 && color2[0]>240) Xspeed*=(-1);

                color = (Uint8 *) & ( pixels[(y+radius+7) *SCREEN->w+(x)] );
                color2 = (Uint8 *) & ( pixels[(y+radius+1) *SCREEN->w+(x)] );
                if(color[2]>240 && color[1]>240 && color[0]>240) Yspeed*=(-1);
                else if(color2[2]>240 && color2[1]>240 && color2[0]>240) Yspeed*=(-1);
            }

            else if(Vx<=0 && Vy<=0)
            {
                color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x-radius-7)] );
                color2 = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x-radius-1)] );
                if(color[2]>240 && color[1]>240 && color[0]>240) Xspeed*=(-1);
                else if(color2[2]>240 && color2[1]>240 && color2[0]>240) Xspeed*=(-1);

                color = (Uint8 *) & ( pixels[(y-radius-7) *SCREEN->w+(x)] );
                color2 = (Uint8 *) & ( pixels[(y-radius-1) *SCREEN->w+(x)] );
                if(color[2]>240 && color[1]>240 && color[0]>240) Yspeed*=(-1);
                else if(color2[2]>240 && color2[1]>240 && color2[0]>240) Yspeed*=(-1);
            }

            else if(Vx<=0 && Vy>=0)
            {
                color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x-radius-7)] );
                color2 = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x-radius-1)] );
                if(color[2]>240 && color[1]>240 && color[0]>240) Xspeed*=(-1);
                else if(color2[2]>240 && color2[1]>240 && color2[0]>240) Xspeed*=(-1);

                color = (Uint8 *) & ( pixels[(y+radius+7) *SCREEN->w+(x)] );
                color2 = (Uint8 *) & ( pixels[(y+radius+1) *SCREEN->w+(x)] );
                if(color[2]>240 && color[1]>240 && color[0]>240) Yspeed*=(-1);
                else if(color2[2]>240 && color2[1]>240 && color2[0]>240) Yspeed*=(-1);
            }
        }

        void Bullet::move()
        {
            Xposition+=Xspeed;
            Yposition+=Yspeed;
        }

		void Bullet::set_Xposition(int i)
		{
			Xposition=i;
		}
		void Bullet::set_Yposition(int i)
		{
			Yposition=i;
		}
		void Bullet::set_angle(int i)
		{
			angle=i;
		}
		void Bullet::set_speed(int i)
		{
			speed=i;
		}
		void Bullet::set_Xspeed(int i)
		{
			if (i==1)
			{
				Xspeed=(float)get_speed()*cos((float)get_angle()*PI/180.0);
			}
			else if (i==0)
			{
				Xspeed=0;

			}
		}
		void Bullet::set_Yspeed(int i)
		{
			if (i==1)
			{
				Yspeed=(float)(-1)*get_speed()*sin((float)get_angle()*PI/180.0);
			}
			else if (i==0)
			{
				Yspeed=0;
			}
		}
		void Bullet::set_flag_exist(bool i)
		{
			flag_exist=i;
		}

		void Bullet::set_radius(int i)
        {
            radius=i;
        }

       	int Bullet::get_Xposition()
       	{
       		return(Xposition);
       	}
       	int Bullet::get_Yposition()
       	{
       		return(Yposition);
       	}
       	int Bullet::get_speed()
       	{
       		return (speed);
       	}
       	int Bullet::get_Xspeed()
       	{
       		return(Xspeed);
       	}
       	int Bullet::get_Yspeed()
       	{
       		return(Yspeed);
       	}
       	bool Bullet::get_flag_exist()
       	{
       		return(flag_exist);
       	}
       	int Bullet::get_angle()
       	{
       		return(angle);
       	}
       	int Bullet::get_radius()
       	{
       		return radius;
       	}
///////////////////////////////////////////////////////////////////////////
//                     function headers                                  //
//////////////////////////////////////////////////////////////////////////
int Distance(int x1 ,int y1 ,int x2,int y2);
int randomMap(int max_numbers_of_map,int mapNum);
//void handle_move_event(Tank*tank,int i);
void handle_move_event(Tank *tank,int numbers_of_player_in_game);
void handle_fire_event(Tank *tank,Bullet *bullet ,int numbers_of_player_in_game );

void menu(SDL_Surface* SCREEN,int &numbers_of_player_in_game,SDL_Event &event);
void shift_bullets(Bullet *bullet);
void shoot(Tank *tank,Bullet *bullet , int i);
void shoot2(Tank *tank,int n,int numbers_of_player_in_game);

////////////////////////////////////////////////////////////////////////////
//                      global variables                                 //
///////////////////////////////////////////////////////////////////////////
int frame_width=1900;
int frame_height=900;
int max_numbers_of_player=4;
int max_numbers_of_map=4;
SDL_Event event;
SDL_Surface* SCREEN = NULL;
SDL_Surface** sparkScreen = new SDL_Surface*[max_numbers_of_player];
SDL_Surface** rotatedSpark = new SDL_Surface*[max_numbers_of_player];
SDL_Surface** tankScreen = new SDL_Surface*[max_numbers_of_player];
SDL_Surface** mapScreen = new SDL_Surface*[max_numbers_of_map];
SDL_Surface** rotatedTank = new SDL_Surface*[max_numbers_of_player];
////////////////////////////////////////////////////////////////////////////////////////////
//                                       main                                            //
////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	srand((unsigned)time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);
	int last_mouse_right_click_Xposition=0;
	int last_mouse_right_click_Yposition=0;
	int mouse_Xposition;
	int mouse_Yposition;
	int numbers_of_player_in_game=2;
	int map_number_in_game;
	map_number_in_game=randomMap(max_numbers_of_map,map_number_in_game);

	SCREEN=SDL_SetVideoMode(frame_width,frame_height,32,SDL_SWSURFACE);
	const char* tankAddress[4]={"tank1.png","tank2.png","tank3.png","tank4.png"};
	const char* mapAddress[4]={"map1.png","map2.png","map3.png","map4.png"};
	const char* sparkAddress[4]={"spark1.png","spark2.png","spark3.png","spark4.png"};

	for (int i=0 ; i<max_numbers_of_player; i++)
	{
		tankScreen[i]=NULL;
    	tankScreen[i]=IMG_Load(tankAddress[i]);
    	rotatedTank[i]=rotozoomSurface(tankScreen[i],/*angle*/0,/*zoom*/1.0,0);
    	if (!(tankScreen[i]))
    			printf("%s\n",IMG_GetError());
	}
	for (int i=0 ; i<max_numbers_of_map/*4*/; i++)
	{
	    mapScreen[i]=IMG_Load(mapAddress[i]);
	    if (!(mapScreen[i]))
    			printf("%s\n",IMG_GetError());
	}

	for (int i = 0; i < max_numbers_of_player; ++i)
	{
		sparkScreen[i]=IMG_Load(sparkAddress[i]);
		if (!(sparkScreen[i]))
    			printf("%s\n",IMG_GetError());
	}


	menu(SCREEN,numbers_of_player_in_game,event);

	int spark_number=0;
	Tank *tank=new Tank[4];
	for (int i=0 ; i<numbers_of_player_in_game ; i++)
	{
		tank[i].set_flag_UP(false);
		tank[i].set_flag_DOWN(false);
		tank[i].set_Xposition(990);
		tank[i].set_Yposition(380);
		tank[i].set_Xposition_center(tankScreen[i]->w/2+tank[i].get_Xposition());
		tank[i].set_Yposition_center(tankScreen[i]->h/2+tank[i].get_Yposition());
		tank[i].set_health(10);
		tank[i].set_speed(8);
		tank[i].set_angle(90);
		tank[i].set_omega(0);
		tank[i].set_Xspeed(0);
		tank[i].set_Yspeed(0);
		tank[i].set_veapon_kind(1);// 1-> is normal veapon
		tank[i].set_tankScreen_width(tankScreen[i]->w);
		tank[i].set_tankScreen_height(tankScreen[i]->h);
		tank[i].set_variable_for_shoot2(20);
	}


	
	Bullet *bullet=new Bullet[41];
	for(int i=0 ; i<=40 ; i++)
	{
        bullet[i].set_Xposition(0);
        bullet[i].set_Yposition(0);
        bullet[i].set_flag_exist(false);
        bullet[i].set_angle(0);
        bullet[i].set_speed(6);
        bullet[i].set_Xspeed(0);
        bullet[i].set_Yspeed(0);
        bullet[i].set_radius(5);
    }



	SDL_Rect offset;
	SDL_Rect spark_offset;
	bool Continue=true;
	while (Continue)
	{

			if (SDL_PollEvent(&event))
			{

/*W*/				if(event.type==SDL_QUIT)
				{
					Continue=false;
				}
				else
				{
					for(int i=0 ; i<numbers_of_player_in_game ; i++)
					{
						handle_move_event(tank,numbers_of_player_in_game);
						handle_fire_event(tank,bullet,numbers_of_player_in_game);
					}
				}
			}


			boxRGBA(SCREEN,0,0,frame_width,frame_height,0,0,0,255);



/*H*/

			//set tank speed
        	for (int i=0 ; i<numbers_of_player_in_game ; i++)
			{
				SDL_FreeSurface(rotatedTank[i]);
				tank[i].turn_around();
/*I*/			rotatedTank[i]=rotozoomSurface(tankScreen[i],tank[i].get_angle()-90,1.0,0);
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
/*L*/				{
					tank[i].set_Xspeed(0);
					tank[i].set_Yspeed(0);
				}
			}


			// tanks move
/*E*/     	for(int i=0;i<numbers_of_player_in_game;i++)
        	{
				tank[i].move(1);
        	}

			// bullets move
       		for(int i=39 ; i>=0 ; i--)
        	{
/*T*/           if(bullet[i].get_flag_exist()==true)
            	{
               		filledCircleRGBA(SCREEN,bullet[i].get_Xposition(),bullet[i].get_Yposition(),5,204,102,0,255);
               		bullet[i].move();
            	}
        	}	
        	
//      	ziri


//          colision bullet tank


        

        	//blit all surface and set center of each tank
			for(int i=0;i<numbers_of_player_in_game;i++)
			{
/*R*/			tank[i].set_Xposition_center(tankScreen[i]->w/2+tank[i].get_Xposition());
				tank[i].set_Yposition_center(tankScreen[i]->h/2+tank[i].get_Yposition());
				offset.x=tank[i].get_Xposition();
				offset.y=tank[i].get_Yposition();
				offset.x-=rotatedTank[i]->w/2-tankScreen[i]->w/2;
				offset.y-=rotatedTank[i]->h/2-tankScreen[i]->h/2;
				SDL_BlitSurface(rotatedTank[i],NULL,SCREEN,&offset);
				tank[i].set_critical_dots(SCREEN);
			}
			
			for (int i=0 ; i<numbers_of_player_in_game ; i++)
			{
				if (tank[i].get_variable_for_shoot2() < 20 )
				{
					if (spark_number>13)
					{
						spark_number=0;
					}
					spark_number++;
					spark_offset.x=tank[i].get_Xposition();
					spark_offset.y=tank[i].get_Yposition();
					spark_offset.x-=rotatedTank[i]->w/2-tankScreen[i]->w/2;
					spark_offset.y-=rotatedTank[i]->h/2-tankScreen[i]->h/2;
					rotatedSpark[spark_number%4]=rotozoomSurface(sparkScreen[spark_number%4],tank[i].get_angle()-90,1.0,0);
					SDL_BlitSurface(rotatedSpark[spark_number%4],NULL,SCREEN,&spark_offset);
					tank[i].set_variable_for_shoot2(tank[i].get_variable_for_shoot2()+1);
				}
			}

			SDL_BlitSurface(mapScreen[map_number_in_game],NULL,SCREEN,NULL);


			// check colision for tanks with walls
        	for(int i=0;i<numbers_of_player_in_game;i++)
				tank[i].check_collision(SCREEN);



        	// check colision of bullets with walls
        	for(int i=39 ; i>=0 ; i--)
       		{
            	if(bullet[i].get_flag_exist()==true)
          	    {
					bullet[i].check_collision(SCREEN);
           		}
       		}

       	cout << tank[1].get_health();
		SDL_Flip(SCREEN);
		SDL_Delay(10);
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

void shift_bullets(Bullet *bullet)
{
    bullet[40]=bullet[0];
    for(int i=1 ; i<=40 ; i++)
        bullet[i-1]=bullet[i];
}

void shoot(Tank *tank,Bullet *bullet , int k)
{
    bullet[0].set_Xposition(tank[k].get_Xposition_center() + (tank[k].get_tankScreen_height()/2)*cos(tank[k].get_angle()/180.0*3.1415));
    bullet[0].set_Yposition(tank[k].get_Yposition_center() - (tank[k].get_tankScreen_height()/2)*sin(tank[k].get_angle()/180.0*3.1415));
    bullet[0].set_angle(tank[k].get_angle());
    bullet[0].set_Xspeed(1);
    bullet[0].set_Yspeed(1);
    bullet[0].set_flag_exist(true);
    shift_bullets(bullet);
    return;
}

void shoot2(Tank *tank,int numbers_of_player_in_game,int k)
{
	for (int i ; i<numbers_of_player_in_game ; i++)
	{
		if (i!=k)
			if (Distance(tank[i].get_Xposition_center(),tank[i].get_Yposition_center(),tank[k].get_Xposition_center(),tank[k].get_Yposition_center())  <  500)
			{
				tank[i].set_variable_for_shoot2(0);
				tank[i].set_health(tank[i].get_health()-2);
			}
	}
}
void handle_fire_event(Tank *tank,Bullet *bullet ,int numbers_of_player_in_game )
{
	if (event.type==SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_m:
			{
				if (numbers_of_player_in_game>=1)
				{
					switch(tank[0].get_veapon_kind())
					{
						case 1:
						{
							shoot(tank,bullet,0);
						}break;
						case 2:
						{
							shoot2(tank,numbers_of_player_in_game,0);
						}break;
						case 3:
						{
							//shoot3
						}break;
					}
				}
			} break;

			
			case SDLK_q:
			{
				if (numbers_of_player_in_game>=2)
				{
					switch(tank[1].get_veapon_kind())
					{
						case 1:
						{
							shoot(tank,bullet,1);
						}break;
						case 2:
						{
							shoot2(tank,numbers_of_player_in_game,1);
						}break;
						case 3:
						{
							//shoot3
						}break;
					}
				}
			} break;
		

		}
	}
}


int Distance(int x1 ,int y1 ,int x2,int y2)
{
	return(sqrt(pow(x1-x2,2)+pow(y1-y2,2)));
}


void handle_move_event(Tank *tank,int numbers_of_player_in_game)
{
	
	if (numbers_of_player_in_game>=1)
	{
		if (event.type==SDL_KEYDOWN)
		{ 
		       //Adjust the velocit
			switch(event.key.keysym.sym)
			{
				case SDLK_UP:
            	{
           			tank[0].set_flag_UP(true);break;
       			}
      			case SDLK_DOWN:
   				{
      				tank[0].set_flag_DOWN(true);break;
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
		if (event.type==SDL_KEYUP)
		{
        //Adjust the velocit
        	switch( event.key.keysym.sym )
     	    {
           		case SDLK_UP:
           		{
           			tank[0].set_flag_UP(false);break;
           		}
            	case SDLK_DOWN:
            	{
           			tank[0].set_flag_DOWN(false);break;
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

	if (numbers_of_player_in_game>=2)
	{

		if( event.type == SDL_KEYDOWN )//in ha rokh dad hastand halat nistand
  		{
        	//Adjust the velocity
      		switch( event.key.keysym.sym )
   			{
          		case SDLK_w:
           		{
           			tank[1].set_flag_UP(true);break;
            	}
      			case SDLK_s:
       			{
   			    	tank[1].set_flag_DOWN(true);break;
   				}
	            //for determining angle
            	case SDLK_a:
            	{
            		tank[1].set_omega(1);break;
            	}
            	case SDLK_d:
            	{
                	tank[1].set_omega(-1);break;
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
            		tank[1].set_flag_UP(false);break;
            	}
            	case SDLK_s:
            	{
            		tank[1].set_flag_DOWN(false);break;
            	}
            //for determining angle
            	case SDLK_a:
            	{
            		tank[1].set_omega(0);break;
            	}
            	case SDLK_d:
            	{
            		tank[1].set_omega(0);break;
            	}
       		}

		}
	}
}


void menu(SDL_Surface* SCREEN,int &numbers_of_player_in_game,SDL_Event &event)
{
	int mouse_xpos=0;
	int mouse_ypos=0;
	SDL_Surface* setting=IMG_Load("setting.png");
	SDL_Surface* playgame=IMG_Load("playgame.png");
	SDL_Surface* singleplayer=IMG_Load("singleplayer.png");
	SDL_Surface* twoplayer=IMG_Load("twoplayer.png");
	SDL_Surface* threeplayer=IMG_Load("threeplayer.png");
	SDL_Surface* fourplayer=IMG_Load("fourplayer.png");
	bool flag_show_playgame_and_setting=true;
	int setting_xpos=600;
	int setting_ypos=550;
	SDL_Rect setting_offset;
	setting_offset.x=setting_xpos;
	setting_offset.y=setting_ypos;
	int playgame_xpos=600;
	int playgame_ypos=150;
	SDL_Rect playgame_offset;
	playgame_offset.x=playgame_xpos;
	playgame_offset.y=playgame_ypos;
	int singleplayer_xpos=600;
	int singleplayer_ypos=30;
	//int singleplayer_final_ypos=30;
	SDL_Rect singleplayer_offset;
	singleplayer_offset.x=singleplayer_xpos;
	singleplayer_offset.y=singleplayer_ypos;
	int twoplayer_xpos=600;
	int twoplayer_ypos=30;//240
	int twoplayer_final_ypos=240;
	SDL_Rect twoplayer_offset;
	twoplayer_offset.x=twoplayer_xpos;
	twoplayer_offset.y=twoplayer_ypos;
	int threeplayer_xpos=600;
	int threeplayer_ypos=30;//450
	int threeplayer_final_ypos=450;
	SDL_Rect threeplayer_offset;
	threeplayer_offset.x=threeplayer_xpos;
	threeplayer_offset.y=threeplayer_ypos;
	int fourplayer_xpos=600;
	int fourplayer_ypos=30;//660
	int fourplayer_final_ypos=660;
	SDL_Rect fourplayer_offset;
	fourplayer_offset.x=fourplayer_xpos;
	fourplayer_offset.y=fourplayer_ypos;
	bool quit=true;
	int i=0;
	while(quit==true)
	{
		SDL_FreeSurface(SCREEN);
		boxRGBA(SCREEN,0,0,frame_width,frame_height,255,255,255,255);
		if (SDL_PollEvent(&event)){}
			if (event.type==SDL_QUIT)
			{
				exit(0);
			}
		mouse_xpos=event.motion.x;
		mouse_ypos=event.motion.y;
		if (mouse_xpos>playgame_xpos && mouse_xpos<playgame_xpos+playgame->w &&
			mouse_ypos>playgame_ypos && mouse_ypos<playgame_ypos+playgame->h)
		{
			flag_show_playgame_and_setting=false;
		}
		else if (mouse_xpos<playgame_xpos || mouse_xpos>playgame_xpos+playgame->w)
		{
			flag_show_playgame_and_setting=true;
			i=0;
		}
		if (flag_show_playgame_and_setting==false)
		{
			for (; i<20 ; i++)
			{
				twoplayer_offset.y=twoplayer_ypos+i*(twoplayer_final_ypos-30)/20.0;
				threeplayer_offset.y=threeplayer_ypos+i*(threeplayer_final_ypos-30)/20.0;
				fourplayer_offset.y=fourplayer_ypos+i*(fourplayer_final_ypos-30)/20.0;

				SDL_BlitSurface(singleplayer,NULL,SCREEN,&singleplayer_offset);
				SDL_BlitSurface(twoplayer,NULL,SCREEN,&twoplayer_offset);
				SDL_BlitSurface(threeplayer,NULL,SCREEN,&threeplayer_offset);
				SDL_BlitSurface(fourplayer,NULL,SCREEN,&fourplayer_offset);
				SDL_Flip(SCREEN);
			}
		}
		if(i==20)
		{
				SDL_BlitSurface(singleplayer,NULL,SCREEN,&singleplayer_offset);
				SDL_BlitSurface(twoplayer,NULL,SCREEN,&twoplayer_offset);
				SDL_BlitSurface(threeplayer,NULL,SCREEN,&threeplayer_offset);
				SDL_BlitSurface(fourplayer,NULL,SCREEN,&fourplayer_offset);
				SDL_Flip(SCREEN);
				SDL_FreeSurface(SCREEN);

			if (SDL_PollEvent(&event))
			{
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if (mouse_xpos>singleplayer_offset.x && mouse_xpos<singleplayer_offset.x+singleplayer->w
						&& mouse_ypos>singleplayer_offset.y && mouse_ypos<singleplayer_offset.y + singleplayer->h)
					{
						numbers_of_player_in_game=1;
						cout << "single\n";
						return;
					}

					else if (mouse_xpos>twoplayer_offset.x && mouse_xpos<twoplayer_offset.x+twoplayer->w
						&& mouse_ypos>twoplayer_offset.y && mouse_ypos<twoplayer_offset.y + twoplayer->h)
					{
						numbers_of_player_in_game=2;
						cout << "two\n";
						return;
					}

					else if (mouse_xpos>threeplayer_offset.x && mouse_xpos<threeplayer_offset.x+threeplayer->w
						&& mouse_ypos>threeplayer_offset.y && mouse_ypos<threeplayer_offset.y + threeplayer->h)
					{
						numbers_of_player_in_game=3;
						cout << "three\n";
						return;
					}

					else if (mouse_xpos>fourplayer_offset.x && mouse_xpos<fourplayer_offset.x+fourplayer->w
						&& mouse_ypos>fourplayer_offset.y && mouse_ypos<fourplayer_offset.y + fourplayer->h)
					{
						numbers_of_player_in_game=4;
						cout << "four\n";
						return;
					}
				}
			}
		}
		if (flag_show_playgame_and_setting==true)
		{
			SDL_BlitSurface(setting,NULL,SCREEN,&setting_offset);
			SDL_BlitSurface(playgame,NULL,SCREEN,&playgame_offset);
		}
		SDL_Flip(SCREEN);
	}
	return ;
}