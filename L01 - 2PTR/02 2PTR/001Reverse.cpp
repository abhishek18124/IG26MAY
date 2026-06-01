#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> arr = {10, 20, 30, 40, 50};
	int n = (int)arr.size();

	// time : n/2.const ~ O(n)

	int i = 0;
	int j = n - 1;

	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}