#pragma once
#include<iostream>
using namespace std;
template<typename T>
class linearList
{
public:

	virtual ~linearList() {};
	virtual bool empty()const = 0;
	virtual int getSize()const = 0;
//	virtual int getCapacity()const = 0;
	virtual T& get(int index)const = 0;
	virtual int find(const T& theElement)const = 0;
	virtual void insert(int index, const T& theElement)=0;
	virtual T erase(int index) = 0;
	virtual void output(ostream & out)const=0;
};

