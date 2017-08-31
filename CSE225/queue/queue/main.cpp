// queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "queue.h"
#include<iostream>
using namespace std;

int main()
{
	queue q(5);
	while (true) {
		cout << "Input 1 for Push and 2 for pop 3 for print 4 for size 5 for manual print" << endl;
		int in;
		cin >> in;
		switch (in) {
		case 1: {
			int push;
			cin >> push;
			q.push(push);
			q.print();
		} break;
		case 2: {
			q.pop();
			q.print();

		} break;
		case 3: {
			q.print();

		}break;
		case 4: {
			cout << q.getSize()<<endl;
		}break;
		case 5: {
			q.manualPrint();
		}break;
		}
		
	}
}

