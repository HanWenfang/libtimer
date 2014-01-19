#include <iostream>
#include "RunTimePlatform.h"
#include <signal.h>

using namespace std;

void printH(){
	cout << "Hello " << endl;
}

void printW(){
	cout << "World!" << endl;
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


	RunTimePlatform runp(20000);

	Event e1(3, 4, printH, condition);
	Event e2(3, 4, printW, condition);

	runp.registerEvent(e1);
	runp.registerEvent(e2);

	runp.start();


	int sig;
	sigwait(&newmask, &sig);

	return 0;
}

