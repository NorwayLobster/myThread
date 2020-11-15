 ///
 /// @file    MutexLock.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 02:06:41
 ///
 
#include <iostream>

#include "MutexLock.hpp"
using std::cout;
using std::endl;

namespace wc{
MutexLock::MutexLock()
:_isLocking(false)
{
	cout<<"MutexLock()"<<endl;
	pthread_mutex_init(&_mutex,NULL);
}

MutexLock::~MutexLock(){
	cout<<"~MutexLock()"<<endl;
	pthread_mutex_destroy(&_mutex);
}
void MutexLock::lock(){
	pthread_mutex_lock(&_mutex);
	_isLocking=true;
}
void MutexLock::unlock(){
	pthread_mutex_unlock(&_mutex);
	_isLocking=false;
}
pthread_mutex_t * MutexLock::GetMutexPtr(){
	return &_mutex;
}
}
