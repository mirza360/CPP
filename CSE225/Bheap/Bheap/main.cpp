// Bheap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"pqtype.cpp"

using namespace std;
int main()
{
	PQType<int> pq(10);
	if (pq.IsEmpty()) {
		cout << "Queue is empty" << endl;
	}
	else {
		cout << "Queue is not empty" << endl;
	}
	//insert items
	pq.Enqueue(4);
	pq.Enqueue(9);
	pq.Enqueue(2);
	pq.Enqueue(7);
	pq.Enqueue(3);
	pq.Enqueue(11);
	pq.Enqueue(17);
	pq.Enqueue(0);
	pq.Enqueue(5);
	pq.Enqueue(1);
	//end of insertion
	if (pq.IsEmpty()) {
		cout << "Queue is empty" << endl;
	}
	else {
		cout << "Queue is not empty" << endl;
	}
	//print elements
	pq.PrintQueue();
	//dequeue
	int x = 0;
	pq.Dequeue(x);
	cout << x << endl;
	pq.Dequeue(x);
	cout << x << endl;
	//print
	pq.PrintQueue();
    //Dequeue thrice
	pq.Dequeue(x);
	pq.Dequeue(x);
	pq.Dequeue(x);
	//print
	pq.PrintQueue();
	
	return 0;
}

