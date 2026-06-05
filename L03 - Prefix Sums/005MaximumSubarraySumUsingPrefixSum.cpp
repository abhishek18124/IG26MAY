/*

https://cses.fi/problemset/task/1643/

input
5
-3 2 -1 4 -5

output
5

input
8
-1 3 -2 5 3 -5 2 2

output
9

*/
#include<iostream>
#include<vector>
#include<climits>
typedef long long ll;

using namespace std;

// time : n + n^2 ~ O(n^2)
// space: O(n) due to pSum[]u

int maximumSubarraySum(vector<int> arr, int n) {

	vector<int> pSum(n);
	pSum[0] = arr[0];


	// pSum[1] = pSum[0] + arr[1]
	// pSum[2] = pSum[1] + arr[2]
	// ...
	// pSum[i] = pSum[i-1] + arr[i]

	for (int i = 1; i < n; i++) {
		pSum[i] = pSum[i - 1] + arr[i];
	}

	int maxSoFar = INT_MIN;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// find the sum of the subarray
			// that starts at the ith index
			// and ends at the jth index

			// int sum;
			// if (i == 0) {
			// 	sum = pSum[j];
			// } else {
			// 	sum = pSum[j] - pSum[i - 1];
			// }

			int sum = (i == 0) ? pSum[j] : pSum[j] - pSum[i - 1];
			maxSoFar = max(maxSoFar, sum);
		}
	}

	return maxSoFar;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << maximumSubarraySum(arr, n) << endl;

	return 0;
}