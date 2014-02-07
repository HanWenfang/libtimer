#include "RunTimePlatform.h"
#include <iostream>

using namespace std;

int RunTimePlatform::start()
{
	timerThread.start(TimerCallback<RunTimePlatform>(*this, &RunTimePlatform::run));


	return 0;
}

void RunTimePlatform::run(Timer &timer)
{
	for(vector<Event>::iterator it=tasks.begin()+breakTaskID; it != tasks.end(); ++it, ++breakTaskID)
	{
		if(checkPoint % it->getEvent() == 0){
			cout << "checkPoint: " << checkPoint << endl;		
			if(retryCounter > it->getRetryCounter()){
				retryCounter = 0;
				continue;
			}

			if(it->condition() < 0){
				++retryCounter;
				return;
			}else{
				it->task();
			}
		}
	}

	breakTaskID = 0;
	++checkPoint;
	return;
}

int RunTimePlatform::registerEvent(Event &e)
{
	tasks.push_back(e);

	return 0;
}





