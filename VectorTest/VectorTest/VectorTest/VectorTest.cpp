// VectorTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>

using namespace std;

struct Node {
	int value;
	Node*next = NULL;
};
vector <Node*> pmix();
int main()
{
	//Node*arra1[50];
	vector<Node*>arr=pmix();
	//arr.push_back(arra1);
	for (int idx = 0; idx < arr.size(); idx++) {
		cout << arr[idx]->value << endl;
	}

    return 0;
}
vector<Node*> pmix() {
	Node* arr[10];
	vector<Node*> v;
	for (int i = 0; i < 10; i++) {
		arr[i] = new Node();
		arr[i]->value = i*(i + 5);
		v.push_back(arr[i]);
	}
	return v;
}

