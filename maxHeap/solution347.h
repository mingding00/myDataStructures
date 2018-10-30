#pragma once
#include<vector>
#include<iostream>
#include<unordered_map>
#include"priorityQueue.h"
using namespace std;
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> record;
		for (int i = 0; i < nums.size(); i++)
			record[nums[i]] += 1;
		for (unordered_map<int, int>::iterator iterator2 = record.begin(); iterator2 != record.end(); ++iterator2) {
			cout << iterator2->first << " " << iterator2->second << endl;
		}
		priorityQueue<Freq> *priorityqueue = new priorityQueue<Freq>();
		for (unordered_map<int, int>::iterator iterator1 = record.begin();iterator1 != record.end(); iterator1++) {
			if (priorityqueue->getSize() < k) {
				priorityqueue->enqueue(Freq(iterator1->first, iterator1->second));
			}
			else if (iterator1->second > priorityqueue->getFront().freq) {
				priorityqueue->dequeue();
				priorityqueue->enqueue(Freq(iterator1->first, iterator1->second));
			}
		}
		vector<int> res;
		while (!priorityqueue->empty()) {
			res.push_back(priorityqueue->dequeue().e);
		}
		return res;
	}
private:
	class Freq {
	public:
		int e, freq;
		Freq(int e = 0, int freq = 0) {
			this->e = e;
			this->freq = freq;
		}
		bool operator<(const Freq& another) {
			if (this->freq < another.freq)
				return false;
			else
				return true;
		}
		bool operator>(const Freq& another) {
			if (this->freq > another.freq) 
				return false;
			else
			{
				return true;
			}
		}
	};
}; 