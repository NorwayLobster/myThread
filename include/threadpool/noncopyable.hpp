 ///
 /// @file    Noncopyable.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-03-10 21:17:22
 ///
#ifndef __Noncopyable_H__
#define __Noncopyable_H__
class Noncopyable{
public:
	Noncopyable()=default;

	Noncopyable(const Noncopyable &)=delete;
	Noncopyable & operator=(const Noncopyable & )=delete;

	~Noncopyable()=default;
};
#endif 
