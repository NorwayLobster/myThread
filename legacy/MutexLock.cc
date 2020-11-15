///
/// @file    MutexLock.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-03-30 21:56:32
///

#include <iostream>
using std::cout;
using std::endl;
class MutexLock
{
	public:
		...
			void lock();
		void unlock();
	private:
		//...
};

class Condition
{
public:
		//...
		void wait();
		void notify();
		void notifyall();
	private:
		//...
};
