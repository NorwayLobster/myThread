 ///
 /// @file    MutexLock.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 02:05:31
 ///
#ifndef _Mutext_HPP_ 
#define _Mutext_HPP_ 
#include <iostream>
#include <pthread.h>
#include "Noncopyable.h"
using std::cout;
using std::endl;
namespace wc{
class MutexLock:public Noncopyable{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();
	pthread_mutex_t * GetMutexPtr();
private:
	bool _isLocking;
	pthread_mutex_t _mutex;
};
}
#endif

