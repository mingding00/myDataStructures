// maxHeap.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"maxHeap.h"
#include<ctime>
#include<cstdlib>
#include"solution347_2.h"
template<typename T>
static double testHeap(T arr[], int n, bool isHeapify) {
	clock_t startTime = clock();
	maxHeap<T> *heap;
	if (isHeapify) {
		heap=new maxHeap<T>(arr, n);
	}
	else
	{
		heap=new maxHeap<T>(10);
		for (int i = 0; i < n; i++) {
			heap->add(arr[i]);
		}
	}
	int *p = new int[n];
	for (int i = 0; i < n; i++) {
		p[i] = heap->extractMax();
	}
	for (int i = 1; i < n; i++)
	{
		if (p[i - 1] < p[i])
			throw illegalParameterValue("error");
	}
	clock_t endTime = clock();
	return (endTime - startTime) / 1000.0;
}
const int n = 100000;
int testData[n];
int main()
{
	srand(time(0));
	for (int i = 0; i < n; i++) {
		int random= rand();
		testData[i] = random;
	}
	double t1 = testHeap(testData, n, false);
	double t2 = testHeap(testData, n, true);
	cout << t1 << endl;
	cout << "heapify: " << t2<<endl;
	Solution solution;
	int a[28] = { 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,7,7 };
	vector<int> arr(a,a+28);
	vector<int> b = solution.topKFrequent(arr, 3);
	cout << "[";
	for (int i = 0; i < b.size();i++) {
		cout <<b[i]<<" ";
	}
	cout << "]";
    return 0;
}

