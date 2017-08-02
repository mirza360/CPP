// assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"book.h"
#include<fstream>
#include<string>
#include <cctype>
//#include"book.cpp"


int main()
{
	book b;
	string line;
	ifstream myfile;
	myfile.open("file.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//cout << line<<endl;
			b.tokenize(line);
		}
		b.print();
		myfile.close();

	}
	//cout<<b.tokenize("Hello My Love");
	
    return 0;
}

