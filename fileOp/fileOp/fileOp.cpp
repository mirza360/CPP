// fileOp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
using namespace std;
int wCount = 0;
void tokenize(string st);
int main(/*char *argv[]*/)
{
	string line;
	ifstream myfile;
	myfile.open("file.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//cout << line << '\n';
			//cout << "-*55685464564654564564" << endl;
			
			tokenize(line);
		}
		myfile.close();
	}
	else {
		cout << "Unable to open";
	}
	return 0;
}

void tokenize(string st) {
	
	//char spc = 32;
	//cout << st << endl;
	cout <<endl <<st.size()<<endl;
	string word="";
	for (long long i = 0;i < st.size()-1;i++) {
		//cout << st.at(i);
		char c = (char)st.at(i);
		//if (c == ' ') {
			cout << c;
		//}
	}
	
}