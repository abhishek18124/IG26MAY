
// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:

	// time : O(n)
	// space: O(1)

	int trap(vector<int>& height) {

		int n = (int)height.size();

		int i = 0;
		int j = n - 1;

		int ans = 0;

		int l = 0;
		int r = 0;

		while (i <= j) {

			l = max(l, height[i]);
			r = max(r, height[j]);

			if (l < r) {
				int wi = l - height[i];
				i++;
				ans += wi;
			} else {
				// r <= l
				int wj = r - height[j];
				j--;
				ans += wj;
			}

		}

		return ans;

	}
};