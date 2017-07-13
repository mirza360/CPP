// fileOp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;
int main()
{
	string st = "The quick brown fox jumps over the lazy dog";
	
	string st1 = "fox";
	string st2 = "box";
	string st3 = "fox";
	//take input full line
	getline(cin, st2);
	//size test
	cout << st.size()<<endl;
	//charAt test
	cout << st.at(2)<< endl;
	//string equal test
	if (st1 == st3) {
		cout << "true" << endl;
	}
	//punctuation test
	if (ispunct(st.at(3))) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	//output the line
	cout << st2 << endl;
    //Line Empty check
	if (empty(st)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;
}

