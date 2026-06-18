#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> prefixXOR(n); // time : O(n)
	prefixXOR[0] = arr[0];
	for (int i = 1; i < n; i++) {
		prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
	}

	while (q--) { // time : O(q)
		int a, b;
		cin >> a >> b;
		a--; b--; // we do this to convert into 0-based indexing
		int ans = a == 0 ? prefixXOR[b] : prefixXOR[b] ^ prefixXOR[a - 1];
		cout << ans << endl;
	}

	// time : n + q ~ O(n+q)
	// space: O(n) due to prefixXOR array


	return 0;
}