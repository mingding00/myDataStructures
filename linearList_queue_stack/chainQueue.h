#pragma once
#include"chainList.h"
#include"Queue.h"
template<typename T>
class chainQueue :public queue<T>
{
private:
	chainList<T> arr;
	int size;
public:
	chainQueue() :size(0), arr() {};
	bool empty()const { return size == 0; }
	int getSize()const { return size; }
	T& getFront()const { return arr.getFirst(); }
	void enqueue(const T& theElement) { arr.addLast(theElement); }
	T dequeue() { return arr.removeFirst(); }
	void output(ostream& out)const {
		out << arr;
	}
};
template<typename T>
ostream& operator<<(ostream& out, const chainQueue<T>& x) {
	x.output(out);
	return out;
}