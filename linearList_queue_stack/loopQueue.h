#pragma once
#include<iostream>
#include"Queue.h"
#include"myExceptions.h"
template<typename T>
class loopQueue :public queue<T>
{
private:
	T * element;
	int front;
	int tail;
	int size;
	int capacity;
	//void checkIndex(int index)const;
public:
	loopQueue(int initialCapacity = 10);
	loopQueue(const loopQueue<T>& theQueue);
	~loopQueue();
	bool empty()const { return front==tail; }
	int getSize()const { return size; }
	T& getFront()const { return element[front]; }
	void enqueue(const T& theElement);
	T dequeue();
	void output(ostream& out)const;
};
template<typename T>
loopQueue<T>::loopQueue(int initialCapacity) {
	capacity = initialCapacity;
	element = new T[capacity + 1];
	size = 0;
	front = tail = 0;
}
template<typename T>
loopQueue<T>::loopQueue(const loopQueue<T>& theQueue) {
	size = theQueue.size;
	capacity = theQueue.capacity;
	front = theQueue.front;
	tail = theQueue.tail;
	element = new T[capacity + 1];
	int res;
	for (int i = 0; i < size; i++) {
		res = (i + front) % (capacity + 1);
		element[res] = theQueue.element[res];
	}
}
template<typename T>
loopQueue<T>::~loopQueue() {
	delete[]element;
}
template<typename T>
void loopQueue<T>::enqueue(const T& theElement) {
	if ((tail + 1) % (capacity + 1) == front) {
		T* temp = new T[2 * capacity + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = element[(i + front)%(capacity+1)];
		}
		capacity *= 2;
		delete[]element;
		element = temp;
		front = 0;
		tail = size;
	}
	element[tail]=theElement;
	tail = (tail + 1) % (capacity + 1);
	size++;
}
template<typename T>
T loopQueue<T>::dequeue() {
	if (front == tail)
		throw illegalParameterValue("the queue is empty");
	T res = element[front];
	element[front] = NULL;
	front = (front + 1) % (capacity + 1);
	size--;
	
	if (size < capacity / 4 && capacity / 2 != 0) {
		T* temp = new T[capacity / 2 + 1];
		for (int i = 0; i < size; i++) {
			temp[i]=element[(front+i)%(capacity+1)];
		}
		delete[]element;
		element = temp;
		capacity = capacity / 2;
		front = 0;
		tail = size;
	}
	return res;
}
template<typename T>
void loopQueue<T>::output(ostream& out)const {
	out << "size: " << size << " capacity: " << capacity<<" front: [";
	if (front == tail) {
		out << "the queue is empty ]";
	}
	else
	{
		for (int i = front; i != tail; i = (i + 1) % (capacity + 1)) {
			out << element[i];
			if (i != tail-1) {
				out << ", ";
			}
		}
		out << " ] tail" <<"front = "<<front<<" tail = "<<tail<< endl;
	}
}
template<typename T>
ostream & operator<<(ostream& out, const loopQueue<T>& x) {
	x.output(out);
	return out;
}