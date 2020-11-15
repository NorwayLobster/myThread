 ///
 /// @file    Condition.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 02:16:17
 ///
#ifndef _Condition_HPP_ 
#define _Condition_HPP_ 
#include <iostream>
#include <pthread.h>
#include "Noncopyable.h"
using std::cout;
using std::endl;
namespace wc{
class MutexLock;//减少头文件的依赖，防止头文件的循环调用

class Condition:public Noncopyable/*系统资源，e.g. IO流，互斥锁，条件变量，对象语义，禁止复制*/{
public:
	Condition(MutexLock&);
	~Condition();
	void wait();
	void notify();
	void notifyall();
private:
	pthread_cond_t _cond;
	MutexLock &_mutex;
};
}
#endif

