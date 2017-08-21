// lab15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
int fib(int n);
double series(int n);
using namespace std;

int main()
{
	/*cout << "Fibonacci n =";
	int fibN;
	cin >> fibN;
	cout << fib(fibN);*/

	cout << " n =";
	int n;
	cin >> n;
	cout << series(n)<< endl;
	cout << fib(n) << endl;
    return 0;
}
int fib(int n) {
	int nthFib = 0;
	if (n <= 2) {
		return 1;
	}
	else {
		nthFib = fib(n - 1) + fib(n - 2);
	}
	return nthFib;
}

double series(int n) {
	double sum=0.0;
	if (n == 0) {
		return 1;
	}
	else {
		sum = (1 / pow(2, n)) + series(n - 1);
	}
	return sum;
}