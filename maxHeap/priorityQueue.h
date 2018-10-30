#pragma once
#include<iostream>
#include"maxHeap.h"
#include"Queue.h"
template<typename T>
class priorityQueue:public queue<T>
{
private:
	maxHeap<T> maxheap;
public:
	priorityQueue() :maxheap() {};
	int getSize()const { return maxheap.getSize(); }
	bool empty()const { return maxheap.empty(); }
	T getFront() { return maxheap.findMax(); }
	void enqueue(T element) {
		maxheap.add(element);
	}
	T dequeue() {
		return maxheap.extractMax();
	}
};