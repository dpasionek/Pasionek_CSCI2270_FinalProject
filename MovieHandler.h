#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Queue.h"
struct Cache
{
	std::string currentMovie;
	std::string URL;
	int index;
};

enum Attribute { MOVIE, URL, INDEX };

class MovieHandler
{
public:
	MovieHandler();
	~MovieHandler();
	void readList();
	void writeList();
	void addMovie(std::string movie);
	void updateCache(std::string _currentMovie, std::string _URL, int _index);
	std::string getURL(std::string name);
	std::string getCacheAttribute(Attribute attribute);
	Queue * movieQueue = new Queue(10);
	
	
private:
	const std::string FILE_NAME = "movies.data";
	const std::string URL_BUFFER = "http://www.rottentomatoes.com/m/";
	Cache * cache;
};
