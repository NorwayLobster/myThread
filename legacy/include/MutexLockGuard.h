 ///
 /// @file    MutexLockGuard.h
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 10:33:54
 ///
#ifndef _MutexLockGuard_H_
#define _MutexLockGuard_H_
#include <iostream>
#include "Noncopyable.h"
using std::cout;
using std::endl;
namespace wc{
class MutexLock;
class MutexLockGuard:public Noncopyable{
public:
	MutexLockGuard(MutexLock&);
	~MutexLockGuard();
private:
	MutexLock & _ml;
};
}
#endif
