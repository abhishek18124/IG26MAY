
// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:

	// time : 3n ~ O(n)
	// space: n due to r[] ~ O(n)

	int trap(vector<int>& height) {

		int n = (int)height.size();

		vector<int> r(n);
		r[n - 1] = height[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			r[i] = max(r[i + 1], height[i]);
		}

		int ans = 0;
		int maxSoFar = height[0];

		for (int i = 0; i < n; i++) {
			// find the water trapped on top of the ith
			// building
			maxSoFar = max(maxSoFar, height[i]);
			int wi = min(maxSoFar, r[i]) - height[i];

			ans += wi;
		}

		return ans;

	}
};