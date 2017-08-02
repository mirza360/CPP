#pragma once
#include<iostream>
using namespace std;


class book
{
	struct pos {
		pos * next = NULL;
		int position = 0;
	};

	struct Word {
		Word *next = NULL;
		string value = "";
		int total = 0;
		pos *side = NULL;
		pos *last = NULL;
	};

	struct Hash {
		int total = 0;
		Word * head = NULL;
	};
	/*
	struct HashLink {
	int value = -1;
	HashLink*next=NULL;
	};
	*/
	//global variables zone

public:
	//variables
	const int pNum = 1777;
	Hash* arr1[55];
	//functions
	book();




	~book();

};

