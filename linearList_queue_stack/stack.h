#pragma once
#include<iostream>
using namespace std;
template<typename T>
class stack
{
public:
	virtual ~stack() {};
	virtual bool empty()const = 0;
	virtual int getSize()const = 0;
	virtual T& top()const = 0;
	virtual T pop() = 0;
	virtual void push(const T& theElement) = 0;
	virtual void output(ostream& out)const = 0;
};