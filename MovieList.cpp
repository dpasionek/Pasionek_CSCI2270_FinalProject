#include <iostream>
#include "MovieHandler.h"

using namespace std;

void printMenu();
void info();
void help();
int main()
{

	info();
	return 0;
}

void printMenu()
{
	cout << "--- Movie List ---" << endl;
	
	
}

void info()
{
	cout << "--- Movie List Info ---" << endl;
	cout << "Welcome to Movie List! This is a useful tool to help" << endl;
	cout << "organize a small list of movie for you /and/ your" << endl;
	cout << "significant other can watch! This program will provide you" << endl;
	cout << "with a list of 10 movies to have you watch in order!" << endl;
	cout << endl;
}

void help()
{
	cout << "--- Movie List Commands ---" << endl;
	cout << "Find <move title> - finds a movie and gives you information about it!" << endl;
	cout << "Print - Will print your current list of movies" << endl;
	cout << "Help - Displays this help menu" << endl;
	cout << "Info - Prints the information about this program" << endl;
	cout << "Quit - Quits the program, don't worry your list will be saved" << endl;
}
