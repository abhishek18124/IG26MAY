#include<iostream>
#include<vector>

using namespace std;

int main() {

	int m, n, q;
	cin >> m >> n >> q;

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

	while (q--) { // time : O(q)
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int ans = pSum[l2][r2];
		if (l1 > 0) ans -= pSum[l1 - 1][r2];
		if (r1 > 0) ans -= pSum[l2][r1 - 1];
		if (l1 > 0 and r1 > 0) ans += pSum[l1 - 1][r1 - 1];
		cout << ans << endl;
	}

	// total time : O(mn + q)
	// space : O(mn) due pSum[][]

	return 0;
}