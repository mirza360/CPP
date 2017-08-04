#include "stdafx.h"
#include "Frequency.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
#include<vector>

using namespace std;
int main() {
	Frequency f;
	vector<Node*>fl=f.FileOpen("file.txt");

	//f.~Frequency();
	//Frequency f2;
	//f2.FileOpen("file3.txt");
	//f2.~Frequency();
	

	return 0;
}
