 ///
 /// @file    Thread.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 03:21:22
 ///
 
#include <iostream>
#include "Thread.h"
using std::cout;
using std::endl;

namespace wc{
Thread::Thread(ThreadCallback cb)
:_cb(cb)
,_isStarting(false)
{
	cout<<"Thread()"<<endl;
}
Thread::~Thread(){
	pthread_detach(_ThreadId);
	cout<<"~Thread()"<<endl;
}
//void Thread::start(void *arg){
void Thread::start(){
	pthread_create(&_ThreadId,NULL,ThreadFunc,this);
	_isStarting=true;
}
void Thread::join(){
	void ** retval=NULL;
	pthread_join(_ThreadId,retval);
	_isStarting=false;
}
//void * _ThreadFunc(/*Thread * this*,*/void* arg){
void * Thread::ThreadFunc(void*arg){	
	Thread * p=static_cast<Thread*>(arg);
	if(NULL!=p)
		p->_cb();
	return NULL;
}
}

