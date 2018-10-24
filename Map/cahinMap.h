#pragma once
#include"chainMapNode.h"
#include"linearList.h"
#include"Map.h"
#include"myException.h"
using namespace std;
template<typename K,typename V>
class  chainMap: public Map<K,V>
{
public:
	 chainMap();
	 int getSize()const { return size; }
	 bool empty()const { return size == 0; }
	 chainMapNode<K, V>* getNode(K key)const;
	 void add(K key, V value);
	 V remove(K key);
	 void set(K key, V newValue);
	 V get(K key)const;
	 bool contains(K key)const;
	 void output(ostream& out)const;
private:
	chainMapNode<K, V>* dummyHead;
	int size;
};

template<typename K, typename V>
chainMap<K, V>::chainMap() {
	size == 0;
	dummyHead = new chainMapNode<K, V>();
}
template<typename K, typename V>
chainMapNode<K, V>* chainMap<K, V>::getNode(K key)const {
	chainMapNode<K, V>* cur = dummyHead->next;
	while (cur != nullptr) {
		if (cur->key == key) {
			return cur;
		}
		cur = cur->next;
	}
	return nullptr;
}

template<typename K, typename V>
void chainMap<K, V>::add(K key, V value) {
	chainMapNode<K, V>* node = getNode(key);
	if (node == nullptr) {
		dummyHead->next = new chainMapNode<K, V>(key, dummyHead->key)
			size++;
	}
	else
	{
		node->value=value
	}
}

template<typename K, typename V>
V chainMap<K, V>::remove(K key) {
	chainMapNode<K, V>* prev = dummyHead;
	while (prev->next != nullptr) {
		if (prev->next->key == key)
			break;
		prev = prev->next;
	}
	if (prev->next != nullptr) {
		chainMapNode<K, V>* deleteNode = prev->next;
		V dvalue = deleteNode->value;
		prev->next = deleteNode->next;
		delete deleteNode;
		size--;
		return dvalue;
	}
	else
	{
		return NULL;
	}
	
}
template<typename K, typename V>
void chainMap<K, V>::set(K key, V newValue) {
	chainMapNode<K, V>* node = getNode(key);
	if (node == nullptr)
		throw illegalParamentValue("no key");
	else
	{
		node->value = newValue;
	}
}
template<typename K, typename V>
V chainMap<K, V>::get(K key)const {
	chainMapNode<K, V>* node = getNode(key);
	if (node == nullptr)
		return NULL;
	else
	{
		return node->value;
	}
}
template<typename K, typename V>
bool chainMap<K, V>::contains(K key)const {
	return getNode(key)!=nullptr;
}
template<typename K, typename V>
void chainMap<K, V>::output(ostream& out)const {
	chainMapNode<K, V>* cur = dummyHead->next;
	int i = 1;
	while (cur!=nullptr)
	{
		out << "key: " << cur->key << ", " << "value: " << cur->value;
		if (i % 3 == 0)
			out << endl;
		i++;
		cur = cur->next;
	}
}
template<typename K,typename V>
ostream& operator<<(ostream& out, const chainMap<K, V>& x) {
	x.output(out);
	return out;
}