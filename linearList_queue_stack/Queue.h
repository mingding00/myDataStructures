#pragma once
#include<iostream>
using namespace std;
template<typename T>
class queue
{
public:
	virtual ~queue() {};
	virtual bool empty()const = 0;
	virtual int getSize()const = 0;
	virtual T& getFront()const = 0;
	virtual void enqueue(const T& theElement) = 0;
	virtual T dequeue() = 0;
	virtual void output(ostream& out)const=0;
};