class Solution {
public:

	int f(const vector<int>& arr, int n, int k, int i) {

		// base case

		if (i == n) {
			return 0;
		}

		// recursive case

		// f(i) : find the maximum sum we can get from partitioning arr[i...n-1]

		// decide the next cut
		int maxSoFar = 0;
		int maxij = 0;
		for (int j = i; j <= i + k - 1 and j <= n - 1; j++) {
			maxij = max(maxij, arr[j]);
			maxSoFar = max(maxSoFar, (j - i + 1) * maxij + f(arr, n, k, j + 1));
		}

		return maxSoFar;

	}

	int fTopdown(const vector<int>& arr, int n, int k, int i, vector<int>& dp) {

		// lookup
		if (dp[i] != -1) {
			return dp[i];
		}

		// base case

		if (i == n) {
			return 0;
		}

		// recursive case

		// f(i) : find the maximum sum we can get from partitioning arr[i...n-1]

		// decide the next cut
		int maxSoFar = 0;
		int maxij = 0;
		for (int j = i; j <= i + k - 1 and j <= n - 1; j++) {
			maxij = max(maxij, arr[j]);
			maxSoFar = max(maxSoFar, (j - i + 1) * maxij + fTopdown(arr, n, k, j + 1, dp));
		}

		return dp[i] = maxSoFar;

	}

	int fBottomUp(const vector<int>& arr, int n, int k) {
		vector<int> dp(n + 1);
		dp[n] = 0; // at the nth index of dp[] we store f(n)
		for (int i = n - 1; i >= 0; i--) {
			// dp[i] = f(i) = find the maximum sum we can get from partitioning arr[i...n-1]
			// decide the next cut
			int maxSoFar = 0;
			int maxij = 0;
			for (int j = i; j <= i + k - 1 and j <= n - 1; j++) {
				maxij = max(maxij, arr[j]);
				maxSoFar = max(maxSoFar, (j - i + 1) * maxij + dp[j + 1]);
			}
			dp[i] = maxSoFar;
		}
		return dp[0]; // at the 0th index of dp[] we store f(0)
	}

	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int n = (int)arr.size();
		// return f(arr, n, k, 0);
		// vector<int> dp(n + 1, -1);
		// return fTopdown(arr, n, k, 0, dp);
		return fBottomUp(arr, n, k);
	}

};