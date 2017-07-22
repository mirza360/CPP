// Anita's Experiment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cmath>

using namespace std;
int main()
{
	int T;
	cin >> T;
	if (T > 0 && T <= 50) {
		for (int idx1 = 0;idx1 < T;idx1++) {
			int N;
			cin >> N;
			if (N >= 2 && N <= 1000) {
				int *array = new int[N + 1];
				//All Good All Bad Neutral Variables
				int allgood = 0;
				int allbad = 0;
				int neutral = 0;
				//End of all good bad neutral variants with -1 breaking and 1 successful
				//beginning of special day variants
				int sp[2];
				sp[0] = 0;
				sp[1] = 0;
				int tmp = 0;
				int go = 1;
				//Start of array element input
				for (int idx = 0;idx < N;idx++) {
					int val;
					cin >> val;
					if (abs(val) <= pow(10, 6)) {
						array[idx] = abs(val);
						//End of Array Element input
						//Start of All Good All Bad Neutral check
						if (idx != 0) {
							//start of all neutral checker
							if (neutral != -1 && array[idx] == array[idx - 1]) {
								neutral = 1;
							}
							else {
								neutral = -1;
								//Start all good checker
								if (allgood != -1 && array[idx] >= array[idx - 1]) {
									allgood = 1;
								}
								else {
									allgood = -1;
								}
								//end of all good checker
								//start of all bad checker
								if (allbad != -1 && array[idx] <= array[idx - 1]) {
									allbad = 1;
								}
								else {
									allbad = -1;
								}
								//end of all bad checker
							}
							//end of neutral checker


						}
						//End of All Good All Bad Neutral check
						//Start of Special Day Counting
						if (idx > 2 && idx < N - 1) {
							//finding special day
							if (array[idx]<array[idx - 1] && array[idx - 1]>array[idx - 2]) {
								//found special day
								//having the first 2 special days
								if (sp[0] == 0) {
									sp[0] = idx - 1;

								}
								else if (sp[1] == 0) {
									sp[1] = idx - 1;
								}

								//end of finding first 2 special days
								else {
									if ((sp[1] - sp[0]) < (idx - 1) - sp[1] && tmp == 0) {
										sp[0] = sp[1];
										sp[1] = idx - 1;
									}
									else if ((sp[1] - sp[0]) > (idx - 1) - sp[1] && tmp == 0) {
										tmp = idx - 1;
									}
									else if ((sp[1] - sp[0]) < (idx - 1) - tmp) {
										sp[0] = tmp;
										sp[1] = idx - 1;
										tmp = 0;
									}
								}
							}
						}
					}

					
				}
				//Printing the result
				if (go > 0) {
					if (allgood == 1) {
						cout << "allGoodDays" << endl;
					}
					else if (allbad == 1) {
						cout << "allBadDays" << endl;
					}
					else if (neutral == 1) {
						cout << "neutral" << endl;
					}
					else if (sp[1] - sp[0]>0) {
						cout << (sp[1] - sp[0]) - 1 << endl;
					}
					else {
						cout << "none"<<endl;
					}
				}

			}

		}
	}
    return 0;
}

