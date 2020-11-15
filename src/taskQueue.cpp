//
//  taskQueue<T>.cpp
//  bo_ProducerConsumer
//
//  Created by ChengWang on 3/10/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include "myThread/taskQueue.hpp"
#include "myThread/mutexLockGuard.hpp"
template<typename T>
taskQueue<T>::taskQueue(size_t queSize):
__queSize(queSize),
__mutex(),
__notFull(),
__notEmpty(),
_workingFlag(true)
{
    cout<<"taskQueue<T>()"<<endl;
}

template<typename T>
taskQueue<T>::~taskQueue()
{ cout<<"~taskQueue<T>()"<<endl;};

template<typename T>
bool taskQueue<T>::empty(){
    return __que.size()==0;
}

template<typename T>
bool taskQueue<T>::full(){
    return __que.size()==__queSize;
}

template<typename T>
void taskQueue<T>::push(T task){
    MutexLockGuard mlg(__mutex);
    while(full()){
        __notFull.wait(__mutex);
    }
    __que.push(task);
    __notEmpty.notify();
}

template<typename T>
T taskQueue<T>::pop(){
    MutexLockGuard mlg(__mutex);
    while(_workingFlag&&empty()){
        __notEmpty.wait(__mutex);
    }
	if(_workingFlag){
		T task = __que.front();
//   Task task = __que.front();
//    shared_ptr<Task> ptask = __que.front();
		__que.pop();
		__notFull.notify();
		return  task;
	}else{
		return T();
	}
}
template<typename T>
void taskQueue<T>::wakeUp()
{
	_workingFlag=false;
	__notEmpty.notify_all();//why __notEmpty? by cheng
}
