// One Timer One Thread

#include <iostream>
#include "RunTimePlatform.h"
#include <signal.h>

using namespace std;

void printH(){
	cout << "Hello!" << endl;
}

void printW(){
	cout << "World!" << endl;
}

void printY(){
	cout << "Yahoo!" << endl;
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


	RunTimePlatform runp(2000);

	// 3 and 6 : the meaning of multiple
	// 3 and 5 : the meaning of co-prime
	// 6 and 5 : the meaning of co-prime
	Event e1(3, 4, printH, condition);
	Event e2(5, 4, printW, condition);
	Event e3(6, 4, printY, condition);

	runp.registerEvent(e1);
	runp.registerEvent(e2);
	runp.registerEvent(e3);

	runp.start();


	int sig;
	sigwait(&newmask, &sig);

	return 0;
}

