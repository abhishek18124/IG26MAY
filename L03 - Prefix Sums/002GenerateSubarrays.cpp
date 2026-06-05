#include<iostream>
#include<vector>
typedef long long ll;

using namespace std;

// time : O(n^3)

void generateSubarrays(vector<int> a, int n) {

	for (int i = 0; i < n; i++) {

		for (int j = i; j < n; j++) {

			// generate the subarray that
			// starts at the ith index &
			// ends at the jth index

			// cout << i << " " << j << endl;

			// i = 0 j = 3

			for (int k = i; k <= j; k++) {
				cout << a[k] << " ";
			}

			cout << endl;

		}

		cout << endl;

	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	generateSubarrays(a, n);

	return 0;
}