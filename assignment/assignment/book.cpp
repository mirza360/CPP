#include "stdafx.h"
#include "book.h"
#include<iostream>
#include<string>
using namespace std;
book::book()
{
}
void book::tokenize(string st)
{
	//cout << endl << st.size() << endl;
	string word = "";
	string snt = "";
	//running a loop where each char of st will be assigned to c
	for (int idx = 0; idx < (int)st.size(); idx++) {
		if ((int)st.at(idx) >= 0 && (int)st.at(idx) <= 255) {


			char c = st.at(idx);
			c = tolower(c);
			//dot operation
			if (c != '.' && !isspace(c) && !ispunct(c) && c != '\n') {

				word += c;
			}
			else if (c == '.' || c == ' ' || c == '\n') {

				//got our word ready!


				if (!word.empty()) {
					wCount++;

					//cout << "Word # " << wCount << " : ";
					//cout << word << endl;
					//return word;
					insert(word);
					//word.erase();
				}
				

			}
			



		}

	}



	//return string();
}
void book::insert(string st)
{
	//word to int conversion
	int res = 0;
	for (int idx = 0; idx < (int)st.size(); idx++) {
		res += (int)st.at(idx);
	}
	//finding the position for the hash table
	res = res%pNum;
	//conversion to number ends
	//--create the word node
	if (HashArray[res] == NULL) {
		HashArray[res] = new Hash();
	}
	insertHash(st, HashArray[res]);
	
}

void book::insertHash(string key, Hash *&HashArr)
{
	HashArr->total++;
	HashArr->head = wrdLink(HashArr->head);
}

Word * book::wrdLink(Word * w)
{
	return nullptr;
}



void book::print()
{
}
book::~book()
{
}
