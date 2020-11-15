 ///
 /// @file    TaskQueue.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-02 14:49:35
 ///
 

#ifndef __WD_TASKQUEUE_H__
#define __WD_TASKQUEUE_H__

#include "MutexLock.h"
#include "Condition.h"

#include <queue>


namespace wd
{

typedef int Task;

class TaskQueue
{
public:
	TaskQueue(size_t queSize)
	: _queSize(queSize)
	, _mutex()
	, _notFull(_mutex)
	, _notEmpty(_mutex)
	{}
	
	void push(const Task & t);
	Task pop();

	bool empty() const
	{	return _que.size() == 0;	}

	bool full()const
	{	return _que.size() == _queSize;	}

private:
	size_t _queSize;
	std::queue<Task> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};


}//end of namespace wd

#endif
