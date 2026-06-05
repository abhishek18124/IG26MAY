#include<iostream>
#include<vector>

using namespace std;

int main() {

	int m, n;
	cin >> m >> n;

	vector<vector<int>> arr(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	// time : O(mn)
	// space : O(mn)

	vector<vector<int>> pSum(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			pSum[i][j] = arr[i][j];
			if (i > 0) pSum[i][j] += pSum[i - 1][j];
			if (j > 0) pSum[i][j] += pSum[i][j - 1];
			if (i > 0 and j > 0) pSum[i][j] -= pSum[i - 1][j - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << pSum[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}