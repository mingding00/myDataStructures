#pragma once
#include<iostream>
template<typename T>
class Set
{
	virtual ~Set() {};
	virtual void add(T e) = 0;
	virtual void remove(T e) = 0;
	virtual bool contains(T e) = 0;
	virtual int getSize() = 0;
	virtual bool empty() = 0;
};