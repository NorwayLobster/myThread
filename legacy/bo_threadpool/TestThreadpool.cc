 ///
 /// @file    TestThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-02 10:28:43
 ///
 
#include "Threadpool.h"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace wd;


class MyTask
{
public:
	void process()
	{
		::srand(::time(NULL));
		//::srand(::clock());
		int number = ::rand() % 100;
		::sleep(2);
		//::usleep(100);
		cout << ">>> subThread: "<< pthread_self() << ". produce a number : " << number << endl;
	}
};

 
int main(void)
{
	cout << "MainThread: " << pthread_self() << endl;

	MyTask mytask;

	Threadpool threadpool(4, 10);
	threadpool.start();

	int cnt = 20;
	while(cnt--) {
		threadpool.addTask(std::bind(&MyTask::process, mytask));
		cout << "MainThread: "<< cnt << endl;
	}
	threadpool.stop();

	return 0;
}
