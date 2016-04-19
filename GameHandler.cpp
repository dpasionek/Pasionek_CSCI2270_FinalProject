#include "GameHandler.h"

GameHandler::GameHandler(Config * c)
{

}

void GameHandler::init()
{

}

void GameHandler::buildMap()
{
	Room * boss = new Room("Boss Chamber");
	Room * entrance = new Room("Entrance");
	Room * kitchen = new Room("Kitchen");
	Room * bedroom = new Room("Bedroom");
	Room * guestRoom = new Room("Guest Room");
	Room * living = new Room("Living Room");
	Room * dining = new Room("Dining Room");
	Room * bathroom = new Room("Bathroom");
	Room * romp = new Room("Romp Room");
	Room * pantry = new Room("Pantry");
	Room * outside = new Room("Outside");
	
	
}


bool GameHandler::checkPos(Position pos, Direction dir)
{
	bool valid = false;
	switch(dir)
	{
		case NORTH:
			break;
		case SOUTH:
			break;
		case EAST:
			break;
		case WEST:
			break;
		default:
			return false;

	}		
	
	return valid;
}

bool GameHandler::hasConnection(Room * currentRoom, Direction dir)
{
	bool toReturn = false;
	switch(dir)
	{
		case NORTH:
			toReturn = (currentRoom->rooms[0] != nullptr) ? true : false;
			break;
		case SOUTH:
			toReturn = (currentRoom->rooms[1] != nullptr) ? true : false;
			break;
		case EAST:
			toReturn = (currentRoom->rooms[2] != nullptr) ? true : false;
			break;
		case WEST:
			toReturn = (currentRoom->rooms[3] != nullptr) ? true : false;
			break;
		default:
			toReturn = false;
	}
	
	return toReturn;
}

GameHandler::~GameHandler()
{

}
