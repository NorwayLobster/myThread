 ///
 /// @file    MutexLockGuard.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 10:35:52
 ///
 
#include <iostream>
#include "MutexLockGuard.h"
#include "MutexLock.hpp"
using std::cout;
using std::endl;

namespace wc{
class MutexLock;
MutexLockGuard::MutexLockGuard(MutexLock& ml)
:_ml(ml)
{
	cout<<"MutexLockGuard(MutexLock&)"<<endl;
	_ml.lock();
}
MutexLockGuard::~MutexLockGuard(){
	cout<<"~MutexLockGuard()"<<endl;
	_ml.unlock();
}

	
}

