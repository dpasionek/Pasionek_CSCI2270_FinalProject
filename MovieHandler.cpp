#include "MovieHandler.h"

MovieHandler::MovieHandler() 
{
	srand(0);  
	cache = new Cache;
};

void MovieHandler::readList()
{	
	ifstream file(FILE_NAME);
	
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
		 movieQueue.enqueue(line); 
	}
}

void MovieHandler::writeList()
{
	ofstream file(FILE_NAME);
	if(!file.is_open())
	{
		std::cout << "--- Movie List ---" << std:::endl;
		std::cout << "ERROR: There was an issue opening the movies file" << std::endl;
		std::cout << "Please make sure the \"" << FILE_NAME << "\" exists!" << std::endl;
		return;
	}
	
	std::string movie;
	while(!movieQueue.isQueueEmpty())
	{
		movie = movieQueue.dequeue();
		file << movie << std::endl;
	}
}

std::string MovieHandler::getURL(std::string name)
{
	std::vector<string> messages = 
	{
		"Here you might find this link informative: ", 
		"I got a Rotten Tomatoes link for you: ",
		"Here's some more information about your movie: ",
		"You might find some more information here: "
	};
	
	int r = rand() % 4 + 1;
	
	std::string URL = URL_BUFFER + messages[r];

	return URL;
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
}

MovieHandler::~MovieHandler() {  };
