 ///
 /// @file    Thread.h
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 03:19:20
 ///
 
#ifndef _Thread_H_
#define _Thread_H_
#include <iostream>
#include <pthread.h>
#include <functional>
#include "Noncopyable.h"
using std::cout;
using std::endl;
namespace wc{

class Thread:public Noncopyable{
	typedef  std::function<void()> ThreadCallback;
	typedef void*(*Functor)(void*);
public:
	Thread(ThreadCallback);
	~Thread();
	void start();
//	void start(void * arg);
	void join();
	static void *ThreadFunc(void*);
private:
	pthread_t _ThreadId;
//	Functor _ThreadFunc;
	ThreadCallback _cb;
	bool _isStarting;
};

}
#endif
