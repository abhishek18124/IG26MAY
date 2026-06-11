#include<iostream>
#include<vector>

using namespace std;

// time : O(logn)

int firstOccurrence(vector<int> arr, int t) {
	int n = (int)arr.size();

	int ans = -1;

	int lo = 0;
	int hi = n - 1;

	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] == t) {
			ans = mid;
			hi = mid - 1;
		} else if (t > arr[mid]) {
			lo = mid + 1;
		} else {
			// t < arr[mid]
			hi = mid - 1;
		}
	}

	return ans;
}

int main() {

	vector<int> arr = {10, 20, 20, 20, 30, 30, 40, 40, 40};
	int t = 410;

	cout << firstOccurrence(arr, t) << endl;

	return 0;
}