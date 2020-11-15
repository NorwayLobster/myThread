 ///
 /// @file    TestThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-02 10:28:43
 ///
 
#include "Thread.h"
#include "TaskQueue.h"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>


using namespace wd;
using std::cout;
using std::endl;

struct Producer{
	void produceNumber(TaskQueue & tq){
		::srand(::time(NULL));
		int cnt = 30;
		while(cnt--) {
			int number = ::rand() % 100;
			tq.push(number);
			cout << ">> Thread "<< pthread_self() << " get a number : " << number << endl;
			::sleep(0.1);
		}
	}
};

struct Consumer{
	void consumeNumber(TaskQueue & tq) {
		int cnt = 30;
		while(cnt--) {
			int number = tq.pop();
			cout << ">> Thread "<< pthread_self() << " consumer a number : " << number << endl;
			::sleep(0.2);
		}
	}
};

void produce(TaskQueue & tq){
	::srand(::time(NULL));
	int cnt = 30;
	while(cnt--) {
		int number = ::rand() % 100;
		tq.push(number);
		cout << ">> Thread "<< pthread_self() << " get a number : " << number << endl;
		::sleep(0.1);
	}
}

void consume(TaskQueue & tq) {
	int cnt = 30;
	while(cnt--) {
		int number = tq.pop();
		cout << ">> Thread "<< pthread_self() << " consumer a number : " << number << endl;
		::sleep(2);
	}
}
 
int main(void)
{
	cout << "MainThread: " << pthread_self() << endl;

	TaskQueue tq(10);
	//wd::Thread producer(std::bind(&Producer::produceNumber, Producer(), std::ref(tq)));
	//wd::Thread consumer(std::bind(&Consumer::consumeNumber, Consumer(), std::ref(tq)));
	wd::Thread producer(std::bind(produce, std::ref(tq)));
	wd::Thread consumer(std::bind(consume, std::ref(tq)));
	producer.start();
	consumer.start();

	producer.join();
	consumer.join();
	return 0;
}
