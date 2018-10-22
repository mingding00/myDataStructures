#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct chainNode{
	chainNode<T>* next;
	T element;
	chainNode() {
		element = NULL;
		next = nullptr;
	}
	chainNode(const T& element, chainNode<T>* next) {
		this->element = element;
		this->next = next;
	}
	chainNode(const T& element) {
		this->element = element;
		next = nullptr;
	}
	chainNode(const T arr[], int n) {
		chainNode<T>* p = this;
		element=arr[0];
		for (int i = 1; i < n; i++) {
			p->next = new chainNode<T>(arr[i]);
			p = p->next;
		}
	}
};