 ///
 /// @file    threadpool.cpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-11-15 16:25:34
 ///
 
#include <iostream>
#include "myThread/threadpool.hpp"
using std::cout;
using std::endl;

using Task=std::function<void()>;
threadPool::threadPool(size_t n1, size_t n2)
:__threadNum(n1)
,__taskqueue(n2)
,__exitFlag(false)
{cout<<"threadPool() ctor"<<endl;}

threadPool::~threadPool(){
  cout<<"~threadPool() dtor"<<endl;
  //Todo
  }

Task threadPool::getTask(){
  cout<<"getTask()"<<endl;
  Task task=__taskqueue.pop();
  return task;
  }
void threadPool::start(){
  cout<<"start()"<<endl;
  for(int i=0;i<__threadNum;++i){
    // shared_ptr<Thread> sp = make_shared<Thread>(new Thread(std::bind(&threadPool::__threadStartPointFunc,this)));
    shared_ptr<Thread> sp = make_shared<Thread>(std::bind(&threadPool::__threadStartPointFunc,this));
    __threadVec.push_back(std::move(sp));
    sp->start();
  }
}
void threadPool::__threadStartPointFunc(){
  while(!__exitFlag){
    Task task=getTask();
    if(task)
      task();
  }
}
void threadPool::stop(){
  cout<<"stop()"<<endl;
  //Todo
}

void threadPool::addTask(Task task){
  cout<<"addTask()"<<endl;
  __taskqueue.push(task);
}


