 ///
 /// @file    Condition.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 02:17:42
 ///
 
#include <iostream>
#include "Condition.hpp"
#include "MutexLock.hpp"
using std::cout;
using std::endl;
namespace wc{
Condition::Condition(MutexLock & mutex)
:_mutex(mutex)
{
	cout<<"Condition()"<<endl;
	pthread_cond_init(&_cond,NULL);
}

Condition::~Condition(){
	cout<<"~Condition()"<<endl;
	pthread_cond_destroy(&_cond);
}

void Condition::wait(){
	pthread_cond_wait(&_cond,_mutex.GetMutexPtr());
}
void Condition::notify(){
	pthread_cond_signal(&_cond);
}
void Condition::notifyall(){
	pthread_cond_broadcast(&_cond);
}
}
