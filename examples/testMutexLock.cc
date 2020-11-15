 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 02:13:20
 ///
 
#include <iostream>
#include "myThread/MutexLock.hpp"
using std::cout;
using std::endl;
int main(){
	MutexLock * pml=new MutexLock;
//	MutexLock ml;
//	ml.lock();
//	ml.unlock();

	pml->lock();
	cout<<pml->GetMutexPtr()<<endl;
	pml->unlock();
	delete pml;
	return 0;
}
