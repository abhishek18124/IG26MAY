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

// time : O(n^3)

int maximumSubarraySum(vector<int> arr, int n) {

	int maxSoFar = INT_MIN;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// find the sum of the subarray
			// that starts at the ith index
			// and ends at the jth index
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += arr[k];
			}
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