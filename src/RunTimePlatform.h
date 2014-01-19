


#ifndef RUN_TIME_PLATFORM_H
#define RUN_TIME_PLATFORM_H

#include <Poco/Timer.h>
#include "Event.h"
#include <vector>

using Poco::Timer;
using Poco::TimerCallback;
using std::vector;

class RunTimePlatform
{
public:
	// period in ms
	RunTimePlatform(int period):timerThread(200, period), checkPoint(0), retryCounter(0), breakTaskID(0){}
	~RunTimePlatform() {}

	int registerEvent(Event &e);
	int start();
	void run(Timer &timer);

private:
	int checkPoint;
	int retryCounter;
	Timer timerThread;
	vector<Event> tasks;
	int breakTaskID;
};




#endif