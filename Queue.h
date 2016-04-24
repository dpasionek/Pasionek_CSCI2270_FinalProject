#pragma once
#include <iostream>
#include <string>

class Queue
{
public:
	Queue(int);
	~Queue();
	void enqueue(std::string, bool msgs);
	void list();
	std::string dequeue(bool msgs);
	std::string find(std::string name);
	bool queueIsFull();
	bool queueIsEmpty();
private:
	int queueSize;
	int queueHead;
	int queueTail;
	int queueCount;
	std::string * arrayQueue;
	
};
