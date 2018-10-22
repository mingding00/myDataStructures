#pragma once
#include<iostream>
#include"myExceptions.h"
using namespace std;
template<typename T>
void changeLenght1D(T* & element, int oldLength, int newLength) {
	if (newLength <= 0)
		throw illegalParameterValue("new length must be > 0");
	int len;
	if (newLength > oldLength)
		len = oldLength;
	else
		len = newLength;
	T* temp = new T[newLength];
	for (int i = 0; i < len; i++) {
		temp[i] = element[i];
	}
	delete[]element;
	element = temp;
}