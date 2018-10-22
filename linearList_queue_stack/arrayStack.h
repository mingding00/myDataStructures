#pragma once
#include"stack.h"
#include"arrayList.h"
template<typename T>
class arrayStack:public stack<T>
{
public:
	arrayStack() : arr() {};
	bool empty()const { return arr.empty(); }
	int getSize()const { return arr.getSize(); }
	T& top()const { return arr.getLast(); }
	void push(const T& theElement) {  arr.addLast(theElement); }
	T pop() { return arr.removeLast(); }
	void output(ostream& out)const {
		out << arr;
	}
private:
	arrayList<T> arr;
};

template<typename T>
ostream& operator<<(ostream& out,const arrayStack<T>& x) {
	x.output(out);
	return out;
}