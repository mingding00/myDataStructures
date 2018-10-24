#pragma once
#include<iostream>
template<typename K, typename V>
struct chainMapNode
{
	K key;
	V value;
	chainMapNode<K, V>* next;
	chainMapNode(K key, V value, chainMapNode<K, V>* next) {
		this->key = key;
		this->value = value;
		this->next = next;
	}
	chainMapNode(K key) {
		this->key = key;
		value = NULL;
		next = nullptr;
	}
	chainMapNode() {
		key = value = NULL;
		next = nullptr;
	}
};