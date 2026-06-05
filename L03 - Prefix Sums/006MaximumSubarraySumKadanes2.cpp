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
typedef long long ll;

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// time : O(n)
	// space: O(1)

	int x = arr[0]; // at present x hold x[0]
	int maxSoFar = x;

	for (int i = 1; i < n; i++) {
		x = max(x + arr[i], arr[i]);
		maxSoFar = max(maxSoFar, x);
	}

	cout << maxSoFar << endl;


	return 0;
}