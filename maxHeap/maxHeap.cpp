// maxHeap.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"maxHeap.h"
#include<ctime>
#include<cstdlib>
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
const int n = 10000000;
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
	cout << "heapify: " << t2;
    return 0;
}

