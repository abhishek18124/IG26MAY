// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:

	// time : O(n^2) : TLE since n <= 10^5

	int maxArea(vector<int>& height) {

		int maxSoFar = 0;

		int n = (int)height.size();

		for (int i = 0; i <= n - 2; i++) {
			for (int j = i + 1; j <= n - 1; j++) {
				int w = j - i;
				int h = min(height[i], height[j]);
				int a = w * h;
				maxSoFar = max(maxSoFar, a);
			}
		}

		return maxSoFar;

	}
};