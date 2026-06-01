// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:

	// time : O(n)

	int maxArea(vector<int>& height) {

		int maxSoFar = 0;

		int n = (int)height.size();

		int i = 0;
		int j = n - 1;

		while (i < j) {

			int w = j - i;
			int h = min(height[i], height[j]);
			int a = w * h;

			maxSoFar = max(maxSoFar, a);

			if (height[i] < height[j]) {
				i++;
			} else {
				j--;
			}

		}

		return maxSoFar;

	}
};