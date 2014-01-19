
#ifndef TIME_EVENT_H
#define TIME_EVENT_H

class Event
{
public:
	Event(int counter, int retryCounter, void (*callback)(), int (*condition)()):Counter(counter),RetryCounter(retryCounter),Callback(callback),Condition(condition) {}
	~Event() {}
	int getEvent();
	int getRetryCounter();
	void task();
	int condition();

private:
	int Counter; // event id
	int RetryCounter;
	void (*Callback)();
	int (*Condition)(); // 0-pass -1-wait
};

#endif
