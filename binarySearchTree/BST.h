#pragma once
#include<iostream>
#include<stack>
#include<list>
#include<queue>
#include"TreeNode.h"
#include"myExceptions.h"
using namespace std;

template<typename T>
class BST
{
//private:
public:
	treeNode<T>* root;
	int size;
	treeNode<T>* add(treeNode<T>* & node, const T& e);
	void preOrder(treeNode<T>* node)const;
	void inOrder(treeNode<T>* node)const;
	void postOrder(treeNode<T>* node)const;
	bool contains(treeNode<T>* node,const T& e)const;
	treeNode<T>* minimum(treeNode<T>* node)const;
	treeNode<T>* maximum(treeNode<T>* node)const;
	treeNode<T>* removeMin(treeNode<T>* & node);
	treeNode<T>* removeMax(treeNode<T>* & node);
	treeNode<T>* removeElement(treeNode<T>*& node, T e);
//public:
	BST() {
		root = nullptr;
		size = 0;
	}
	bool empty()const { return size == 0; }
	int getSize()const { return size; }
	void add(const T& e) { add(root,e); size++; }
	bool contains(const T& e) { return contains(root, e); }
	void preOrder()const { preOrder(root); }
	void inOrder()const { inOrder(root); }
	void postOrder() { postOrder(root); }
	void preOrderNR1 ()const;
	void preOrderNR2()const;
	void inOrderNR()const;
//	void postOrderNR()const;
	void levelOrder()const;
	T minimum() { return minimum(root)->element; }
	T maximum() { return maximum(root)->element; }
	T removeMin() {	T ret = minimum();
					removeMin(root); return ret;	}
	T removeMax() {
					T ret = maximum();
				    removeMax(root); return ret;	}
	void removeElement(T e) { removeElement(root, e); }

};
template<typename T>
treeNode<T>* BST<T>::add(treeNode<T>* &node, const T& e) {
	if (node == nullptr)
		return node = new treeNode<T>(e);
	else {
		if (e > node->element)
			node->right = add(node->right, e);
		else if(e<node->element)
			node->left = add(node->left, e);
		return node;
	}
}
//template<typename T>
//void BST<T>::add(treeNode<T>* & node, const T& e) {
//	if (node == nullptr)
//		node = new treeNode<T>(e);
//	else
//	{
//		if (e > node->element)
//			add(node->right, e);
//		else
//			add(node->left, e);
//	}	
//}
template<typename T>
bool BST<T>::contains(treeNode<T>* node, const T& e)const {
	if (node == nullptr)
		return false;
	else
	{
		if (node->element == e) {
			return true;
		}
		else
		{
			if (e > node->element)
				return contains(node->right, e);
			else
				return contains(node->left, e);
		}
	}
}

template<typename T>
void BST<T>::preOrder(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	cout << node->element<<", ";
	preOrder(node->left);
	preOrder(node->right);
}
template<typename T>
void BST<T>::inOrder(treeNode<T>* node)const {
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
void BST<T>::postOrder(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	else {
		postOrder(node->left);
		postOrder(node->right);
		cout << node->element<<", ";
	}
}
template<typename T>
void BST<T>::preOrderNR1()const {
	if (root == nullptr)
		return;
	stack<treeNode<T>*> Stack;
	Stack.push(root);
	while (!Stack.empty()) {
		treeNode<T>* cur = Stack.top();
		Stack.pop();
		cout << cur->element<<", ";
		if(cur->right!=nullptr)
			Stack.push(cur->right);
		if (cur->left != nullptr)
			Stack.push(cur->left);
	}
}
template<typename T>
void BST<T>::preOrderNR2()const{     //非递归前序遍历2 
	stack<treeNode<T>*> Stack;
	treeNode<T> *p = root;
	while (p != nullptr || !Stack.empty())
	{
		while (p != nullptr)
		{
			cout << p->element << " ";//前序遍历入栈前输出
			Stack.push(p);      //然后入栈
			p = p->left;
		}
		if (!Stack.empty())
		{
			treeNode<T>* cur = Stack.top();
			p = cur->right;
			Stack.pop();
		}
	}
}
template<typename T>
void BST<T>::inOrderNR()const {
	stack<treeNode<T>*> Stack;
	treeNode<T>* p = root;
	while (p!=nullptr || !Stack.empty()) {//注意两个条件不能省
		while (p!=nullptr)
		{
			Stack.push(p);
			p = p->left;
		}
		if (!Stack.empty()) {
			treeNode<T>* cur = Stack.top();
			p = cur->right;
			cout << cur->element<<", ";
			Stack.pop();
		}
		//用cur记录栈顶，用p记录cur的右孩子，然后出栈输出
		//直到栈顶的右孩子不为空再入栈，且一入到底。 
	}
}



template<typename T>
void BST<T>::levelOrder()const {
//使用队列边进边出，进来的为弹出的那个栈顶的左右孩子
	queue<treeNode<T>*> Queue;
	Queue.push(root);
	while (!Queue.empty())
	{
		treeNode<T>* cur = Queue.front();
		cout << cur->element<<", ";
		Queue.pop();
		if (cur->left != nullptr)
			Queue.push(cur->left);
		if (cur->right != nullptr)
			Queue.push(cur->right); 
	}
}
template<typename T>
treeNode<T>* BST<T>::minimum(treeNode<T>* node)const {
	if (node == nullptr)
		throw illegalParameterValue("the BST is empty");
		if (node->left == nullptr)
			return node;
		else
		{
			return minimum(node->left);
		}
}
template<typename T>
treeNode<T>* BST<T>::maximum(treeNode<T>* node)const {
	if (node == nullptr)
		throw illegalParameterValue("the BST is empty");
		if (node->right == nullptr)
			return node;
		else
		{
			return maximum(node->right);
		}
}

template<typename T>
treeNode<T>* BST<T>::removeMin(treeNode<T>* & node) {
	if (node->left==nullptr)
	{
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
treeNode<T>* BST<T>::removeMax(treeNode<T>* & node) {
	if (node->right == nullptr)
	{
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
template<typename T>//利用元素所在节点的后继删除该元素，还可以使用前驱
treeNode<T>* BST<T>::removeElement(treeNode<T>*& node,T e) { 
	if (node == nullptr)
		return nullptr;
	else
	{
		if (e > node->element)
			node->right = removeElement(node->right, e);
		if (e < node->element)
			node->left = removeElement(node->left, e);
		else
		{
			if (node->left == nullptr) {
				treeNode<T>* p = node->right;
				delete node; size--;
				return p;
			}
			else if (node->right==nullptr)
			{
				treeNode<T>* p = node->left;
				delete node;size--
				return p;
			}
			else
			{
				treeNode<T>* p =new treeNode<T>(minimum(node->right)->element);
				p->right = removeMin(node->right);
				p->left = node->left;
				delete node;
				return p;
			}

		}
	}

}
//template<typename T>
//class BST
//{
//private:
//	treeNode<T>* root;
//	int size;
//	treeNode<T>* add( treeNode<T>* &node, const T& e);
//	bool contains(const treeNode<T>* node, const T& e)const;
//	void preOrder(treeNode<T>* node);
//	void output(treeNode<T>* node)const;
//	void inOrder(treeNode<T>* node);
//public:
//	BST() {
//		root = nullptr;
//		size = 0;
//	}
//	int getSize(){ return size; }
//	bool empty() { return size == 0; }
//	void add(const T& e) {
//		add(root, e); size++;
//	}
//	bool contains(const T& e)const {
//		return contains(root, e);
//	}
//	void preOrder() {
//		preOrder(root);
//	}
//	void inOrder() {
//		inOrder(root);
//	}
//	void output()const {
//		output(root);
//	}
//};
//template<typename T>
//treeNode<T>* BST<T>::add( treeNode<T>* & node, const T& e) {
//	if (node == nullptr) {
//		return node = new treeNode<T>(e);
//	}
//	else
//	{
//		if (node->element > e)
//			node->left = add(node->left, e);//此处node的右指针需要指向下一级节点，该节点必须由add函数返回，也就是说add无论如何都必须返回当前的node
//		else
//			node->right = add(node->right, e);
//	}
//	return node;//必须把当前的头节点返回给上级递归的left或right，				//如果不返回的话，则虽然在递归的入栈部分正常，但返回的时候，所有的add函数返回值都指向最后new的那个空间,则上面每一级的指针都指向最后new的那个空间
//}
//
//template<typename T>
//bool BST<T>::contains(const treeNode<T>* node, const T& e)const {
//	if (node == nuuptr) {
//		return false;
//	}
//	if (node->element == e) {
//		return true;
//	}
//	else if (node->element > e) {
//		return find(node->left);
//	}
//	else if (node->element < e) {
//		return find(node->right, e);
//	}
//}
//template<typename T>
//void BST<T>::preOrder(treeNode<T>* node) {
//	if (node == nullptr)
//		return;
//	cout << node->element;
//	preOrder(node->left);
//	preOrder(node->right);
//}
//template<typename T>
//void BST<T>::output(treeNode<T>* node)const {
//	if (node == nullptr) {
//		cout << "nullptr" << endl; return;
//	}
//	else {
//		cout << node->element<<endl;
//	}
//	output(node->left);
//	output(node->right);
//}
//template<typename T>
//void BST<T>::inOrder(treeNode<T>* node) {
//	if (node == nullptr)
//		return;
//	inOrder(node->left);
//	cout << node->element;
//	inOrder(node->right);
//}
