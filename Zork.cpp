#include <iostream>
#include "GameHandler.h"
#include "Config.h"
using namespace std;

int main(int argc, char * argv[])
{
	cout << "Hello World?" << endl;
	Config c;
	GameHandler h(c);
	c.init("config/config.txt");
	return 0;
}


