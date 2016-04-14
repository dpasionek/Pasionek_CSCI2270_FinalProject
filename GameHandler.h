#include <iostream>
#include "Config.h"
struct Item
{
	std::string name;
	std::string desc;
	int durability;
	int carryWeight;
}; 

struct Room
{
	std::string name;
	std::vector<Item> items;	
};

struct Position
{
	int x;
	int y;
	Room currentRoom;
};

class GameHandler
{

public:
	GameHandler(Config c);
	void init();
	~GameHandler();
};
