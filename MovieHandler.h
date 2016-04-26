#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
struct Cache
{
	std::string currentMovie;
	std::string URL;
	int index;
};

struct Node
{
	std::string movie;
	std::string URL;
	Node * next;
	Node * previous;
	Node(std::string _movie, std::string _url, Node * _next, Node * _prev)
	{
		movie = _movie;
		URL = _url;
		next = _next;
		previous = _prev;
	}Node(){};
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
	void removeMovie(std::string title);
	void pop();
	void print();
	std::string getURL(std::string name);
	std::string getCacheAttribute(Attribute attribute);
	
	
private:
	const std::string FILE_NAME = "movies.data";
	const std::string URL_BUFFER = "http://www.rottentomatoes.com/m/";
	Cache * cache;
	Node * head;
};
