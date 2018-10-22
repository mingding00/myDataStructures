#pragma once
#include"chainList.h"
#include"stack.h"
template<typename T>
class chainStack :public stack<T>
{
private:
	chainList<T> theList;
public:
	chainStack() :theList() {};
	bool empty()const { return theList.empty(); }
	int getSize()const { return getSize(); }
	T& top()const { return theList.getLast(); }
	void push(const T& theElement) { theList.addLast(theElement); }
	T pop() { return theList.removeLast(); }
	void output(ostream& out)const { out << theList<<" tail"; }
};
template<typename T>
ostream& operator<<(ostream& out, const chainStack<T>& x) {
	x.output(out);
	return out;
}