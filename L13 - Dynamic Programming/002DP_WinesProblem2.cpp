/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year
you can sell the first or the last wine in the row. However, the price of wines increases
over time.

Let the initial prices of the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit
from the kth wine will be y*p_k.

Find the maximum profit from all the wines.

Example :
	Input : prices[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int f(const vector<int>& p, int i, int j, int y) {

	// base case

	if (i == j) {
		return p[i] * y;
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide the bottle to sell in the y year

	// option 1 : sell the ith bottle

	// option 2 : sell the jth bottle

	return max(y * p[i] + f(p, i + 1, j, y + 1),
	           y * p[j] + f(p, i, j - 1, y + 1));

}

int dp[100][100]; // n <= 100

// time : O(n^2)
// space: O(n^2)

int fTopdown(const vector<int>& p, int i, int j) {

	int n = (int)p.size();
	int y = n - j + i;

	// lookup
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	// base case

	if (i == j) {
		return dp[i][j] = p[i] * y;
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide the bottle to sell in the y year

	// option 1 : sell the ith bottle

	// option 2 : sell the jth bottle

	return dp[i][j] = max(y * p[i] + fTopdown(p, i + 1, j),
	                      y * p[j] + fTopdown(p, i, j - 1));

}

// time : O(n^2)
// space: O(n^2), can be optimised to O(n)

int fBottomUp(int n, const vector<int>& p) {
	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		// int j = i;
		// int y = n;
		// dp[i][j] = y * p[i];

		dp[i][i] = n * p[i];

	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			int y = n - j + i;
			dp[i][j] = max(y * p[i] + dp[i + 1][j],
			               y * p[j] + dp[i][j - 1]);
		}
	}

	return dp[0][n - 1]; // at the 0,n-1th index we store f(0,n-1)
}

int main() {

	vector<int> p = {2, 3, 5, 1, 4};
	int n = p.size();

	cout << f(p, 0, n - 1, 1) << endl;

	memset(dp, -1, sizeof(dp));

	cout << fTopdown(p, 0, n - 1) << endl;

	cout << fBottomUp(n, p) << endl;

	return 0;
}