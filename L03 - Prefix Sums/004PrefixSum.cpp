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

	vector<int> pSum(n);
	pSum[0] = arr[0];


	// pSum[1] = pSum[0] + arr[1]
	// pSum[2] = pSum[1] + arr[2]
	// ...
	// pSum[i] = pSum[i-1] + arr[i]

	for (int i = 1; i < n; i++) {
		pSum[i] = pSum[i - 1] + arr[i];
	}

	// time : O(n)

	for (int i = 0; i < n; i++) {
		cout << pSum[i] << " ";
	}

	cout << endl;

	return 0;
}