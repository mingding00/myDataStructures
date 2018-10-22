#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct treeNode {
	T element;
	treeNode<T>* left;
	treeNode<T>* right;
	treeNode(const T& element) {
		this->element = element;
		left = right = nullptr;
	}
};