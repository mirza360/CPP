// Variable-2D-Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{	
	int row=0;
	int col=0;
	cout << "Enter Number of Row: ";
	cin >> row;
	int **array = new int*[row];
	for (int idx = 0; idx < row; idx++) 
	{
		cout << "Enter Number of Column for row # "<<(idx+1)<<" :";
		cin >> col;
		array[idx] = new int[col];
		
	}
	cout << sizeof(array[0])/sizeof(array[0][0]);
	/*
	for (int idx = 0; idx < row; idx++) {
		for (int id = 0; id < sizeof(array[idx][id]); id++) {
			//array[idx][id] = 5;
			cout << "Row # " << idx << " Col# " << id << endl;
		}
	}*/
	/*
	for (int idx = 0; idx < row; idx++) {
		for (int id = 0; id < col; id++) {
			cout << array[idx][id]<<" ";
		}
		cout << endl;
	}
	*/
    return 0;
}

