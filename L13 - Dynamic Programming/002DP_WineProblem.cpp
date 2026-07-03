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

// time : O(n^2)
// space: O(n^3)

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

int dp[100][100][101]; // n <= 100

int fTopdown(const vector<int>& p, int i, int j, int y) {

	// lookup
	if (dp[i][j][y] != -1) {
		return dp[i][j][y];
	}

	// base case

	if (i == j) {
		return dp[i][j][y] = p[i] * y;
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide the bottle to sell in the y year

	// option 1 : sell the ith bottle

	// option 2 : sell the jth bottle

	return dp[i][j][y] = max(y * p[i] + fTopdown(p, i + 1, j, y + 1),
	                         y * p[j] + fTopdown(p, i, j - 1, y + 1));

}

int main() {

	vector<int> p = {2, 3, 5, 1, 4};
	int n = p.size();

	cout << f(p, 0, n - 1, 1) << endl;

	memset(dp, -1, sizeof(dp));

	cout << fTopdown(p, 0, n - 1, 1) << endl;

	return 0;
}