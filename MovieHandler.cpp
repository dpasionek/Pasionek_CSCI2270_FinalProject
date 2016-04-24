#include <fstream>
#include <vector>
#include "MovieHandler.h"

MovieHandler::MovieHandler() 
{
	srand(0);  
	cache = new Cache;
	readList();
}

void MovieHandler::readList()
{	
	std::ifstream file(FILE_NAME);
	
	if(!file.is_open())
	{
		std::cout << "--- Movie List ----" << std::endl;
		std::cout << "ERROR: There was an issue opening the movies file" << std::endl;
		std::cout << "Please make sure the \"" << FILE_NAME <<  "\" exists!" << std::endl;
		return;
	}

	std::string line = "null";
	while(getline(file, line)) 
	{
		 movieQueue->enqueue(line, false); 
	}
}

void MovieHandler::writeList()
{
	std::ofstream file(FILE_NAME);
	if(!file.is_open())
	{
		std::cout << "--- Movie List ---" << std::endl;
		std::cout << "ERROR: There was an issue opening the movies file" << std::endl;
		std::cout << "Please make sure the \"" << FILE_NAME << "\" exists!" << std::endl;
		return;
	}
	
	std::string movie;
	while(!movieQueue->queueIsEmpty())
	{
		movie = movieQueue->dequeue(false);
		file << movie << std::endl;
	}
}

void MovieHandler::addMovie(std::string movie)
{
	if(!movieQueue->queueIsFull())
		movieQueue->enqueue(movie, true);
}

std::string MovieHandler::getURL(std::string name)
{
	std::vector<std::string> msgs = 
	{
		"Here you might find this link informative: ", 
		"I got a Rotten Tomatoes link for you: ",
		"Here's some more information about your movie: ",
		"You might find some more information here: "
	};
	
	int r = rand() % 4;
	
	for(unsigned int i = 0; i < name.size(); i++)
		if(name[i] == ' ')
			name[i] = '_';
	std::string URL = URL_BUFFER + name;
	std::string toReturn = msgs[r] + URL;

	return toReturn;;
}

void MovieHandler::updateCache(std::string _currentMovie, std::string _URL, int _index)
{
	cache->currentMovie = _currentMovie;
	cache->URL = _URL;
	cache->index = _index;
}

std::string MovieHandler::getCacheAttribute(Attribute attribute)
{
	switch(attribute)
	{
		case MOVIE:
			return cache->currentMovie;		
			break;
		case URL:
			return cache->URL;
			break;
		case INDEX:
			return std::to_string(cache->index);
			break;
	}
	return "null";	
}

MovieHandler::~MovieHandler() { writeList(); };
