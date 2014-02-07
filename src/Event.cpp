#include "Event.h"


// event id, un-unique
int Event::getEvent() 
{
	return Counter;
}

void Event::task()
{
	return Callback();
}

// condition by function
// -1 means false, 0 means true
int Event::condition()
{
	return Condition();
}

// real-time retry
int Event::getRetryCounter() 
{
	return RetryCounter;
}





