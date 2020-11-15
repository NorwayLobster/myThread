 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 02:13:20
 ///
 
#include <iostream>
#include <functional>
#include <unistd.h>
#include "myThread/mutexLock.hpp"
#include "myThread/mutexLockGuard.h"
#include "myThread/condition.hpp"
#include "myThread/thread.hpp"
using std::cout;
using std::endl;
//Task: thread1 thread2 加10000
wc::MutexLock gMutexLock;
wc::Condition gCondition(gMutexLock);
int gCnt=10;
bool gFlag=false;
void PrintNum(void * arg){
	int cnt=*(int*)arg;
	while(cnt--){
		gMutexLock.lock();
		cout<<"ThreadId:"<<pthread_self()<<",gCnt:"<<gCnt--<<endl;
		gMutexLock.unlock();
	}
}
//when gFlag is true, add 1
void PrintNum1(void * arg){
	int cnt=*(int*)arg;
	while(cnt--){
		wc::MutexLockGuard mlg(gMutexLock);
//		gMutexLock.lock();
		if(!gFlag)
			gCondition.wait();
		cout<<"ThreadId:"<<pthread_self()<<",gCnt:"<<gCnt--<<endl;
		if(gFlag){//
			gFlag=false;	
			gCondition.notify();
		}
//		gMutexLock.unlock();
		sleep(1);
	}
}

//when gFlag is false, add 1
void PrintNum2(void * arg){
	int cnt=*(int*)arg;
	while(cnt--){
		wc::MutexLockGuard mlg(gMutexLock);
//		gMutexLock.lock();
		if(gFlag)
			gCondition.wait();
		cout<<"ThreadId:"<<pthread_self()<<",gCnt:"<<gCnt--<<endl;
		if(!gFlag){//
			gFlag=true;	
			gCondition.notify();
		}
//		gMutexLock.unlock();
		sleep(2);
	}
}
int main(){
//	wc::MutexLock * pml=new wc::MutexLock;
//	MutexLock ml;
//	ml.lock();
//	ml.unlock();
	int cnt=10;
//	wc::Thread th1(std::bind(PrintNum,&cnt));
//	wc::Thread th2(std::bind(PrintNum,&cnt));
	wc::Thread th1(std::bind(PrintNum1,&cnt));
	wc::Thread th2(std::bind(PrintNum2,&cnt));
	th2.start();
	th1.start();

	th2.join();
	th1.join();
//	pml->lock();
//	cout<<pml->GetMutexPtr()<<endl;
//	wc::Condition cond(*pml);
//	Condition cond(*(pml->GetMutextPtr()));

//	pml->unlock();
//	delete pml;
	return 0;
}
