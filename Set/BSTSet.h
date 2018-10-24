#pragma once
#include"BST.h"
#include"Set.h"
using namespace std;
template<typename T>
class BSTSet :public Set<T>
{
private:
	BST<T> bst;
public:
	BSTSet() :bst() {};
	bool empty()const { return bst.empty(); }
	int getSize()const { return bst.getSize(); }
	bool contains(T e)const { return bst.contains(e); }
	void add(T e) { bst.add(e); }
	void remove(T e) { bst.remove(e); }
};