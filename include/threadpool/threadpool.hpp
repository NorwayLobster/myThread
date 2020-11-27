 ///
 /// @file    threadpool.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-11-15 16:26:38
 ///
 
#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include "threadpool/taskQueue.hpp"
#include "threadpool/thread.hpp"

using std::vector;
using std::shared_ptr;
using std::make_shared;
class Thread;
class threadPool{
	using Task=std::function<void()>;
	public:	
	threadPool(size_t,size_t);
	~threadPool();
	void start();
	void stop();
	void addTask(Task task);
	private:
	Task getTask();
	void __threadStartPointFunc();
	private:
	size_t __threadNum;
	taskQueue<Task> __taskqueue;	
	vector<shared_ptr<Thread>> __threadVec;	
	bool __exitFlag;
};
