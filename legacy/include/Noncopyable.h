 ///
 /// @file    Noncopyable.h
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 03:03:25
 ///
#ifndef _Noncopyable_H_ 
#define _Noncopyable_H_ 
#include <iostream>
using std::cout;
using std::endl;
class Noncopyable{
public:
	Noncopyable(){cout<<"Noncopyable()"<<endl;};
	//c++11
	Noncopyable(const Noncopyable&)=delete;
//	Noncopyable & operator=(const Noncopyable&)=delete;
private://C++98
	Noncopyable & operator=(const Noncopyable&);
//	Noncopyable(const Noncopyable&);
};
#endif
