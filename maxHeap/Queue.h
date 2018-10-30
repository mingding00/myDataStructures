#pragma once
#include<iostream>
template<typename T>
class queue {
public:
	virtual ~queue() {};
	virtual int getSize()const = 0;
	virtual bool empty()const = 0;
	virtual void enqueue(T element) = 0;
	virtual T dequeue() = 0;
	virtual T getFront() = 0;
};