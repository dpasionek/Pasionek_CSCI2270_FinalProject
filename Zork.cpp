#include <iostream>
#include "GameHandler.h"
#include "Config.h"
using namespace std;

int main(int argc, char * argv[])
{
	Config c;
	GameHandler h(&c);
	c.init("config/config.txt");
	h.init();
	return 0;
}


