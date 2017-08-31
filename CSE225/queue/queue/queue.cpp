#include "stdafx.h"
#include "queue.h"
#include<iostream>

using namespace std;
queue::queue()
{
}


queue::queue(int x)
{
	int *arr = new int[x];
	size = x;
	
}
void queue::push(int x) 
{
	if (head == tail && head == -1) 
	{
		head++;
		tail++;
		arr[tail] = x;
		element++;
	}
	else if (head <= tail) 
	{
		tail++;
		arr[tail%size] = x;
		element++;
	}
	else if(tail!=(head-2))
	{
		tail++;
		arr[tail] = x;
		element++;
	}
	else {//when tail=head
		resizeArray(size*2);
		tail++;
		arr[tail] = x;
		element++;
	}
	
}
int queue::pop() {
	int ret = arr[head%size];
	head++;
	element--;
	return ret;
}
void queue::insert(int x, int idx)
{
	if (element < size) {
		arr[idx] = x;
		element++;
	}
	else {
		resizeArray(size*2);
		arr[idx] = x;
		element++;
	}
}
void queue::print()
{	
	int idx = head;
	for (idx; idx <= tail; idx++) {
		cout << "|| " << arr[idx%size] << "||";
	}
	
	cout << endl << endl;
}

void queue::resizeArray(int x) {
	int *arr2 = new int[x];
	for (int idx = 0; idx < element; idx++) {
		arr2[idx] = arr[idx%size];
	}
	size = x;
	arr = arr2;
}

int queue::getSize()
{
	return element;
}

void queue::manualPrint()
{
	for (int idx = 0; idx < size; idx++)
	{
		cout << "|| " << arr[idx] << "||";
	}
}

queue::~queue()
{
}
