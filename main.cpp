#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <sstream>
#include <SDL/SDL_gfxPrimitives.h>
#include "global_variables.h"
#include <iostream>
#include <cmath>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
using namespace std;
#define PI 3.1415
/////////////////////////////////////////////////////////////////////////////
//                             classes                                    //
///////////////////////////////////////////////////////////////////////////
	class Chopper
       	{
       	private:
       		int Xposition;
       		int Yposition;
       		int Xposition_center;
       		int Yposition_center;
       		int speed;
       		int Xspeed;
       		int Yspeed;
       		int angle;
       	public:
            void set_Xposition_center(int i)
       		{
       			Xposition_center=i;
       		}
       		void set_Yposition_center(int i)
       		{
       			Yposition_center=i;
       		}
       		void set_Xposition(int i)
       		{
       			Xposition=i;
       		}
       		void set_Yposition(int i)
       		{
       			Yposition=i;
       		}
       		void set_angle(int i)
       		{
       			angle=i;
       		}
       		void set_speed(int i)
       		{
       			speed=i;
       		}
       		void set_Xspeed(int i)
       		{
       			if (i==1)
       			{
       				Xspeed=speed*cos(angle/180.0*3.1415);
       			}
       			if (i==0)
       			{
       				Xspeed=0;
       			}
       		}
       		void set_Yspeed(int i)
       		{
       			if (i==1)
       			{
       				Yspeed=(-1)*speed*sin(angle/180.0*3.1415);
       			}
       			if (i==0)
       			{
       				Yspeed=0;
       			}
       		}
       		int get_Yposition_center()
       		{
       			return Yposition_center;
       		}
       		int get_Xposition_center()
       		{
       			return Xposition_center;
       		}
       		int get_Xposition()
       		{
       			return(Xposition);
       		}
       		int get_Yposition()
       		{
       			return(Yposition);
       		}
       		int get_angle()
       		{
       			return(angle);
       		}
       		int get_Xspeed()
       		{
       			return(Xspeed);
       		}
       		int get_Yspeed()
       		{
       			return(Yspeed);
       		}
       		void move()
       		{
       			Xposition+=Xspeed;
       			Yposition+=Yspeed;
       		}

       		void random_position()
       		{
       			int i=(int)(rand()%80)/20;
       			if (i==0)
       			{
       				set_Xposition(0);
       				set_Yposition(50+rand()%800);// bolandi safhe
       				//int j=(rand()%100)/50;
       				//if (j==0) j=(-1);
       				//set_angle(j*(rand()%70));
       			}
       			else if (i==1)
       			{
       				set_Yposition(0);
       				set_Xposition(100+rand()%1600);
       				//set_angle(190+rand()%160);
       			}
       			else if (i==2)
       			{
       				set_Xposition(1800);
       				set_Yposition(50+rand()%800);
       				//set_angle(100+rand()%160);
       			}
       			else if(i==3)
       			{
       				set_Yposition(1020);
       				set_Xposition(100+rand()%1600);
       				//set_angle(10+rand()%160);
       			}
       				//set_speed(10);
       				//set_Xspeed(1);
       				//set_Yspeed(1);
       		}
       	};


struct Clock
{
    uint32_t last_tick_time=0;
    uint32_t delta=0;

    int tick()
    {
        uint32_t tick_time = SDL_GetTicks();
        delta = tick_time - last_tick_time;
        last_tick_time = tick_time;
        return delta;
    }
}cl;

class Tank
{
	private:
		int tankScreen_width;
		int tankScreen_height;
		int critical_dot[12][2]; // 0 is x  and  1 is y
		int R;
		int G;
		int B;
		bool flag_UP;
		bool flag_DOWN;
		bool flag_exist;
		bool flag_laser;
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
		int weapon_kind;//felan ye no tir
		int variable_for_shoot2;
		int variable_for_shoot3;
		int bulletNum;
		int score;
		int laser_x1;
		int laser_x2;
		int laser_y1;
		int laser_y2;
		int variable_for_fire;
		bool flag_weapon1;
		bool flag_weapon2;
		bool flag_weapon3;
	public:
        void set_variable_for_fire(int i);
		int get_variable_for_fire();
        void set_R(int i);
        void set_G(int i);
        void set_B(int i);
		void set_tankScreen_width(int i);
		void set_tankScreen_height(int i);
		void set_flag_UP(bool i);
		void set_flag_DOWN(bool i);
		void set_flag_exist(bool i);
		void set_flag_laser(bool i);
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
		void set_weapon_kind(int i);
		void set_variable_for_shoot2(int i);
		void set_variable_for_shoot3(int i);
		void set_bulletNum(int i);
		void set_score(int i);
		void set_laser_x1(int i);
		void set_laser_x2(int i);
		void set_laser_y1(int i);
		void set_laser_y2(int i);

        void get_tankScreen_width(int i);
		void get_tankScreen_height(int i);
		bool get_flag_UP();
		bool get_flag_DOWN();
		bool get_flag_exist();
		bool get_flag_laser();
		int get_R();
		int get_G();
		int get_B();
		int get_variable_for_shoot2();
		int get_variable_for_shoot3();
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
		int get_weapon_kind();
		int get_bulletNum();
		int get_score();
		int get_critical_dot(int i,int j);
		int get_laser_x1();
		int get_laser_y1();
		int get_laser_x2();
		int get_laser_y2();

		/////////////////////////////
		void move(int i);
		void turn_around();

		void set_flag_weaponi(int i ,bool j)
		{
			if (i==1)
			{
				flag_weapon1==j;
			}
			else if (i==2)
			{
				flag_weapon2=j;
			}
			else if (i==3)
			{
				flag_weapon3=j;
			}
		}

		bool get_flag_weaponi(int i)
		{
			if (i==1)
			{
				return flag_weapon1;
			}
			if (i==2)
			{
				return flag_weapon2;
			}
			if (i==3)
			{
				return flag_weapon3;
			}
		}

};

void Tank::set_variable_for_fire(int i)
{
	variable_for_fire=i;
}
int Tank::get_variable_for_fire()
{
	return (variable_for_fire);
}

void Tank::set_score(int i)
{
    score=i;
}

void Tank::set_bulletNum(int i)
{
    bulletNum=i;
}

void Tank::set_R(int i)
{
    R=i;
}

void Tank::set_G(int i)
{
    G=i;
}

void Tank::set_B(int i)
{
    B=i;
}

void Tank::set_variable_for_shoot2(int i)
{
	variable_for_shoot2=i;
}

void Tank::set_variable_for_shoot3(int i)
{
	variable_for_shoot3=i;
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

		critical_dot[2][0]=get_Xposition_center()+ (3*tankScreen_height/5)*cos(get_angle()/180.0*3.1415);//x   3
		critical_dot[2][1]=get_Yposition_center()-(3*tankScreen_height/5)*sin(get_angle()/180.0*3.1415);//y

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
void Tank::set_flag_exist(bool i)
{
    flag_exist=i;
}
void Tank::set_flag_laser(bool i)
{
    flag_laser=i;
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
void Tank::set_weapon_kind(int i)
{
	weapon_kind=i;
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

void Tank::set_laser_x1(int i)
{
    laser_x1=i;
}

void Tank::set_laser_x2(int i)
{
    laser_x2=i;
}

void Tank::set_laser_y1(int i)
{
    laser_y1=i;
}

void Tank::set_laser_y2(int i)
{
    laser_y2=i;
}
////////////////////////////////////////
int Tank::get_score()
{
    return score;
}

int Tank::get_bulletNum()
{
    return bulletNum;
}

int Tank::get_R()
{
    return R;
}

int Tank::get_G()
{
    return G;
}

int Tank::get_B()
{
    return B;
}

int Tank::get_variable_for_shoot2()
{
	return(variable_for_shoot2);
}

int Tank::get_variable_for_shoot3()
{
	return(variable_for_shoot3);
}

bool Tank::get_flag_UP()
{
	return(flag_UP);
}
bool Tank::get_flag_DOWN()
{
	return(flag_DOWN);
}
bool Tank::get_flag_laser()
{
	return(flag_laser);
}
bool Tank::get_flag_exist()
{
    return flag_exist;
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
int Tank::get_weapon_kind()
{
	return(weapon_kind);
}
int Tank::get_critical_dot(int i,int j)
{
    return critical_dot[i][j];
}
int Tank::get_laser_x1()
{
    return laser_x1;
}
int Tank::get_laser_x2()
{
    return laser_x2;
}
int Tank::get_laser_y1()
{
    return laser_y1;
}
int Tank::get_laser_y2()
{
    return laser_y2;
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
        int startTime;
        int existingTime;
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
       	void collision_with_tank(SDL_Surface *SCREEN,Tank *tank,int i,Mix_Music *explosion);
       	void set_radius(int i);
       	void set_startTime(int i);
       	void set_currentTime(int i);
       	void set_existingTime(int i);
       	int get_Xposition();
       	int get_Yposition();
       	int get_speed();
       	int get_Xspeed();
       	int get_Yspeed();
       	int get_angle();
       	int get_radius();
       	int get_startTime();
       	int get_existingTime();
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


        void Bullet::collision_with_tank(SDL_Surface *SCREEN,Tank *tank,int i,Mix_Music *explosion)
        {
            int x=Xposition;
            int y=Yposition;
            int Vx=Xspeed;
            int Vy=Yspeed;

            Uint32 *pixels = (Uint32 *) SCREEN->pixels;
            Uint8 *color;

            if(Vx>=0 && Vy<=0)
            {
                color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x+radius+1)] );
                if(color[2]>tank[i].get_R()-10 && color[2]<tank[i].get_R()+10 && color[1]>tank[i].get_G()-10 && color[1]<tank[i].get_G()+10 && color[0]>tank[i].get_B()-10 && color[0]<tank[i].get_B()+10 && flag_exist==true)
                {
                    tank[i].set_health(tank[i].get_health()-5);
                    flag_exist=false;
                    //if( Mix_PlayChannel( -1, explosion, 0 ) == 0 ) Mix_PlayChannel(-1,explosion,0);
                    Mix_PlayMusic(explosion,0);
                }


                    color = (Uint8 *) & ( pixels[(y-radius-1) *SCREEN->w+(x)] );
                    if(color[2]>tank[i].get_R()-10 && color[2]<tank[i].get_R()+10 && color[1]>tank[i].get_G()-10 && color[1]<tank[i].get_G()+10 && color[0]>tank[i].get_B()-10 && color[0]<tank[i].get_B()+10 && flag_exist==true)
                    {
                        tank[i].set_health(tank[i].get_health()-5);
                        flag_exist=false;
                        //if( Mix_PlayChannel( -1, explosion, 0 ) == 0 ) Mix_PlayChannel(-1,explosion,0);
                        Mix_PlayMusic(explosion,0);
                    }
            }

            else if(Vx>=0 && Vy>=0)
            {
                color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x+radius+1)] );
                if(color[2]>tank[i].get_R()-10 && color[2]<tank[i].get_R()+10 && color[1]>tank[i].get_G()-10 && color[1]<tank[i].get_G()+10 && color[0]>tank[i].get_B()-10 && color[0]<tank[i].get_B()+10 && flag_exist==true)
                {
                    tank[i].set_health(tank[i].get_health()-5);
                    flag_exist=false;
                    //if( Mix_PlayChannel( -1, explosion, 0 ) == 0 ) Mix_PlayChannel(-1,explosion,0);
                    Mix_PlayMusic(explosion,0);
                }

                    color = (Uint8 *) & ( pixels[(y-radius-1) *SCREEN->w+(x)] );
                    if(color[2]>tank[i].get_R()-10 && color[2]<tank[i].get_R()+10 && color[1]>tank[i].get_G()-10 && color[1]<tank[i].get_G()+10 && color[0]>tank[i].get_B()-10 && color[0]<tank[i].get_B()+10 && flag_exist==true)
                    {
                        tank[i].set_health(tank[i].get_health()-5);
                        flag_exist=false;
                        //if( Mix_PlayChannel( -1, explosion, 0 ) == 0 ) Mix_PlayChannel(-1,explosion,0);
                        Mix_PlayMusic(explosion,0);
                    }
            }

            else if(Vx<=0 && Vy<=0)
            {
                color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x-radius-1)] );
                if(color[2]>tank[i].get_R()-10 && color[2]<tank[i].get_R()+10 && color[1]>tank[i].get_G()-10 && color[1]<tank[i].get_G()+10 && color[0]>tank[i].get_B()-10 && color[0]<tank[i].get_B()+10 && flag_exist==true)
                {
                    tank[i].set_health(tank[i].get_health()-5);
                    flag_exist=false;
                    //if( Mix_PlayChannel( -1, explosion, 0 ) == 0 ) Mix_PlayChannel(-1,explosion,0);
                    Mix_PlayMusic(explosion,0);
                }


                    color = (Uint8 *) & ( pixels[(y-radius-1) *SCREEN->w+(x)] );
                    if(color[2]>tank[i].get_R()-10 && color[2]<tank[i].get_R()+10 && color[1]>tank[i].get_G()-10 && color[1]<tank[i].get_G()+10 && color[0]>tank[i].get_B()-10 && color[0]<tank[i].get_B()+10 && flag_exist==true)
                    {
                        tank[i].set_health(tank[i].get_health()-5);
                        flag_exist=false;
                        //if( Mix_PlayChannel( -1, explosion, 0 ) == 0 ) Mix_PlayChannel(-1,explosion,0);
                        Mix_PlayMusic(explosion,0);
                    }
            }

            else if(Vx<=0 && Vy>=0)
            {
                color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x-radius-1)] );
                if(color[2]>tank[i].get_R()-10 && color[2]<tank[i].get_R()+10 && color[1]>tank[i].get_G()-10 && color[1]<tank[i].get_G()+10 && color[0]>tank[i].get_B()-10 && color[0]<tank[i].get_B()+10 && flag_exist==true)
                {
                    tank[i].set_health(tank[i].get_health()-5);
                    flag_exist=false;
                    //if( Mix_PlayChannel( -1, explosion, 0 ) == 0 ) Mix_PlayChannel(-1,explosion,0);
                    Mix_PlayMusic(explosion,0);
                }

                    color = (Uint8 *) & ( pixels[(y-radius-1) *SCREEN->w+(x)] );
                    if(color[2]>tank[i].get_R()-10 && color[2]<tank[i].get_R()+10 && color[1]>tank[i].get_G()-10 && color[1]<tank[i].get_G()+10 && color[0]>tank[i].get_B()-10 && color[0]<tank[i].get_B()+10 && flag_exist==true)
                    {
                        tank[i].set_health(tank[i].get_health()-5);
                        flag_exist=false;
                        //if( Mix_PlayChannel( -1, explosion, 0 ) == 0 ) Mix_PlayChannel(-1,explosion,0);
                        Mix_PlayMusic(explosion,0);
                    }
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

        void Bullet::set_startTime(int i)
        {
            startTime=i;
        }
        void Bullet::set_existingTime(int i)
        {
            existingTime=i;
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
       	int Bullet::get_startTime()
       	{
            return startTime;
       	}
       	int Bullet::get_existingTime()
       	{
            return existingTime;
       	}

    class Power_up
       	{
       		private:
       			int Xposition;
       			int Yposition;
       			int Xposition_center;
       			int Yposition_center;
       			bool flag_exist;
       			bool flag_show;

    		public:
    			void set_flag_show(bool i)
    			{
    				flag_show=i;
    			}
    			void set_Xposition(int i)
    			{
    				Xposition=i;
    			}
    			void set_Yposition(int i)
    			{
    				Yposition=i;
    			}
    			void set_Xposition_center(int i)
    			{
    				Xposition_center=i;
    			}
    			void set_Yposition_center(int i)
    			{
    				Yposition_center=i;
    			}
    			void set_flag_exist(bool i)
    			{
    				flag_exist=i;
    			}
    			bool get_flag_show()
    			{
    				return (flag_show);
    			}

    			int  get_Xposition()
    			{
    				return Xposition;
    			}
    			int  get_Yposition()
    			{
    				return Yposition;
    			}
    			int get_Xposition_center()
    			{
    				return Xposition_center;
    			}
    			int get_Yposition_center()
    			{
    				return Yposition_center;
    			}
    			int get_flag_exist()
    			{
    				return flag_exist;
    			}
       	};
///////////////////////////////////////////////////////////////////////////
//                     function headers                                  //
//////////////////////////////////////////////////////////////////////////
void check_if_power_up_is_gotten(Power_up *power_up,Tank* tank,int numbers_of_player_in_game , int i);
void check_if_chopper_drop_power_up(Chopper chopper,Power_up *power_up,int i);
int make_power_up(Power_up* power_up,int frame_height,int frame_width);
bool check_game_end(Tank *tank,int numbers_of_player_in_game);
int dictance(int x1 ,int y1 ,int x2,int y2);
int randomMap(int max_numbers_of_map,int mapNum);
//void handle_move_event(Tank*tank,int i);
void handle_move_event(Tank *tank,Bullet *bullet,int numbers_of_player_in_game);
void handle_fire_event(Tank *tank,Bullet *bullet ,int numbers_of_player_in_game );

void menu(SDL_Surface* SCREEN,int &numbers_of_player_in_game,SDL_Event &event);
void shift_bullets(Bullet *bullet);
void shoot(Tank *tank,Bullet *bullet , int i);
void shoot2(Tank *tank,int numbers_of_player_in_game,int k);
void shoot3(SDL_Surface *SCREEN,Tank *tank,int numbers_of_player_in_game,int k);
void apply_surface(int x,int y,SDL_Surface* source,SDL_Surface* destination);
char* NumToStr(int num);
void random_position(SDL_Surface *SCREEN,Tank *tank,int i);

////////////////////////////////////////////////////////////////////////////
//                      global variables                                //
///////////////////////////////////////////////////////////////////////////
int frame_width=1800;
int frame_height=1020;
int max_numbers_of_player=4;
int max_numbers_of_map=4;
SDL_Event event;
SDL_Surface* SCREEN = NULL;
SDL_Surface** tankScreen = new SDL_Surface*[max_numbers_of_player];
SDL_Surface** sparkScreen = new SDL_Surface*[max_numbers_of_player];
SDL_Surface** rotatedSpark = new SDL_Surface*[max_numbers_of_player];
SDL_Surface** mapScreen = new SDL_Surface*[max_numbers_of_map];
SDL_Surface** rotatedTank = new SDL_Surface*[max_numbers_of_player];
SDL_Surface** rotatedTankBG = new SDL_Surface*[max_numbers_of_player];
SDL_Surface** tankScreenBG = new SDL_Surface*[max_numbers_of_player];
SDL_Surface** chopperScreen = new SDL_Surface*[4];
SDL_Surface** rotatedChopper = new SDL_Surface*[4];
SDL_Surface** chopperShScreen = new SDL_Surface*[4];
SDL_Surface** rotatedShadow = new SDL_Surface*[4];
SDL_Surface** fireScreen = new SDL_Surface*[6];
SDL_Surface* heartScreen = new SDL_Surface;
SDL_Surface** power_upScreen = new SDL_Surface*[4];


SDL_Joystick *stick1=NULL;
SDL_Joystick *stick2=NULL;

Mix_Music *explosion;//=new MUS_WAV;
Mix_Music *plane;//=new MUS_MP3;
Mix_Music *emp;//=new MUS_MP3;
Mix_Music *Menu;//=new MUS_MP3;
Mix_Music *laser;//=new MUS_WAV;


////////////////////////////////////////////////////////////////////////////////////////////
//                                       main                                            //
////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	srand((unsigned)time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	SDL_INIT_JOYSTICK;
	Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
	explosion=Mix_LoadMUS("explosion.wav");
	plane=Mix_LoadMUS("Plane.mp3");
	emp=Mix_LoadMUS("EMP.mp3");
	Menu=Mix_LoadMUS("Menu.mp3");
	laser=Mix_LoadMUS("Laser.mp3");
	TTF_Font *font = TTF_OpenFont("font.ttf",18); // defining & loading font
	SDL_Color font_color={0,255,127};  // font color
	int last_mouse_right_click_Xposition=0;
	int last_mouse_right_click_Yposition=0;
	int mouse_Xposition;
	int mouse_Yposition;
	int numbers_of_player_in_game=2;
	int map_number_in_game;
	map_number_in_game=randomMap(max_numbers_of_map,map_number_in_game);

        cout<<SDL_NumJoysticks()<<endl;
        stick1=SDL_JoystickOpen(0);
        stick2=SDL_JoystickOpen(1);
        cout<<SDL_JoystickOpened(0)<<endl<<SDL_JoystickOpened(1)<<endl;//<<SDL_JoystickOpened(2)<<endl;

	SCREEN=SDL_SetVideoMode(frame_width,frame_height,32,SDL_SWSURFACE);
	const char* tankAddress[4]={"tank1.png","tank2.png","tank3.png","tank4.png"};
	const char* mapAddress[4]={"map1.png","map2.png","map3.png","map4.png"};
	const char* tankBGAddress[4]={"tank1z.png","tank2z.png","tank3z.png","tank4z.png"};
	const char* sparkAddress[4]={"spark1.png","spark2.png","spark3.png","spark4.png"};
    const char* chopperAddress[4]={"hele1.png","hele2.png","hele3.png","hele4.png"};
    const char* chopper_shadowAddress[4]={"helesh1.png","helesh2.png","helesh3.png","helesh4.png"};
    const char* heartAddress={"heart.png"};
    const char* fireAddress[6]={"fire1.png","fire2.png","fire3.png","fire4.png","fire5.png","fire6.png"};
    const char* power_upAddress[4]={"shoot.png","shoot2.png","shoot3.png","jon.png"};


    int spark_number=0;
    int chopper_number=0;
    heartScreen=IMG_Load(heartAddress);

    for (int i=0 ; i<4 ; i++)
  	{
  		power_upScreen[i]=NULL;
  		power_upScreen[i]=IMG_Load(power_upAddress[i]);
  		if (!(power_upAddress[i]))
  			printf("%s\n",IMG_GetError());
  	}

	for (int i=0 ; i<max_numbers_of_player; i++)
	{
		tankScreen[i]=NULL;
    	tankScreen[i]=IMG_Load(tankAddress[i]);
    	rotatedTank[i]=rotozoomSurface(tankScreen[i],/*angle*/0,/*zoom*/1.0,0);
    	if (!(tankScreen[i]))
    			printf("%s\n",IMG_GetError());

        tankScreenBG[i]=NULL;
        tankScreenBG[i]=IMG_Load(tankBGAddress[i]);
        rotatedTankBG[i]=rotozoomSurface(tankScreenBG[i],/*angle*/0,/*zoom*/1.0,0);
        if(!(tankScreenBG[i]))
    			printf("%s\n",IMG_GetError());
        if(!(rotatedChopper[i]))
    			printf("%s\n",IMG_GetError());
	}

    for(int i=0 ; i<4 ; i++)
	{
        chopperShScreen[i]=NULL;
        chopperShScreen[i]=IMG_Load(chopper_shadowAddress[i]);
        rotatedShadow[i]=rotozoomSurface(chopperShScreen[i],0,1.0,0);
        if(!(chopperShScreen[i]))
    			printf("%s\n",IMG_GetError());
	}


	for(int i=0 ; i<4 ; i++)
	{
        chopperScreen[i]=NULL;
        chopperScreen[i]=IMG_Load(chopperAddress[i]);
        rotatedChopper[i]=rotozoomSurface(chopperScreen[i],0,1.0,0);
        if(!(chopperScreen[i]))
    			printf("%s\n",IMG_GetError());
	}

	for (int i = 0; i < max_numbers_of_player; ++i)
	{
		sparkScreen[i]=IMG_Load(sparkAddress[i]);
		if (!(sparkScreen[i]))
    			printf("%s\n",IMG_GetError());
	}




	for (int i=0 ; i<max_numbers_of_map/*4*/; i++)
	{
	    mapScreen[i]=IMG_Load(mapAddress[i]);
	    if (!(mapScreen[i]))
    			printf("%s\n",IMG_GetError());
	}

	for (int i=0 ; i<6 ; i++)
	{
		fireScreen[i]=IMG_Load(fireAddress[i]);
		if (!(fireScreen[i]))
		{
			printf("%s\n",IMG_GetError());
		}
	}

    Mix_PlayMusic(Menu,-1);

    Power_up *power_up=new Power_up[4];
    Bullet *bullet=new Bullet[41];
	Tank *tank=new Tank[4];
	Chopper chopper;
	for (int i=0 ; i<numbers_of_player_in_game ; i++)
	{
		tank[i].set_score(0);
	}

	SDL_Rect fire_offset;
    SDL_Rect chopper_offset;
    SDL_Rect heart_offset[4];
    SDL_Rect tankInfo_offset;
	SDL_Rect spark_offset;
	SDL_Rect offset;
	SDL_Rect BG_offset;
	SDL_Rect power_up_offset;

	menu(SCREEN,numbers_of_player_in_game,event);
	int power_up_number=0;
	int rand_number=0;
	int frame_number=0;

	while(true)
	{
        if (rand_number==3)
        {
            SDL_Delay(3000);
            //neshan dadan barandeh
            menu(SCREEN,numbers_of_player_in_game,event);
            rand_number=0;
            for (int i=0 ; i<numbers_of_player_in_game ; i++)
            {
                tank[i].set_score(0);
            }
        }
        rand_number++;

	map_number_in_game=randomMap(max_numbers_of_map,map_number_in_game);

	for (int i=0 ; i<4 ; i++)
	{
		power_up[i].set_Xposition(0);
		power_up[i].set_Yposition(0);
		power_up[i].set_Xposition_center(25);
		power_up[i].set_Yposition_center(25);
		power_up[i].set_flag_exist(false);
		power_up[i].set_flag_show(false);
	}

	for (int i=0 ; i<numbers_of_player_in_game ; i++)
	{
		tank[i].set_flag_UP(false);
		tank[i].set_flag_DOWN(false);
		tank[i].set_flag_exist(true);
		tank[i].set_flag_laser(false);
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
		tank[i].set_weapon_kind(1);// 1-> is normal veapon
		tank[i].set_tankScreen_width(tankScreen[i]->w);
		tank[i].set_tankScreen_height(tankScreen[i]->h);
		tank[i].set_variable_for_shoot2(30);
		tank[i].set_variable_for_shoot3(30);
		tank[i].set_bulletNum(10);
		//tank[i].set_score(0);
		tank[i].set_critical_dots(SCREEN);
		tank[i].set_flag_weaponi(1,true);
		tank[i].set_flag_weaponi(2,false);
		tank[i].set_flag_weaponi(3,false);
		tank[i].set_variable_for_fire(22);
	}
        tank[0].set_R(46); // setting RGB colors for the background of tanks
        tank[0].set_G(122);
        tank[0].set_B(201);

        tank[1].set_R(116);
        tank[1].set_G(80);
        tank[1].set_B(43);

        tank[2].set_R(10);
        tank[2].set_G(170);
        tank[2].set_B(77);

        tank[3].set_R(248);
        tank[3].set_G(70);
        tank[3].set_B(170);

	for(int i=0 ; i<=40 ; i++)
	{
        bullet[i].set_Xposition(0);
        bullet[i].set_Yposition(0);
        bullet[i].set_flag_exist(false);
        bullet[i].set_angle(0);
        bullet[i].set_speed(12);
        bullet[i].set_Xspeed(0);
        bullet[i].set_Yspeed(0);
        bullet[i].set_radius(5);
        bullet[i].set_existingTime(7000);
    }

    //chopper.random_position();
	chopper.set_Xposition(-200);
	chopper.set_Yposition(-200);
	chopper.set_Xposition_center(chopperScreen[0]->w/2);
	chopper.set_Yposition_center(chopperScreen[0]->h/2);
    chopper.set_angle(0);
    chopper.set_speed(0);
    chopper.set_Xspeed(0);
    chopper.set_Yspeed(0);


    boxRGBA(SCREEN,0,0,frame_width,frame_height,100,100,100,255);
    SDL_BlitSurface(mapScreen[map_number_in_game],NULL,SCREEN,NULL);

	for(int i=0 ; i<numbers_of_player_in_game ; i++)
        random_position(SCREEN,tank,i);


    Mix_PauseMusic();

	bool Continue=true;

	while (Continue)
	{

        //cout<<tank[0].get_score()<<endl;
        SDL_WM_SetCaption("AlterTank 2018",NULL); // Title for game


            //cout << frame_number<<endl;
			frame_number++;

            if(frame_number%1000==900)
            {
                Mix_PlayMusic(plane,0);
            }
       		if (frame_number%1000==0)
       		{
				power_up_number = make_power_up(power_up,frame_height,frame_width);
				power_up[power_up_number].set_Xposition_center(power_up[power_up_number].get_Xposition()+power_upScreen[power_up_number]->w/2);
				power_up[power_up_number].set_Yposition_center(power_up[power_up_number].get_Yposition()+power_upScreen[power_up_number]->h/2);
       			chopper.random_position();
       			chopper.set_Xposition_center(chopper.get_Xposition()+rotatedChopper[0]->w/2);
				chopper.set_Yposition_center(chopper.get_Yposition()+rotatedChopper[0]->h/2);

       			if(chopper.get_Xposition()<power_up[power_up_number].get_Xposition())
       				chopper.set_angle( (int)(180 / 3.1415 * atan( (float)(power_up[power_up_number].get_Yposition_center()-chopper.get_Yposition_center()) / (float)(chopper.get_Xposition_center()-power_up[power_up_number].get_Xposition_center() )) ));
       			else
       				chopper.set_angle( 180 + (int)(180.0 / 3.14159265 * atan( (float)(power_up[power_up_number].get_Yposition_center()-chopper.get_Yposition_center()) / (float)(chopper.get_Xposition_center()-power_up[power_up_number].get_Xposition_center() )) ));
       			chopper.set_speed(10);
       			chopper.set_Xspeed(1);
       			chopper.set_Yspeed(1);
       		}

       		/*cout << "angle"<<chopper.get_angle()<<endl;
       		cout << "Xposition"<<chopper.get_Xposition()<<endl;
       		cout << "Yposition"<<chopper.get_Yposition()<<endl;*/

       		if (power_up[power_up_number].get_flag_exist()==true)
       		{
				check_if_chopper_drop_power_up(chopper,power_up,power_up_number);
       		}
       		if (power_up[power_up_number].get_flag_exist()==true && power_up[power_up_number].get_flag_show()==true)
       		{
 				check_if_power_up_is_gotten(power_up,tank,numbers_of_player_in_game ,power_up_number);
       		}

			if(frame_number==2000)	frame_number=0;


			if (SDL_PollEvent(&event))
			{

/*W*/			if(event.type==SDL_QUIT)
				{
					exit(0);
				}
				else
				{
                    handle_move_event(tank,bullet,numbers_of_player_in_game);
                    handle_fire_event(tank,bullet,numbers_of_player_in_game);
				}
			}

			//checking tank health
            for(int i=0 ; i<numbers_of_player_in_game ; i++)
            {
                if(tank[i].get_health()<=0)
                {
                	tank[i].set_flag_exist(false);
                	if(tank[i].get_variable_for_fire()==22)
                		tank[i].set_variable_for_fire(0);
                }
            }

			boxRGBA(SCREEN,0,0,frame_width,frame_height,100,100,100,255);

/*H*/

			//set tank speed
        	for (int i=0 ; i<numbers_of_player_in_game ; i++)
			{
				SDL_FreeSurface(rotatedTank[i]);
				tank[i].turn_around();
/*I*/				rotatedTank[i]=rotozoomSurface(tankScreen[i],tank[i].get_angle()-90,1.0,0);
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
                if((SDL_GetTicks())-bullet[i].get_startTime()>=bullet[i].get_existingTime())
                    bullet[i].set_flag_exist(false);
/*T*/           if(bullet[i].get_flag_exist()==true)
            	{
               		filledCircleRGBA(SCREEN,bullet[i].get_Xposition(),bullet[i].get_Yposition(),5,255,165,0,255);
               		bullet[i].move();
            	}
        	}




            for(int i=0;i<numbers_of_player_in_game;i++)
			{
/*R*/           if(tank[i].get_flag_exist()==true)
                {
                    BG_offset.x=tank[i].get_Xposition();
                    BG_offset.y=tank[i].get_Yposition();
                    BG_offset.x-=rotatedTank[i]->w/2-tankScreen[i]->w/2;
                    BG_offset.y-=rotatedTank[i]->h/2-tankScreen[i]->h/2;
                    rotatedTankBG[i]=rotozoomSurface(tankScreenBG[i],tank[i].get_angle()-90,1.0,0);
                    SDL_BlitSurface(rotatedTankBG[i],NULL,SCREEN,&BG_offset);
                    SDL_FreeSurface(rotatedTankBG[i]);
                }
			}

            for(int i=0 ; i<numbers_of_player_in_game ; i++)
            {
                if(tank[i].get_flag_laser()==true)
                {
                    shoot3(SCREEN,tank,numbers_of_player_in_game,i);
                    tank[i].set_flag_laser(false);
                }

                if(tank[i].get_variable_for_shoot3() < 20)
				{
                    lineRGBA(SCREEN,tank[i].get_laser_x1(),tank[i].get_laser_y1(),tank[i].get_laser_x2(),tank[i].get_laser_y2(),255,0,0,255);
                    tank[i].set_variable_for_shoot3(tank[i].get_variable_for_shoot3()+1);
				}
            }


            //checking bullet collision with tanks
            for(int i=0 ; i<numbers_of_player_in_game ; i++)
            {
                if(tank[i].get_flag_exist()==true)
                    for(int j=0 ; j<40 ; j++)
                    {
                        if(bullet[j].get_flag_exist()==true)
                            bullet[j].collision_with_tank(SCREEN,tank,i,explosion);
                    }
            }


        	//blit all surface and set center of each tank
			for(int i=0;i<numbers_of_player_in_game;i++)
			{
                if(tank[i].get_flag_exist()==true)
                {
/*U*/			    tank[i].set_Xposition_center(tankScreen[i]->w/2+tank[i].get_Xposition());
                    tank[i].set_Yposition_center(tankScreen[i]->h/2+tank[i].get_Yposition());
                    offset.x=tank[i].get_Xposition();
                    offset.y=tank[i].get_Yposition();
                    offset.x-=rotatedTank[i]->w/2-tankScreen[i]->w/2;
                    offset.y-=rotatedTank[i]->h/2-tankScreen[i]->h/2;
                    //rotatedTank[i]=rotozoomSurface(tankScreen[i],tank[i].get_angle()-90,1.0,0);
                    SDL_BlitSurface(rotatedTank[i],NULL,SCREEN,&offset);
                    tank[i].set_critical_dots(SCREEN);
                    //SDL_FreeSurface(rotatedTank[i]);

                    //showing tank information under the map
                    tankInfo_offset.x=225+i*450;
                    tankInfo_offset.y=930;
                    heart_offset[i].x=175+i*450;
                    heart_offset[i].y=927;
                    SDL_BlitSurface(tankScreen[i],NULL,SCREEN,&tankInfo_offset);

                    //showing health
                    SDL_Surface *message =TTF_RenderText_Solid(font,NumToStr(tank[i].get_health()),font_color);
                    apply_surface(tankInfo_offset.x-25,tankInfo_offset.y,message,SCREEN);
                    SDL_BlitSurface(heartScreen,NULL,SCREEN,&heart_offset[i]);

                    //showing bullet number
                    message =TTF_RenderText_Solid(font,NumToStr(tank[i].get_bulletNum()),font_color);
                    filledCircleRGBA(SCREEN,tankInfo_offset.x-33,tankInfo_offset.y+61,5,255,165,0,255);
                    apply_surface(tankInfo_offset.x-25,tankInfo_offset.y+50,message,SCREEN);

                    //showing score
                    message =TTF_RenderText_Solid(font,"Score =",font_color);
                    apply_surface(tankInfo_offset.x+60,tankInfo_offset.y,message,SCREEN);
                    message =TTF_RenderText_Solid(font,NumToStr(tank[i].get_score()),font_color);
                    apply_surface(tankInfo_offset.x+122,tankInfo_offset.y,message,SCREEN);

                    //showing weapon kind
                    if(tank[i].get_weapon_kind()==1)
                    message =TTF_RenderText_Solid(font,"Normal",font_color);
                    else if(tank[i].get_weapon_kind()==2)
                    message =TTF_RenderText_Solid(font,"EMP",font_color);
                    else if(tank[i].get_weapon_kind()==3)
                    message =TTF_RenderText_Solid(font,"Laser",font_color);
                    apply_surface(tankInfo_offset.x+60,tankInfo_offset.y+50,message,SCREEN);
				}
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
					if(tank[i].get_variable_for_shoot2() == 20 )
                        tank[i].set_health(tank[i].get_health()-2);
				}
			}

			//creat animation for fire tank
			for (int i=0 ; i<numbers_of_player_in_game ; i++)
			{
				if (tank[i].get_variable_for_fire()<=20)
				{
					fire_offset.x=tank[i].get_Xposition();
					fire_offset.y=tank[i].get_Yposition();
					fire_offset.x-=rotatedTank[i]->w/2-tankScreen[i]->w/2;
					fire_offset.y-=rotatedTank[i]->h/2-tankScreen[i]->h/2;
					//
					SDL_BlitSurface(fireScreen[frame_number%6],NULL,SCREEN,&fire_offset);
					tank[i].set_variable_for_fire(tank[i].get_variable_for_fire()+1);
				}
			}

            // map is included to surface
			SDL_BlitSurface(mapScreen[map_number_in_game],NULL,SCREEN,NULL);

			if (power_up[power_up_number].get_flag_show()==true && power_up[power_up_number].get_flag_exist()==true)
       		{
       			//cout << "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk"<<endl;
       			//cout << power_up_number<<endl;
       			power_up_offset.x=power_up[power_up_number].get_Xposition();
       			power_up_offset.y=power_up[power_up_number].get_Yposition();
       			SDL_BlitSurface(power_upScreen[power_up_number],NULL,SCREEN,&power_up_offset);
       			//cout << "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk"<<endl;
       		}

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

       		// CHOPPER operation={movment and shadow creation}
       		chopper.move();

       		SDL_FreeSurface(rotatedShadow[frame_number%4]);
       		SDL_FreeSurface(rotatedChopper[frame_number%4]);

       		chopper_offset.x=chopper.get_Xposition();
       		chopper_offset.y=chopper.get_Yposition();
       		chopper_offset.y+=100;

       		rotatedShadow[frame_number%4]=rotozoomSurface(chopperShScreen[frame_number%4],chopper.get_angle()-90,1.5,0);
       		rotatedChopper[frame_number%4]=rotozoomSurface(chopperScreen[frame_number%4],chopper.get_angle()-90,2,0);


       		SDL_BlitSurface(rotatedShadow[frame_number%4],NULL,SCREEN,&chopper_offset);
       		chopper_offset.y=chopper.get_Yposition();
       		chopper_offset.x=chopper.get_Xposition();

       		SDL_BlitSurface(rotatedChopper[frame_number%4],NULL,SCREEN,&chopper_offset);

       		chopper.set_Xposition_center(chopper.get_Xposition()+rotatedChopper[0]->w/2);
			chopper.set_Yposition_center(chopper.get_Yposition()+rotatedChopper[0]->h/2);
       		//filledCircleRGBA(SCREEN,chopper.get_Xposition_center(),chopper.get_Yposition_center(),20,255,0,0,255);

        int time=cl.tick();
		SDL_Flip(SCREEN);
		if(time<10)	SDL_Delay(10-time);
		else 	SDL_Delay(10);
		SDL_FreeSurface(SCREEN);
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////new code
		if(frame_number%200==0)
        {
            Continue=check_game_end(tank,numbers_of_player_in_game);
        }
	}
	}
return 0;
}

//////////////////////////////////////////////////////////////////////////

//                             functions                                //

//////////////////////////////////////////////////////////////////////////

int  make_power_up(Power_up* power_up,int frame_height,int frame_width)
{
	int x = 200+rand()%1400;
	int y = 200+rand()%500;

	int i = rand()%100;
	if (i>=0 && i<25)
	{
		power_up[0].set_Xposition(x);
		power_up[0].set_Yposition(y);
		power_up[0].set_flag_exist(true);
		return(0);
	}
	else if (i>=25 && i<50)
	{
		power_up[1].set_Xposition(x);
		power_up[1].set_Yposition(y);
		power_up[1].set_flag_exist(true);
		return(1);
	}
	else if (i>=50 && i<75)
	{
		power_up[2].set_Xposition(x);
		power_up[2].set_Yposition(y);
		power_up[2].set_flag_exist(true);
		return(2);
	}
	else if (i>=75 && i<100)
	{
		power_up[3].set_Xposition(x);
		power_up[3].set_Yposition(y);
		power_up[3].set_flag_exist(true);
		return(3);
	}
}

void check_if_chopper_drop_power_up(Chopper chopper,Power_up *power_up,int i)
{
			if (dictance(chopper.get_Xposition_center(),chopper.get_Yposition_center(),power_up[i].get_Xposition_center(),power_up[i].get_Yposition_center()) < 50 )
			{
				power_up[i].set_flag_show(true);
				//cout << "OK check_if_chopper_drop_power_up"<<endl;
			}
}
void check_if_power_up_is_gotten(Power_up *power_up,Tank* tank,int numbers_of_player_in_game , int i)
{
	for (int j=0; j<numbers_of_player_in_game; j++)
	{
		if (dictance(tank[j].get_Xposition_center(),tank[j].get_Yposition_center(),power_up[i].get_Xposition_center(),power_up[i].get_Yposition_center())  < 60)
		{
			if (i==0)
			{
				tank[j].set_bulletNum(tank[j].get_bulletNum()+5);
			}
			else if (i==1)
			{
				tank[j].set_flag_weaponi(2,true);
			}
			else if (i==2)
			{
				tank[j].set_flag_weaponi(3,true);
			}
			else if (i==3)
			{
				tank[j].set_health(tank[j].get_health()+5);
			}
			power_up[i].set_flag_exist(false);
			power_up[i].set_flag_show(false);

		}
	}
}


bool check_game_end(Tank *tank,int numbers_of_player_in_game)
{
	int k=0;
	int m=0;
	for (int i=0 ; i<numbers_of_player_in_game ; i++ )
	{
		if(tank[i].get_flag_exist()==true)
		{
			k++;
			m=i;
		}
	}
	if (k==1)
	{
		tank[m].set_score(tank[m].get_score() + 1);
		return (false);
	}
	else if (k==0)
	{
		return (false);
	}
	return (true);
}

void random_position(SDL_Surface *SCREEN,Tank *tank,int i)
{
    Uint32 *pixels = (Uint32 *) SCREEN->pixels;
    Uint8 *color=(Uint8 *) & ( pixels[(100) *SCREEN->w+(100)] );
    int x0;
    int y0;
    int angle;

    bool flag=true;
    while(flag)
    {
        //angle=rand()%360;
        //tank[i].set_angle(angle);
        //rotatedTank[i]=rotozoomSurface(tankScreen[i],tank[i].get_angle()-90,1.0,0);

        x0=rand()%(frame_width-100)+50;
        y0=rand()%(frame_height-170)+50;
        int x=x0-sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/2),2))*cos(tank[i].get_angle()/180.0*3.1415+PI/2-atan2(tank[i].get_tankScreen_height()/2,tank[i].get_tankScreen_width()/2));
        int y=y0+sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/2),2))*sin(tank[i].get_angle()/180.0*3.1415+PI/2-atan2(tank[i].get_tankScreen_height()/2,tank[i].get_tankScreen_width()/2));
        /*int x0=x+sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/2),2))*cos(tank[i].get_angle()/180.0*3.1415+atan2((tank[i].get_tankScreen_width()),(tank[i].get_tankScreen_height())));
        int y0=y-sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/4),2))*sin(tank[i].get_angle()/180.0*3.1415+atan2((tank[i].get_tankScreen_width()),(tank[i].get_tankScreen_height())));
        x0-=rotatedTank[i]->w/2-tankScreen[i]->w/2;
        y0-=rotatedTank[i]->h/2-tankScreen[i]->h/2;
        x=x0-sqrt(pow((x-x0),2)+pow((y-y0),2))*cos(tank[i].get_angle()/180.0*3.1415+PI/2-atan2(tank[i].get_tankScreen_height()/2,tank[i].get_tankScreen_width()/2));
        y=y0+sqrt(pow((x-x0),2)+pow((y-y0),2))*sin(tank[i].get_angle()/180.0*3.1415+PI/2-atan2(tank[i].get_tankScreen_height()/2,tank[i].get_tankScreen_width()/2));*/


        color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x)] );

        if( color[2]==100 && color[1]==100 && color[0]==100)
        {
                tank[i].set_Xposition_center(x);
                tank[i].set_Yposition_center(y);
                tank[i].set_critical_dots(SCREEN);
                int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12;
                int y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12;

                x1=x+sqrt(pow((tank[i].get_tankScreen_height()/4),2)+pow((tank[i].get_tankScreen_width()/2),2))*cos(tank[i].get_angle()/180.0*3.1415-PI/2+atan2((tank[i].get_tankScreen_height()/4),(tank[i].get_tankScreen_width()/2))) ;
                y1=y-sqrt(pow((tank[i].get_tankScreen_height()/4),2)+pow((tank[i].get_tankScreen_width()/2),2))*sin(tank[i].get_angle()/180.0*3.1415-PI/2+atan2((tank[i].get_tankScreen_height()/4),(tank[i].get_tankScreen_width()/2))) ;

                x2=x+sqrt(pow((tank[i].get_tankScreen_height()/4),2)+pow((tank[i].get_tankScreen_width()/2),2))*cos(tank[i].get_angle()/180.0*3.1415+3*PI/2-atan2((tank[i].get_tankScreen_height()/4),(tank[i].get_tankScreen_width()/2))) ;
                y2=y-sqrt(pow((tank[i].get_tankScreen_height()/4),2)+pow((tank[i].get_tankScreen_width()/2),2))*sin(tank[i].get_angle()/180.0*3.1415+3*PI/2-atan2((tank[i].get_tankScreen_height()/4),(tank[i].get_tankScreen_width()/2))) ;

                x3= x+sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/4),2))*cos(tank[i].get_angle()/180.0*3.1415+PI/2-atan2((tank[i].get_tankScreen_height()/4),(tank[i].get_tankScreen_width()/2)));
                y3= y-sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/4),2))*sin(tank[i].get_angle()/180.0*3.1415+PI/2-atan2((tank[i].get_tankScreen_height()/4),(tank[i].get_tankScreen_width()/2)));

                x4= x+sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/4),2))*cos(tank[i].get_angle()/180.0*3.1415+PI/2+atan2((tank[i].get_tankScreen_height()/4),(tank[i].get_tankScreen_width()/2)));
                y4= y-sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/4),2))*sin(tank[i].get_angle()/180.0*3.1415+PI/2+atan2((tank[i].get_tankScreen_height()/4),(tank[i].get_tankScreen_width()/2)));

                x5=x+sqrt(pow((3*tank[i].get_tankScreen_height()/8),2)+pow((tank[i].get_tankScreen_width()/2),2))*cos(tank[i].get_angle()/180.0*3.1415-PI/2+atan2((3*tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2))) ;
                y5=y-sqrt(pow((3*tank[i].get_tankScreen_height()/8),2)+pow((tank[i].get_tankScreen_width()/2),2))*sin(tank[i].get_angle()/180.0*3.1415-PI/2+atan2((3*tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2))) ;

                x6=x+sqrt(pow((3*tank[i].get_tankScreen_height()/8),2)+pow((tank[i].get_tankScreen_width()/2),2))*cos(tank[i].get_angle()/180.0*3.1415+3*PI/2-atan2((3*tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2))) ;
                y6=y-sqrt(pow((3*tank[i].get_tankScreen_height()/8),2)+pow((tank[i].get_tankScreen_width()/2),2))*sin(tank[i].get_angle()/180.0*3.1415+3*PI/2-atan2((3*tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2))) ;

                x7=x+sqrt(pow((tank[i].get_tankScreen_height()/8),2)+pow((tank[i].get_tankScreen_width()/2),2))*cos(tank[i].get_angle()/180.0*3.1415-PI/2+atan2((tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2))) ;
                y7=y-sqrt(pow((tank[i].get_tankScreen_height()/8),2)+pow((tank[i].get_tankScreen_width()/2),2))*sin(tank[i].get_angle()/180.0*3.1415-PI/2+atan2((tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2))) ;

                x8=x+sqrt(pow((tank[i].get_tankScreen_height()/8),2)+pow((tank[i].get_tankScreen_width()/2),2))*cos(tank[i].get_angle()/180.0*3.1415+3*PI/2-atan2((tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2))) ;
                y8=y-sqrt(pow((tank[i].get_tankScreen_height()/8),2)+pow((tank[i].get_tankScreen_width()/2),2))*sin(tank[i].get_angle()/180.0*3.1415+3*PI/2-atan2((tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2))) ;

                x9= x+sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((3*tank[i].get_tankScreen_height()/8),2))*cos(tank[i].get_angle()/180.0*3.1415+PI/2-atan2((3*tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2)));
                y9= y-sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((3*tank[i].get_tankScreen_height()/8),2))*sin(tank[i].get_angle()/180.0*3.1415+PI/2-atan2((3*tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2)));

                x10= x+sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((3*tank[i].get_tankScreen_height()/8),2))*cos(tank[i].get_angle()/180.0*3.1415+PI/2+atan2((3*tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2)));
                y10= y-sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((3*tank[i].get_tankScreen_height()/8),2))*sin(tank[i].get_angle()/180.0*3.1415+PI/2+atan2((3*tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2)));

                x11= x+sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/8),2))*cos(tank[i].get_angle()/180.0*3.1415+PI/2-atan2((tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2)));
                y11= y-sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/8),2))*sin(tank[i].get_angle()/180.0*3.1415+PI/2-atan2((tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2)));

                x12= x+sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/8),2))*cos(tank[i].get_angle()/180.0*3.1415+PI/2+atan2((tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2)));
                y12= y-sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/8),2))*sin(tank[i].get_angle()/180.0*3.1415+PI/2+atan2((tank[i].get_tankScreen_height()/8),(tank[i].get_tankScreen_width()/2)));


                bool f=true;

                color = (Uint8 *) & ( pixels[(y1) *SCREEN->w+(x1)] );
                if( color[2]>230 && color[1]>230 && color[0]>230 ) f=false;

                color = (Uint8 *) & ( pixels[(y2) *SCREEN->w+(x2)] );
                if( color[2]>230 && color[1]>230 && color[0]>230 ) f=false;

                color = (Uint8 *) & ( pixels[(y3) *SCREEN->w+(x3)] );
                if( color[2]>230 && color[1]>210 && color[0]>230 ) f=false;

                color = (Uint8 *) & ( pixels[(y4) *SCREEN->w+(x4)] );
                if( color[2]>230 && color[1]>230 && color[0]>230 ) f=false;

                color = (Uint8 *) & ( pixels[(y5) *SCREEN->w+(x5)] );
                if( color[2]>230 && color[1]>230 && color[0]>230 ) f=false;

                color = (Uint8 *) & ( pixels[(y6) *SCREEN->w+(x6)] );
                if( color[2]>230 && color[1]>230 && color[0]>230 ) f=false;

                color = (Uint8 *) & ( pixels[(y7) *SCREEN->w+(x7)] );
                if( color[2]>230 && color[1]>230 && color[0]>230 ) f=false;

                color = (Uint8 *) & ( pixels[(y8) *SCREEN->w+(x8)] );
                if( color[2]>230 && color[1]>230 && color[0]>230 ) f=false;

                color = (Uint8 *) & ( pixels[(y9) *SCREEN->w+(x9)] );
                if( color[2]>230 && color[1]>230 && color[0]>230 ) f=false;

                color = (Uint8 *) & ( pixels[(y10) *SCREEN->w+(x10)] );
                if( color[2]>230 && color[1]>230 && color[0]>230 ) f=false;

                color = (Uint8 *) & ( pixels[(y11) *SCREEN->w+(x11)] );
                if( color[2]>230 && color[1]>230 && color[0]>230 ) f=false;

                color = (Uint8 *) & ( pixels[(y12) *SCREEN->w+(x12)] );
                if( color[2]>230 && color[1]>230 && color[0]>230 ) f=false;


                if(f==true)
                for(int k=0 ; k<12 ; k++)
                {
                    color = (Uint8 *) & ( pixels[(tank[i].get_critical_dot(k,1)) *SCREEN->w+(tank[i].get_critical_dot(k,0))] );
                    if( color[2]>230 && color[1]>230 && color[0]>230 )
                    f=false;
                }

                if(f==true)
                {
                    tank[i].set_Xposition( x+sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/2),2))*cos(tank[i].get_angle()/180.0*3.1415+atan2((tank[i].get_tankScreen_width()),(tank[i].get_tankScreen_height()))) );
                    tank[i].set_Yposition( y-sqrt(pow((tank[i].get_tankScreen_width()/2),2)+pow((tank[i].get_tankScreen_height()/4),2))*sin(tank[i].get_angle()/180.0*3.1415+atan2((tank[i].get_tankScreen_width()),(tank[i].get_tankScreen_height()))) );

                    tank[i].set_Xposition_center(x);
                    tank[i].set_Yposition_center(y);

                    flag=false;
                }
        }

    }

}

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

void shoot(Tank *tank,Bullet *bullet , int i)  // Ordinary bullets
{
    bullet[0].set_Xposition(tank[i].get_Xposition_center() + (tank[i].get_tankScreen_height()/2)*cos(tank[i].get_angle()/180.0*3.1415));
    bullet[0].set_Yposition(tank[i].get_Yposition_center() - (tank[i].get_tankScreen_height()/2)*sin(tank[i].get_angle()/180.0*3.1415));
    bullet[0].set_angle(tank[i].get_angle());
    bullet[0].set_Xspeed(1);
    bullet[0].set_Yspeed(1);
    bullet[0].set_flag_exist(true);
    bullet[0].set_startTime((int)(SDL_GetTicks()));
    shift_bullets(bullet);
}

void shoot2(Tank *tank,int numbers_of_player_in_game,int k) // EMP damage area
{
	for (int i ; i<numbers_of_player_in_game ; i++)
	{
		if (i!=k)
            if (tank[i].get_flag_exist()==true)
                if (dictance(tank[i].get_Xposition_center(),tank[i].get_Yposition_center(),tank[k].get_Xposition_center(),tank[k].get_Yposition_center())  <  500)
                {
                    tank[i].set_variable_for_shoot2(0);
                }
	}
	Mix_PlayMusic(emp,0);
}

void shoot3(SDL_Surface *SCREEN,Tank *tank,int numbers_of_player_in_game,int k) // Laser shot
{
    int x1 = tank[k].get_Xposition_center() + (tank[k].get_tankScreen_height()/2)*cos(tank[k].get_angle()/180.0*3.1415);
    int y1 = tank[k].get_Yposition_center() - (tank[k].get_tankScreen_height()/2)*sin(tank[k].get_angle()/180.0*3.1415);
    int x2,y2,n;
    int theta=tank[k].get_angle();
    double m=-1*tan(theta/180.0*3.1415);
    Uint32 *pixels = (Uint32 *) SCREEN->pixels;
    Uint8 *color;

    if(x1>tank[k].get_Xposition_center())
    {
        int x=1780;
        int y=y1+m*(x-x1);
        if(y>0 && y<900) n=1;
    }
    else if(x1<tank[k].get_Xposition_center())
    {
        int x=20;
        int y=y1+m*(x-x1);
        if(y>0 && y<900) n=2;
    }

    if(y1<tank[k].get_Yposition_center())
    {
        int y=20;
        int x=(y-y1+m*x1)/m;
        if(x>0 && x<1800) n=3;
    }
    else if(y1>tank[k].get_Yposition_center())
    {
        int y=900;
        int x=(y-y1+m*x1)/m;
        if(x>0 && x<1800) n=4;
    }

    if(n==1)  //Right
    {
        bool flag_hit=false;
        bool f=true;
        for(int x=x1 ; x<1800 ; x+=10)
        {
            int y=y1+m*(x-x1);
            color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x)] );
            if(f==true)
            for(int i=0 ; i<numbers_of_player_in_game ; i++)
            {
                if( i!=k )
                {
                    if(color[2]>tank[i].get_R()-10 && color[2]<tank[i].get_R()+10 && color[1]>tank[i].get_G()-10 && color[1]<tank[i].get_G()+10 && color[0]>tank[i].get_B()-10 && color[0]<tank[i].get_B()+10)
                    {
                        x2=x;
                        y2=y;
                        flag_hit=true;
                        tank[i].set_health(tank[i].get_health()-5);
                        f=false;
                    }
                }
            }
            else break;
        }
        if(flag_hit==false)
        {
            x2=1780;
            y2=y1+m*(x2-x1);
        }
    }

    else if(n==2)  //Left
    {
        bool flag_hit=false;
        bool f=true;
        for(int x=x1 ; x>0 ; x-=10)
        {
            int y=y1+m*(x-x1);
            color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x)] );
            if(f==true)
            for(int i=0 ; i<numbers_of_player_in_game ; i++)
            {
                if(i!=k)
                {
                    if(color[2]>tank[i].get_R()-10 && color[2]<tank[i].get_R()+10 && color[1]>tank[i].get_G()-10 && color[1]<tank[i].get_G()+10 && color[0]>tank[i].get_B()-10 && color[0]<tank[i].get_B()+10)
                    {
                        x2=x;
                        y2=y;
                        flag_hit=true;
                        tank[i].set_health(tank[i].get_health()-5);
                        f=false;
                    }
                }
            }
            else break;
        }
        if(flag_hit==false)
        {
            x2=20;
            y2=y1+m*(x2-x1);
        }
    }

    else if(n==3)  //Up
    {
        bool flag_hit=false;
        bool f=true;
        for(int y=y1 ; y>0 ; y-=10)
        {
            int x=(y-y1+m*x1)/m;
            color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x)] );
            if(f==true)
            for(int i=0 ; i<numbers_of_player_in_game ; i++)
            {
                if(i!=k)
                {
                    if(color[2]>tank[i].get_R()-10 && color[2]<tank[i].get_R()+10 && color[1]>tank[i].get_G()-10 && color[1]<tank[i].get_G()+10 && color[0]>tank[i].get_B()-10 && color[0]<tank[i].get_B()+10)
                    {
                        x2=x;
                        y2=y;
                        flag_hit=true;
                        tank[i].set_health(tank[i].get_health()-5);
                        f=false;
                    }
                }
            }
            else break;
        }
        if(flag_hit==false)
        {
            y2=20;
            x2=(y2-y1+m*x1)/m;
        }
    }

    else if(n==4)  //Down
    {
        bool flag_hit=false;
        bool f=true;
        for(int y=y1 ; y<1020 ; y+=10)
        {
            int x=(y-y1+m*x1)/m;
            color = (Uint8 *) & ( pixels[(y) *SCREEN->w+(x)] );
            if(f==true)
            for(int i=0 ; i<numbers_of_player_in_game ; i++)
            {
                if(i!=k)
                {
                    if(color[2]>tank[i].get_R()-10 && color[2]<tank[i].get_R()+10 && color[1]>tank[i].get_G()-10 && color[1]<tank[i].get_G()+10 && color[0]>tank[i].get_B()-10 && color[0]<tank[i].get_B()+10)
                    {
                        x2=x;
                        y2=y;
                        flag_hit=true;
                        tank[i].set_health(tank[i].get_health()-5);
                        f=false;
                    }
                }
            }
            else break;
        }
        if(flag_hit==false)
        {
            y2=880;
            x2=(y2-y1+m*x1)/m;
        }
    }

    tank[k].set_variable_for_shoot3(0);
    tank[k].set_laser_x1(x1);
    tank[k].set_laser_x2(x2);
    tank[k].set_laser_y1(y1);
    tank[k].set_laser_y2(y2);

    tank[k].set_flag_laser(false);
    Mix_PlayMusic(laser,0);

}

void handle_fire_event(Tank *tank,Bullet *bullet ,int numbers_of_player_in_game)
{
	if (event.type==SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_m:
			{
                if(tank[0].get_flag_exist()==true)
				if (numbers_of_player_in_game>=1)
				{
					switch(tank[0].get_weapon_kind())
					{
						case 1:
						{
                            if(tank[0].get_bulletNum()>0)
                            {
                                shoot(tank,bullet,0);
                                tank[0].set_bulletNum(tank[0].get_bulletNum()-1);
                            }
						} break;
						case 2:
						{
							if (tank[0].get_flag_weaponi(2)==true)
                            {
                                tank[0].set_flag_weaponi(2,false);
                                shoot2(tank,numbers_of_player_in_game,0);
                            }
						} break;
						case 3:
						{
                            if (tank[0].get_flag_weaponi(3)==true)
                            {
                                tank[0].set_flag_weaponi(3,false);
                                tank[0].set_flag_laser(true);
                            }
						} break;
					}
				}
			} break;

            case SDLK_n:
			{
				if(tank[0].get_flag_exist()==true)
					if (tank[0].get_weapon_kind()==3)
					{
						tank[0].set_weapon_kind(1);
					}
					else if(tank[0].get_flag_weaponi(tank[0].get_weapon_kind()+1)==true)
					{
						tank[0].set_weapon_kind(tank[0].get_weapon_kind()+1);
					}
					else if (tank[0].get_weapon_kind()==1 && tank[0].get_flag_weaponi(3)==true)
					{
						tank[0].set_weapon_kind(3);
					}
					else if (tank[0].get_weapon_kind()==2 && tank[0].get_flag_weaponi(3)==false)
					{
						tank[0].set_weapon_kind(1);
					}
			}break;

			case SDLK_q:
			{
                if(tank[1].get_flag_exist()==true)
				if (numbers_of_player_in_game>=2)
				{
					switch(tank[1].get_weapon_kind())
					{
						case 1:
						{
							if(tank[1].get_bulletNum()>0)
                            {
                                shoot(tank,bullet,1);
                                tank[1].set_bulletNum(tank[1].get_bulletNum()-1);
                            }
						} break;
						case 2:
						{
							if (tank[1].get_flag_weaponi(2)==true)
								{
									shoot2(tank,numbers_of_player_in_game,1);
									tank[1].set_flag_weaponi(2,false);
								}
						} break;
						case 3:
						{
                            if(tank[1].get_flag_weaponi(3)==true)
                            {
                                tank[1].set_flag_weaponi(3,false);
                            }
                            tank[1].set_flag_laser(true);
						} break;
					}
				}
			} break;

			case SDLK_e:
			{
				if(tank[1].get_flag_exist()==true)
					if (tank[1].get_weapon_kind()==3)
					{
						tank[1].set_weapon_kind(1);
					}
					else if(tank[1].get_flag_weaponi(tank[1].get_weapon_kind()+1)==true)
					{
						tank[1].set_weapon_kind(tank[1].get_weapon_kind()+1);
					}
					else if (tank[1].get_weapon_kind()==1 && tank[1].get_flag_weaponi(3)==true)
					{
						tank[1].set_weapon_kind(3);
					}
					else if (tank[1].get_weapon_kind()==2 && tank[1].get_flag_weaponi(3)==false)
					{
						tank[1].set_weapon_kind(1);
					}
			}break;
		}
	}
}

int dictance(int x1 ,int y1 ,int x2,int y2)
{
	return(sqrt(pow(x1-x2,2)+pow(y1-y2,2)));
}


void handle_move_event(Tank *tank,Bullet *bullet,int numbers_of_player_in_game)
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
            		tank[1].set_omega(1); break;
            	}
            	case SDLK_d:
            	{
                	tank[1].set_omega(-1); break;
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
            		tank[1].set_flag_DOWN(false); break;
            	}
            //for determining angle
            	case SDLK_a:
            	{
            		tank[1].set_omega(0); break;
            	}
            	case SDLK_d:
            	{
            		tank[1].set_omega(0); break;
            	}
       		}
		}
	}

    if(numbers_of_player_in_game>=3)
    {
        if(event.type == SDL_JOYAXISMOTION)
        {
            //If joystick 0 has moved
            if( event.jaxis.which == 0 )
            {
                //If the Y axis changed
                if( event.jaxis.axis == 1 )
                {
                    //If the Y axis is neutral
                    if( ( event.jaxis.value > -8000 ) && ( event.jaxis.value < 8000 ) )
                    {
                        tank[2].set_flag_UP(false);
                        tank[2].set_flag_DOWN(false);
                    }
                    //If not
                    else
                    {
                        //Adjust the velocity
                        if( event.jaxis.value < 0 )
                        {
                            tank[2].set_flag_UP(true);
                        }
                        else
                        {
                            tank[2].set_flag_DOWN(true);
                        }
                    }
                }
            }
        }

        if(event.type==SDL_JOYBUTTONDOWN)
        {
            if(event.jbutton.which==0)
            switch(event.jbutton.button)
            {
                case 4:
                    tank[2].set_omega(1); break;

                case 5:
                    tank[2].set_omega(-1); break;

                case 3:
                    {
                        switch(tank[2].get_weapon_kind())
                        {
                            case 1:
                            {
                                if(tank[2].get_bulletNum()>0)
                                {
                                    shoot(tank,bullet,2);
                                    tank[2].set_bulletNum(tank[2].get_bulletNum()-1);
                                }
                            } break;
                            case 2:
                            {
                                if (tank[2].get_flag_weaponi(2)==true)
                                {
                                    tank[2].set_flag_weaponi(2,false);
                                    shoot2(tank,numbers_of_player_in_game,0);
                                }
                            } break;
                            case 3:
                            {
                                if (tank[2].get_flag_weaponi(3)==true)
                                {
                                    tank[2].set_flag_weaponi(3,false);
                                    tank[2].set_flag_laser(true);
                                }
                            } break;
                        }
                    }

                case 1:
                {
                    if(tank[2].get_flag_exist()==true)
					if (tank[2].get_weapon_kind()==3)
					{
						tank[2].set_weapon_kind(1);
					}
					else if(tank[2].get_flag_weaponi(tank[2].get_weapon_kind()+1)==true)
					{
						tank[2].set_weapon_kind(tank[2].get_weapon_kind()+1);
					}
					else if (tank[2].get_weapon_kind()==1 && tank[2].get_flag_weaponi(3)==true)
					{
						tank[2].set_weapon_kind(3);
					}
					else if (tank[2].get_weapon_kind()==2 && tank[2].get_flag_weaponi(3)==false)
					{
						tank[2].set_weapon_kind(1);
					}
                }break;
            }
        }

        if(event.type==SDL_JOYBUTTONUP)
        {
            if(event.jbutton.which==0)
            switch(event.jbutton.button)
            {
                case 4:
                    tank[2].set_omega(0); break;

                case 5:
                    tank[2].set_omega(0); break;
            }
        }
    }


    if(numbers_of_player_in_game>=4)
    {
        if(event.type == SDL_JOYAXISMOTION)
        {
            if(event.jaxis.which==1)
            {
                //If the Y axis changed
                if(event.jaxis.axis==1)
                {
                    //If the Y axis is neutral
                    if( (event.jaxis.value>-8000) && (event.jaxis.value<8000) )
                    {
                        tank[3].set_flag_UP(false);
                        tank[3].set_flag_DOWN(false);
                    }
                    //If not
                    else
                    {
                        //Adjust the velocity
                        if( event.jaxis.value < 0 )
                        {
                            tank[3].set_flag_UP(true);
                        }
                        else
                        {
                            tank[3].set_flag_DOWN(true);
                        }
                    }
                }
            }
        }


        if(event.type==SDL_JOYBUTTONDOWN)
        {
            if(event.jbutton.which==1)
            switch(event.jbutton.button)
            {
                case 4:
                    tank[3].set_omega(1); break;

                case 5:
                    tank[3].set_omega(-1); break;

                case 3:
                    {
                        switch(tank[3].get_weapon_kind())
                        {
                            case 1:
                            {
                                if(tank[3].get_bulletNum()>0)
                                {
                                    shoot(tank,bullet,3);
                                    tank[3].set_bulletNum(tank[3].get_bulletNum()-1);
                                }
                            } break;
                            case 2:
                            {
                                if (tank[3].get_flag_weaponi(2)==true)
                                {
                                    tank[3].set_flag_weaponi(2,false);
                                    shoot2(tank,numbers_of_player_in_game,0);
                                }
                            } break;
                            case 3:
                            {
                                if (tank[3].get_flag_weaponi(3)==true)
                                {
                                    tank[3].set_flag_weaponi(3,false);
                                    tank[3].set_flag_laser(true);
                                }
                            } break;
                        }
                    }
                case 1:
                {
                    if(tank[3].get_flag_exist()==true)
					if (tank[3].get_weapon_kind()==3)
					{
						tank[3].set_weapon_kind(1);
					}
					else if(tank[3].get_flag_weaponi(tank[3].get_weapon_kind()+1)==true)
					{
						tank[3].set_weapon_kind(tank[3].get_weapon_kind()+1);
					}
					else if (tank[3].get_weapon_kind()==1 && tank[3].get_flag_weaponi(3)==true)
					{
						tank[3].set_weapon_kind(3);
					}
					else if (tank[3].get_weapon_kind()==2 && tank[3].get_flag_weaponi(3)==false)
					{
						tank[3].set_weapon_kind(1);
					}
                }break;
            }
        }

        if(event.type==SDL_JOYBUTTONUP)
        {
            if(event.jbutton.which==1)
            switch(event.jbutton.button)
            {
                case 4:
                    tank[3].set_omega(0); break;

                case 5:
                    tank[3].set_omega(0); break;
            }
        }
    }
}

void apply_surface(int x,int y,SDL_Surface* source,SDL_Surface* destination)
{
    SDL_Rect offset;
    offset.x=x;
    offset.y=y;

    SDL_BlitSurface(source,NULL,destination,&offset);
}

char* NumToStr(int num)  // for rectangle lives
{
    stringstream strs;
    strs<<num;
    string temp_str=strs.str();
    char* finall = new char(temp_str.length()+1);
    for(int i=0;i<temp_str.length();i++)
    {
        finall[i]=temp_str[i];
    }
    finall[temp_str.length()]='\0';
    return finall;
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

	Mix_PauseMusic();

	return ;
}
