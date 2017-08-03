#pragma once
#include<iostream>
using namespace std;

struct pos {
	pos * next = NULL;
	int position = 0;
};

struct Word {
	Word *next = NULL;
	string key = "";
	int total = 0;
	pos *side = NULL;
	pos *last = NULL;
};

struct Hash {
	int total = 0;
	Word * head = NULL;
};
class book
{

	/*
	struct HashLink {
	int value = -1;
	HashLink*next=NULL;
	};
	*/
	//global variables zone

public:
	//variables
	int sCount = 0;
	int wCount = 0;
	const int pNum = 1777;
	Hash* HashArray[1777];
	//functions
	book();
	void tokenize(string st);
	void insert(string st);
	void insertHash(string key,Word *&h);
	void wrdLink(Word*& w,string key);
	void print();





	~book();

};
