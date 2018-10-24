#pragma once
template<typename K,typename V>
struct treeMapNode
{
	K key;
	V value;
	treeMapNode<K, V>* left;
	treeMapNode<K, V>* right;
	treeMapNode(K key, V value) {
		this->key = key;
		this->value = value;
		left = right = nullptr;
	}
};