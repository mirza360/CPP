// Subarray Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin >> T;
	if (T >= 1 && T <= 10) {
		for (int tst = 0;tst < T;tst++) {
			int N;
			int K;
			cin >> N;
			cin >> K;
			int *arr = new int[N];
			int *sub = new int[K];
			sub[0] = 0;
			int kLim=0;
			int sum = 0;
			//testing at easy
			if (N >= 1 && N <= 50 && K >= 0 && K <= 50) {  
				for (int idx = 0;idx < N;idx++) {
					int val;
					cin >> val;
					if (val <= 100000) {
						arr[idx] = val;
						sum = sum + val;
						//Finding the lower indexes to replace
						if (val < 0) {
							if (kLim < K) {
								sub[kLim] = val;
								kLim++;
							}else {
								sort(sub, sub + K);
			
								for (int kId = 0;kId < K;kId++) {
									if (sub[kId] > val && sub[kId + 1] < val && kId<K-1) {
										for (int vx = kId;vx < K-1;vx++) {
											sub[vx + 1] = sub[vx];
										}
										sub[kId] = val;
										break;
									}
									else if (kId == K - 1 && sub[kId] > val) {
										sub[kId] = val;
									}
							}
						}
					}
						//End of Finding lower Index

					}
				}
			}
			

			//end of easy
			//Fixing the sum
			for (int d = 0;d < K;d++) {
				cout << sub[d]<<endl;
				sum = sum + abs(sub[d]);
			}
			cout << "Case " << T << ": " << sum << endl;
		}
	}
    return 0;
}

