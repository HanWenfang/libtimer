#include "Event.h"



int Event::getEvent()
{
	return Counter;
}

void Event::task()
{
	return Callback();
}

int Event::condition()
{
	return Condition();
}

int Event::getRetryCounter()
{
	return RetryCounter;
}





