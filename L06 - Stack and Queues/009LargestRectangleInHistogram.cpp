class Solution {
public:

	vector<int> f1(vector<int> A) {

		int n = (int)A.size();

		stack<int> stk; // monotonic stack of indices
		vector<int> ans;

		for (int i = n - 1; i >= 0; i--) {

			// find the index of the nearest smaller element to the right
			// of A[i] with the help of the monotonic stack

			while (!stk.empty() and A[stk.top()] >= A[i]) {
				stk.pop();
			}

			if (stk.empty()) {
				// there is no smaller element to the right of A[i]
				ans.push_back(n);
			} else {
				ans.push_back(stk.top());
			}

			stk.push(i);

		}

		reverse(ans.begin(), ans.end());
		return ans;
	}



	vector<int> f2(vector<int> A) {

		int n = (int)A.size();

		stack<int> stk; // monotonic stack of indices
		vector<int> ans;

		for (int i = 0; i < n; i++) {

			// find the index of the nearest smaller element to the left
			// of A[i] with the help of the monotonic stack

			while (!stk.empty() and A[stk.top()] >= A[i]) {
				stk.pop();
			}

			if (stk.empty()) {
				// there is no smaller element to the left of A[i]
				ans.push_back(-1);
			} else {
				ans.push_back(stk.top());
			}

			stk.push(i);

		}

		return ans;
	}

	// time : O(n)
	// space: O(n)

	int largestRectangleArea(vector<int>& heights) {

		vector<int> nsr = f1(heights);
		vector<int> nsl = f2(heights);

		int maxSoFar = 0;
		for (int i = 0; i < heights.size(); i++) {
			// find the bestArea for heights[i]
			int bestWidth = nsr[i] - nsl[i] - 1;
			int bestArea = bestWidth * heights[i];
			maxSoFar = max(maxSoFar, bestArea);
		}

		return maxSoFar;
	}

};