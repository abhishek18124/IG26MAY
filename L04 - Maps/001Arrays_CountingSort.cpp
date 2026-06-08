/*

e.g.

input
9 3
1 0 3 2 3 1 2 0 2

output
0 0 1 1 2 2 2 3 3

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 1. build a freqMap for the given arr[] : O(n)

	vector<int> freqMap(k + 1, 0);
	for (int i = 0; i < n; i++) {
		int x = arr[i];
		freqMap[x]++;
		// freqMap[arr[i]]++;
	}

	for (int i = 0; i <= k; i++) {
		cout << "freq[" << i << "] = " << freqMap[i] << endl;
	}

	// 2. transform the freqMap into a sorted array // time : O(n)

	for (int i = 0; i <= k; i++) {

		// print 'i' freqMap[i] times

		for (int j = 1; j <= freqMap[i]; j++) {
			cout << i << " ";
		}

	}

	// time : n + n = 2n ~ O(n)
	// space: O(k) due to freqMap

	return 0;
}