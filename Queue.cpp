#include "Queue.h"

Queue::Queue(int size)
{
	queueSize = size;
	arrayQueue = new std::string[queueSize];
	queueHead = 0;
	queueTail = 0;
	queueCount = 0;
}

void Queue::enqueue(std::string toQueue, bool msgs)
{
	if(queueIsFull())
	{
		std::cout << "You already need to watch " << queueSize << " movies!" << std::endl;
		return;
	}
	
	arrayQueue[queueCount] = toQueue;
	queueTail = (queueTail + 1) % queueSize;
	if(msgs) {
		std::cout << "--- Movie List ---" << std::endl;
		std::cout << "You added the movie: " << toQueue << " to your watch list!" << std::endl;
		std::cout << "This movie is currently number " << queueCount + 1 << " on your list" << std::endl;
	}
	queueCount++;
}

std::string Queue::dequeue(bool msgs)
{
	if(queueIsEmpty())
	{
		std::cout << "You currently don't have any movies to watch!" << std::endl;
		return "";
	}	
	
	std::string movie = arrayQueue[queueHead];
	arrayQueue[queueHead] = "null";
	queueHead = (queueHead + 1) % queueSize;
	if(msgs) {
		std::cout << "--- Movie List ---" << std::endl;
		std::cout << "You've watched the movie \"" << movie << "\"!" << std::cout;
		std::cout << "The next movie on your list is: " << arrayQueue[queueHead] << std::endl; 
		std::cout << "You have " << queueCount - 1 << " movies left in your list!" << std::endl;
	}
	queueCount--;

	return movie;
}

void Queue::list()
{
	if(queueIsEmpty())
	{
		std::cout << "You don't have any movies to watch!" << std::endl;
		return;
	}
	std::cout << "--- Movie List ---" << std::endl;
	for(int i = queueHead; i < queueCount; i++)
		std::cout << i + 1 << ".) " << arrayQueue[i] << std::endl;
}

std::string Queue::find(std::string name)
{
	if(queueIsEmpty())
	{
		std::cout << "You don't have any movies to watch!" << std::endl;
		return "";
	}
	
	for(int i = queueHead; i < queueCount ; i++)
		if(arrayQueue[i] == name)
			return arrayQueue[i];
	return "null";
}

bool Queue::queueIsFull()
{
	return (queueCount == queueSize);
}

bool Queue::queueIsEmpty()
{
	return (queueCount == 0);	
}
