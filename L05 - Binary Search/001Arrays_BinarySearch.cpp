#include<iostream>
#include<vector>

using namespace std;

// time : O(logn)

int binarySearch(vector<int> arr, int t) {

	int n = (int)arr.size();

	int lo = 0;
	int hi = n - 1;

	while (lo <= hi) {
		int mid = lo + ((hi - lo) / 2);
		if (arr[mid] == t) {
			return mid;
		} else if (t > arr[mid]) {
			lo = mid + 1;
		} else {
			// t < arr[mid]
			hi = mid - 1;
		}
	}

	return -1;

}

int main() {

	vector<int> arr = {10, 20, 30, 40, 50};

	int t = 100;

	cout << binarySearch(arr, t) << endl;

	return 0;
}