#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include"myExceptions.h"
#include"chainNode.h"
#include"linearList.h"

using namespace std;
template<typename T>
class chainList :public linearList<T>
{
private:
	chainNode<T>* dummyHead;
	int size;
	void checkIndex(int index)const;
public:
	chainList(int initialCapacity = 10);
	chainList(const chainList<T>& theList);
	virtual bool empty()const { return size == 0; }
	virtual int getSize()const { return size; }
//	virtual int getCapacity()const;
	virtual T& get(int index)const ;
	virtual int find(const T& theElement)const ;
	virtual void insert(int index, const T& theElement) ;
	virtual T erase(int index) ;
	virtual void output(ostream & out)const ;
	T& getFirst()const { return get(0); }
	T& getLast()const { return get(0); }
	void addFirst(const T& theElement) { insert(0, theElement); }
	void addLast(const T& theElement) { insert(size, theElement); }
	T removeFirst() { return erase(0); }
	T removeLast() { return erase(size - 1); }
};
template<typename T>
chainList<T>::chainList(int initialCapacity) {
	size = 0;
	dummyHead=new chainNode<T>(NULL, nullptr);
}
template<typename T>
chainList<T>::chainList(const chainList<T>& theList) {
	chainNode<T>* sourceNode = theList.dummyHead;
	chainNode<T>* p = new chainNode(NULL, sourceNode->next);
	dummyHead = p;
	while (sourceNode->next!=nullptr)
	{
		sourceNode = sourceNode->next;
		p->next = new chainNode<T>(sourceNode->element, sourceNode->next);
		p = p->next;
	}
	size = theList.size;
}
template<typename T>
void chainList<T>::checkIndex(int index)const {
	if (index < 0 || index >= size) {
		ostringstream s;
		s << "size = " << size << ", index = " << index << " must be >=0 or < size";
		throw illegalIndexValue(s.str());
	}
}
template<typename T>
T& chainList<T>::get(int index)const {
	checkIndex(index);
	chainNode<T>* p=dummyHead->next;
	for (int i = 0; i < index; i++) {
		p = p->next;
	}
	return p->element;
}
//template<typename T>
//int chainList<T>::find(const T& theElement)const {
//	chainNode<T>* p = dummyHead->next;
//	int i = 0;
//	while (p->element!=theElement && p->next!=nullptr)
//	{
//		p = p->next;
//		i++;
//	}
//	if (i == size)
//		return -1;
//	else
//		return i;
//}
template<typename T>
int findElement(chainNode<T>* Head, T& E) {
	static int i = 0;
	if (head == nullptr)
		return 1;
	if (Head->element == E) 
		return 0;
	else 
		i = 1 + findElement(Head->next, E);
}
template<typename T>
int chainList<T>::find(const T& theElement)const {
	return findElement(dummyHead->next, theElement);
}
template<typename T>
void chainList<T>::insert(int index, const T& theElement) {
	if (index<0 || index>size)
		throw illegalParameterValue("index must be >=0 and <=size");
	chainNode<T>* p = dummyHead;
	for (int i = 0; i < index; i++) {
		p = p->next;
	}
	p->next = new chainNode<T>(theElement, p->next);
	size++;
}
template<typename T>
T chainList<T>::erase(int index){
	chainNode<T>* p = dummyHead;
	for (int i = 0; i < index; i++) {
		p = p->next;
	}
	chainNode<T>*deleteNode = p->next;
	p->next = deleteNode->next;
	T res = deleteNode->element;
	delete deleteNode;
	size--;
	return res;
}
template<typename T>
void chainList<T>::output(ostream& out)const {
	out << "size = " << size << ", front: ";
	chainNode<T>* p = dummyHead->next;
	while (p != nullptr) {
		out << p->element<<"->";
		p = p->next;
	}
	out << "NULL";
}
template<typename T>
ostream& operator<<(ostream& out, const chainList<T> & x) {
	x.output(out);
	return out;
}