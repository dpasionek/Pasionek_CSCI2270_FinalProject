#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
/*
* Struct for the in-program cache
* Figured it would be useful in case a user
* wanted to look at 'past history'
*/
struct Cache
{
	std::string currentMovie;
	std::string URL;
	int index;
};

/*
* LinkedList structure, contains a movie and a URL
* Although the URL isn't always correct
* It's sort of hard to tell when a user is
* inputing a real movie or just a derp
*/
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

/* Attribute for the cache, makes calling the getAttribute function easier  */
enum Attribute { MOVIE, URL, INDEX };

class MovieHandler
{
public:
	// Constructor, just initializes some of the variables
	MovieHandler();
	
	// Just to be safe... I know I never use it but you can never be too safe.
	~MovieHandler();
	
	// Reads in the movie.data file
	void readList();

	// Writes the current list of movies to the file
	void writeList();

	// Adds a movie to the current list, at the end
	// Sort of acts like a queue
	void addMovie(std::string movie);

	// Updates the Cache, so that the "past history" thing I talked about
	// earlier works nicely.
	void updateCache(std::string _currentMovie, std::string _URL, int _index);
	
	// Removes a movie from the list, can be anywhere in the list
	void removeMovie(std::string title);
	
	//Removes a movie from the front of the list, make the list act like a queue	
	void pop();

	// Prints all of the movies in order of which to watch first (Again like a queue)
	void print();

	// Returns a rotten tomatoes link... I know it's not always right... I tried my best :(
	std::string getURL(std::string name, bool msg);

	// Returns a string of the attribute requested (Look at the enum Attribute to see what can be returned)
	// Returns as a string because some of the attributes are of a different data type but can be easily
	// converted from a string to and int, or int to string, or <some abritraty data type> to string and 
	// vice versa
	std::string getCacheAttribute(Attribute attribute);
	
private:
	// This will never change. Don't change it. 
	const std::string FILE_NAME = "movies.data";
	// This also will never change. And if you do change it, it's your own fault that
	// the link doesn't work. 
	const std::string URL_BUFFER = "http://www.rottentomatoes.com/m/";

	// Initial declaration of these variables
	Cache * cache;
	Node * head;
};
