#pragma once
#include<iostream>
#include"myException.h"
#include"Map.h"
#include"treeMapNode.h"
using namespace std;
template<typename K,typename V>
class treeMap
{
public:
	treeMap() :size(0), node(NULL, NULL) {};
	void add(K key, V value) { add(root, key, value); }
	treeMapNode<K, V>* getNode(treeMapNode<K,V>* node,K key)const;
	void remove(K key) { remove(root, key); }
	void set(K key, V newValue);
	bool contains(K key)const;
	V get(K key)const;
	bool empty()const { return size == 0; };
	int getSize()const { return size; };
private:
	treeMapNode<K, V>* root;
	int size;
	treeMapNode<K, V>* add(treeMapNode<K, V>* node, K key, V value);
	treeMapNode<K, V>* minimum(treeMapNode<K, V>* node)const;
	treeMapNode<K, V>* removeMin(treeMapNode<K, V>* node);
	treeMapNode<K, V>* remove(treeMapNode<K, V>* node, K key);
};
template<typename K,typename V>
treeMapNode<K, V>* treeMap<K, V>::add(treeMapNode<K, V>* node, K key, V value) {
	if (node == nullptr) {
		node = new treeMapNode<K, V>(key, value);
		return node;
	}
	else
	{
		if (key > node->key)
			node->right = add(node->right, key, value);
		else if (key < node->key)
			node->left = add(node->left, key, value);
		else
		{
			node->value = value;
		}
		return node;
	}
}
template<typename K,typename V>
treeMapNode<K, V>* treeMap<K,V>::getNode(treeMapNode<K,V>* node,K key)const {
	if (node == nullptr)
		return nullptr;
	else
	{
		if (key == node->key)
			return node;
		else if (key > node->key)
			return getNode(node->right);
		else
			return getNode(node->left);		
	}
}
template<typename K,typename V>
bool treeMap<K, V>::contains(K key)const {
	return getNode(root, key) != nullptr;
}
template<typename K, typename V>
V treeMap<K, V>::get(K key)const {
	treeMapNode<K, V>* node = getNode(root, key);
	return node == nullptr ? NULL : node->value;
}
template<typename K, typename V>
void treeMap<K, V>::set(K key, V newValue) {
	treeMapNode<K, V>* node = getNode(root, key);
	if (node == nullptr)
		throw illegalParamentValue("no Key");
	else
	{
		node->value = newValue;
	}
}
template<typename K, typename V>
treeMapNode<K, V>* treeMap<K, V>::minimum(treeMapNode<K, V>* node)const {
	if (node->left == nullptr)
		return node;
	else
		return minimum(node->left);
}
template<typename K, typename V>
treeMapNode<K, V>* treeMap<K, V>::removeMin(treeMapNode<K, V>* node) {
	if (node->left == nullptr)
		return node->right;
	else
	{
		node->left = removeMin(node->left);
		return node;
	}
}
template<typename K,typename V>
treeMapNode<K,V>* treeMap<K, V>::remove(treeMapNode<K,V>* node,K key) {
	if (root == nullptr)
		return NULL;
	else
	{
		if (key > node->key)
			node->right = remove(node->right, key);
		else if (key < node->key)
			node->left = remove(node->left, key);
		else
		{
			treeMapNode<K, V>* p = minimum(node->right);
			treeMapNode<K, V>* newNode = new treeMapNode<K, V>(p->key, p->value);
			newNode->left = node->left;
			newNode->right = removeMin(node->right);
			delete node;
			return newNode;
		}
	}
}