#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include"linearList.h"
#include"myExceptions.h"
#include"changeLength1D.h"
using namespace std;
template<typename T>
class arrayList :public linearList<T>
{
private:
	int size;
	int capacity;
	T* element;
	void checkIndex(int index)const;
public:
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>& theList);
	arrayList(T arr[], int size);
	~arrayList() { delete[]element; }
	bool empty()const { return size == 0; }
	int getSize()const { return size; }
	int getCapacity()const { return capacity; }
	T& get(int index)const;
	int find(const T& theElement)const;
	void insert(int index, const T& theElement);
	T erase(int index);
	void output(ostream& out)const;
	T& getFirst()const { return get(0); }
	T& getLast()const { return get(size - 1); }
	void addFirst(const T& theElement) { insert(0, theElement); }
	void addLast(const T& theElement) { insert(size, theElement); }
	T removeFirst() { return erase(0); }
	T removeLast() { return erase(size - 1); }
	void swap(int i, int j);
};
template<typename T>
arrayList<T>::arrayList(int initialCapacity) {
	size = 0;
	capacity = initialCapacity;
	element = new T[capacity];
}
template<typename T>
arrayList<T>::arrayList(const arrayList<T>& theList) {
	size = theList.size;
	capacity = theList.capacity;
	element = new T[capacity];
	for (int i = 0; i < size; i++) {
		element[i] = theList.element[i];
	}
}
template<typename T>
arrayList<T>::arrayList(T arr[], int size) {
	element = new T[size];
	for (int i = 0; i < size; i++) {
		element[i] = arr[i];
	}
	this->size = size;

}
template<typename T>
void arrayList<T>::checkIndex(int index)const {
	if (index < 0 || index >= size) {
		ostringstream s;
		s << "size = " << size << ", index = " << index << " must be >=0 or <size.";
		throw illegalIndexValue(s.str());
	}
}
template<typename T>
T& arrayList<T>::get(int index) const {
	checkIndex(index);
	return element[index];
}
template<typename T>
int arrayList<T>::find(const T& theElement)const {
	for (int i = 0; i < size; i++) {
		if (element[i] == theElement) {
			return i;
		}
	}
	return -1;
}
template<typename T>
void arrayList<T>::insert(int index, const T& theElement) {
	if (index<0 || index>size)
		throw illegalIndexValue("illeagl index");
	if (size == capacity) {
		changeLenght1D(element, capacity, 2 * capacity);
		capacity *= 2;
	}
	for (int i = size; i > index; i--) {
		element[i] = element[i - 1];
	}
	element[index] = theElement;
	size++;
}
template<typename T>
T arrayList<T>::erase(int index) {
	checkIndex(index);
	if (size < capacity / 4) {
		changeLenght1D(element, capacity, capacity / 2);
		capacity = capacity / 2;
	}
	T res = element[index];
	for (int i = index + 1; i < size; i++) {
		element[i - 1] = element[i];
	}
	element[size - 1]=NULL;
	size--;
	return res;
}
template<typename T>
void arrayList<T>::output(ostream& out)const {
	out << "size = " << size << ", capacity = " << capacity<<": [";
	for (int i = 0; i < size; i++) {
		out << element[i];
		if (i != size - 1)
			out << ", ";
	}
	out << " ]";
}
template<typename T>
ostream& operator<<(ostream & out, const arrayList<T>& x) {
	x.output(out);
	return out;
}
template<typename T>
void arrayList<T>::swap(int i, int j) {
	if (i < 0 || i >= size || j < 0 || j >= size)
		throw illegalParameterValue("index is illegal");
	T temp = element[i];
	element[i] = element[j];
	element[j] = temp;
}