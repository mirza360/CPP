// fileOp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
using namespace std;
int sCount = 0;
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
			//cout << line<<endl;
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
	cout << endl << st.size() << endl;
	string word = "";
	string snt = "";
	//running a loop where each char of st will be assigned to c
	for (int idx = 0; idx < (int)st.size(); idx++) {
		char c = st.at(idx);
		//get rid of punctuation
		if (!ispunct(c))
		{
			//making all lower case
			if ((int)c >= 65 && (int)c <= 90) {
				c = tolower(c);
			}
			//get rid of space
			if (!isspace(c)) {
				//put chars into the word
				word += c;
				//cout << word;
			}
			else {
				//increasing word count
				
				wCount++;
				cout << "Word # " << wCount << " : ";
				cout << word << endl;
				word = "";
				//got our word ready!

				//clearing the word variable to store the next one
				//word = "";
			}
			
			//word = "";

		}//else if()


	}

	//cout << snt;

}