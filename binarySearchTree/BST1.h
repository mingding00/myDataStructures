#pragma once
#include<iostream>
#include<stack>
#include<queue>
#include<list>
#include"TreeNode.h"
#include"myExceptions.h"
using namespace std;
template<typename T>
class BST1
{
public:
	BST1() :size(0), root(NULL) {};
	int getSize()const { return size; }
	bool empty()const { return size == 0; }
	void add(T e) { add(root, e); size++; }
	void addNoReturn(T e) { addNoReturn(root, e); size++; }
	bool contains(T e)const { return contains(root, e); }
	void preOrder()const { preOrder(root); }
	void preOrderNR1()const { preOrderNR1(root); }
	void inOrder()const { inOrder(root); }
	void inOrderNR()const { inOrder(root); }
	void postOrder()const { postOrder(root); }
	void levelOrder()const { levelOrder(root); }
	T minimum()const { return minimum(root)->element; }
	T maximum()const { return maximum(root)->element; }
	T removeMin() { T ret = minimum(); removeMin(root); return ret; }
	T removeMax() { T ret = maximum(); removeMax(root); return ret; }
	void removeElement(T e) { removeElement(root, e); }
//private:
	treeNode<T>* root;
	int size;
	treeNode<T>* add(treeNode<T>* &node, T e);
	void addNoReturn(treeNode<T>* node, T e);
	bool contains(treeNode<T>* node, T e)const;
	void preOrder(treeNode<T>* node)const;
	void preOrderNR1(treeNode<T>* node)const;
	void inOrder(treeNode<T>* node)const;
	void inOrderNR(treeNode<T>* node)const;
	void postOrder(treeNode<T>* node)const;
	void levelOrder(treeNode<T>* node)const;
	treeNode<T>* minimum(treeNode<T>* node)const;
	treeNode<T>* maximum(treeNode<T>* node)const;
	treeNode<T>* removeMin(treeNode<T>* node);
	treeNode<T>* removeMax(treeNode<T>* node);
	treeNode<T>* removeElement(treeNode<T>* node, T e);

};
template<typename T>
treeNode<T>* BST1<T>::add(treeNode<T>*& node, T e) {
	if (node == nullptr) {
		node=new treeNode<T>(e);
		return node;
	}
	else
	{
		if (e > node->element)
			node->right = add(node->right, e);
		else if (e < node->element)
			node->left = add(node->left, e);
		return node;
	}
}
template<typename T>
void BST1<T>::addNoReturn(treeNode<T>* node, T e) {
	if (node == nullptr)
		node->element = e;
	else
	{
		if (e > node->element)
			add(node->right, e);
		else if (e < node->element)
			add(node->left, e);
	}
}
template<typename T>
bool BST1<T>::contains(treeNode<T>* node, T e)const {
	if (node == nullptr)
		return false;
	if (node->element == e)
		return true;
	else
	{
		if (e > node->element)
			return contains(node->right, e);
		if (e < node->element)
			return contains(node->left, e);
	}
}
template<typename T>
void BST1<T>::preOrder(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	else
	{
		cout << node->element<<", ";
		preOrder(node->left);
		preOrder(node->right);
	}
}
template<typename T>
void BST1<T>::preOrderNR1(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	treeNode<T>* p = node;
	stack<treeNode<T>*> Stack;
	while (p != nullptr || !Stack.empty()) {
		while (p != nullptr) {
			cout << p->element<<", ";
			Stack.push(p);
			p = p->left;
		}
		treeNode<T>* cur = Stack.top();
		Stack.pop();
		p = cur->right;
	}
}
template<typename T>
void BST1<T>::inOrder(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	else
	{
		inOrder(node->left);
		cout << node->element<<", ";
		inOrder(node->right);
	}
}
template<typename T>
void BST1<T>::inOrderNR(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	treeNode<T>* p = node;
	stack<treeNode<T>*> Stack;
	while (p != nullptr || !Stack.empty()) {
		while (p != nullptr) {
			Stack.push(p);
			p = p->left;
		}
		treeNode<T>* cur = Stack.top();
		cout << cur->element<<", ";
		Stack.pop();
		p = cur->right;
	}
}
template<typename T>
void BST1<T>::postOrder(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	else
	{
		postOrder(node->left);
		postOrder(node->right);
		cout << node->element<<", ";
	}
}
template<typename T>
treeNode<T>* BST1<T>::minimum(treeNode<T>* node)const {
	if (node == nullptr)
		throw illegalParameterValue("the BTS is null");
	else
	{
		if (node->left == nullptr)
			return node;
		else
			return minimum(node->left);
	}
}
template<typename T>
treeNode<T>* BST1<T>::maximum(treeNode<T>* node)const {
	if (node == nullptr)
		throw illegalParameterValue("the BTS is null");
	else
	{
		if (node->right == nullptr)
			return node;
		else
			return maximum(node->right);
	}
}
template<typename T>
treeNode<T>* BST1<T>::removeMin(treeNode<T>* node) {
	if (node == nullptr)
		throw illegalParameterValue("the node is null");
	if (node->left == nullptr) {
		treeNode<T>* rnode = node->right;
		delete node;
		size--;
		return rnode;
	}
	else
	{
		node->left = removeMin(node->left);
		return node;
	}

}
template<typename T>
treeNode<T>* BST1<T>::removeMax(treeNode<T>* node) {
	if (node == nullptr)
		throw illegalParameterValue("the node is null");
	if (node->right == nullptr) {
		treeNode<T>* lnode = node->left;
		delete node;
		size--;
		return lnode;
	}
	else
	{
		node->right = removeMax(node->right);
		return node;
	}
}
template<typename T>
treeNode<T>* BST1<T>::removeElement(treeNode<T>* node, T e) {
	if (node == nullptr)
		return nullptr;
	else
	{
		if (e > node->element) {
			node->right = removeElement(node->right, e);
		}
		if (e < node->element) {
			node->left = removeElement(node->left, e);
		}
		if (e == node->element) {
			if (node->right == nullptr) {
				treeNode<T>* lnode = node->left;
				delete node;
				return lnode;
			}
			if (node->left == nullptr) {
				treeNode<T>* rnode = node->right;
				delete node;
				return rnode;
			}
			else
			{
				treeNode<T>* p = minimum(node->right);
				treeNode<T>* cur = new treeNode<T>(p->element);
				cur->left = node->left;
				cur->right = removeMin(node->right);
				delete node;
				return cur;
			}
		}
		return node;
	}
}
template<typename T>
void BST1<T>::levelOrder(treeNode<T>* node) const {
	if (node == nullptr)
		return;
	queue<treeNode<T>*> Queue;
	Queue.push(node);
	while (!Queue.empty()) {
		treeNode<T>* cur = Queue.front();
		Queue.pop();
		cout << cur->element<<", ";
		if (cur->left != nullptr)
			Queue.push(cur->left);
		if (cur->right != nullptr)
			Queue.push(cur->right);
	}
}