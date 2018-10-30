#pragma once
#include<iostream>
#include"arrayList.h"
using namespace std;
template<typename T>
class minHeap
{
private:
	arrayList<T> data;
	int parent(int k) { return (k - 1) / 2; }
	int leftChild(int k) { return 2 * k + 1; }
	int rightChild(int k) { return 2 * k + 2; }
	void siftUp(int k);
	void siftDown(int k);
public:
	minHeap() :data() {};
	minHeap(int initialCapacity) :data(initialCapacity) {};
	minHeap(T arr[], int n) :data(arr, n) {
		for (int i = parent(n - 1))
			siftDown(i);
	}
	int getSize() { return data.getSize(); }
	bool empty() { return data.empty(); }
	T findMin() {
		if (data.getSize() == 0)
			throw illegalParameterValue("the Heap is null");
		return data.get(0)
	}
	void add(T e) {
		data.addLast(e);
		siftUp(data.getSize() - 1);
	}
	T extractMin() {
		T ret = findMin();
		data.swap(0, data.getSize() - 1);
		siftDown(0);
		return ret;
	}
	T replace(T e) {
		T ret = data.get(0);
		data.insert(0, e);
		siftDown(0);
		return ret;
	}
};
template<typename T>
void minHeap<T>::siftUp(int k) {
	while (k>0 && data.get(k)<data.get(parent(k)))
	{
		data.swap(k,parent(k));
		k = parent(k);
	}
}
template<typename T>
void minHeap<T>::siftDown(int k) {
	//data.swap(k, data.getSize() - 1);
	while (leftChild(k) < data.getSize()) {
		int min = leftChild(k);
		if (min+1<data.getSize() && leftChild(k) > rightChild(k))
			min = rightChild(k);
		if (data.get(k) < data.get(min))
			break;
		else if (data.get(k) > data.get(min)) {
			data.swap(k, min);
			k = min;
		}
	}
} 