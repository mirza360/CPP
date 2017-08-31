#pragma once
class queue
{
private:
	int size=30;
	int element=0;
	int *arr = new int[size];
	int head=-1;
	int tail=-1;
public:
	queue();
	queue(int x);
	void push(int x);
	int pop();
	void insert(int x, int idx);
	void print();
	void resizeArray(int x);
	int getSize();
	void manualPrint();
	~queue();
};

