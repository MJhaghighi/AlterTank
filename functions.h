// this is functions fils
#include "sstream"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*const char* getTankString(int i)
{
	stringstream tankString;
	tankString.str("");
	tankString<<"tank"<<(char)(i+'1')<<".jpg";
	cout << tankString.str()<<"\n";
	return(tankString.str().c_str());
}

const char* getMapString(int i)
{
	stringstream mapString;
	mapString<<"map"<<(char)(i+'1')<<".png";
	cout << mapString.str()<<"\n";
	return(mapString.str().c_str());
} */

int randomMap(int MaxNumOFmap)
{
    int p=rand()%MaxNumOFmap;
    if(p==mapNum) randomMap(MaxNumOFmap);
    else return p;
}

