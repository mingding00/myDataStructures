#pragma once
#include<iostream>
template<typename K,typename V>
class Map
{
public:
	virtual ~Map() {};
	virtual void add(K key, V value) = 0;
	virtual V remove(K key) = 0;
	virtual void set(K key, V newValue) = 0;
	virtual bool contains(K,key)const = 0;
	virtual V get(K key)const = 0;
	virtual int getSize()const = 0;
	virtual bool empty()const = 0;
	virtual void output(ostream& out)const = 0;
};
