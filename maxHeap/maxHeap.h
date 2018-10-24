#pragma once
#include"arrayList.h"
template<typename T>
class maxHeap
{
private:
	arrayList<T> data;
//��������������������ڸ������������������Һ��Ӻ͸��׽ڵ������
	int  parent(int index) {
		if (index == 0)
			throw illegalParameterValue("index 0 doesn't hava parent. ");
		return (index - 1) / 2;
	}
	int leftChild(int index) {
		return index * 2 + 1;
	}
	int rightChild(int index) {
		return index * 2 + 2;
	}
	void siftUp(int k);//�ϸ� 
	void siftDown(int k);
public:
	maxHeap(int initialCapacity) :data(initialCapacity) {};
	maxHeap() :data() {};
	maxHeap(T arr[], int n) :data(arr, n) {
		for (int i = parent(n - 1); i >= 0; i--) {
			siftDown(i);
		}
	}
	int getSize() { return data.getSize(); }
	bool empty() { return data.empty(); }
	//���Ԫ��
	void add(T e);
	T findMax() { 
		if (data.getSize() == 0)
			throw illegalParameterValue("the heap is null");
		return data.get(0);
	}
	//ȡ����������Ԫ��
	T extractMax() {
		T ret = findMax();
		data.swap(0, data.getSize() - 1);
		siftDown(0);
		return ret;
	}
	//�滻���е����Ԫ��
	T replace(T e) {
		T ret = data.get(0);
		data.insert(0, e);
		siftDown(0);
		return ret;
	}
};
template<typename T>
void maxHeap<T>::siftUp(int k) {
	while (k > 0 && data.get(parent(k)) < data.get(k)) {
		data.swap(k, parent(k));
		k = parent(k);
	}
}
template<typename T>
void maxHeap<T>::add(T e) {
	data.addLast(e);
	siftUp(data.getSize() - 1);
}
template<typename T>
void maxHeap<T>::siftDown(int k) {
	while (leftChild(k) < data.getSize()) {

		int maxChild = leftChild(k);
		if (maxChild+1<data.getSize() && data.get(rightChild(k)) > data.get(maxChild))
			maxChild = rightChild(k);
		//maxChildΪ�����
		if (data.get(k) < data.get(maxChild)) {
			data.swap(k, maxChild);
			k = maxChild;
		}
		else
			break;
	}
}