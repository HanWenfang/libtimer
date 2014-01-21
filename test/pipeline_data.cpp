// ring-pipeling

#include <iostream>
#include "RunTimePlatform.h"
#include <signal.h>
#include <string>

using namespace std;

static string data1;
static string data2;
static string data3;

void P1(){
	data1 = "Hello!";
	cout << "data1: " << data1 << endl;
	data1 = "";
}

void P2(){
	data2 = data1 + "World!" ;
	cout << "data2: " << data2 << endl;
	data2 = "";
}

void P3(){
	data3 = data2 +  "Yahoo!";
	cout << "data3: " << data3 << endl;
	data3 = "";
}

int condition(){
	return 0;
}

int main(int argc, char *argv[])
{

	sigset_t newmask;
	sigset_t oldmask;

	//no return value check
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	sigaddset(&newmask, SIGINT);
	sigaddset(&newmask, SIGTERM);
	sigprocmask(SIG_BLOCK, &newmask, &oldmask);

	Event e1(2, 4, P1, condition);
	Event e2(3, 4, P2, condition);
	Event e3(4, 4, P3, condition);

	// Three Pipelines
	RunTimePlatform runp1(2000);
	runp1.registerEvent(e1);

	RunTimePlatform runp2(2000);
	runp2.registerEvent(e2);

	RunTimePlatform runp3(2000);
	runp3.registerEvent(e3);

	runp1.start();
	runp2.start();
	runp3.start();


	int sig;
	sigwait(&newmask, &sig);

	return 0;
}

