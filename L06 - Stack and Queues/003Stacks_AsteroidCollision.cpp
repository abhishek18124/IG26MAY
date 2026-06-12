class Solution {
public:

	// time : 2n - 1 worst case ~ O(n)
	// space: O(n) due to stack
	vector<int> asteroidCollision(vector<int>& asteroids) {
		stack<int> stk;
		for (int ast : asteroids) {
			if (ast < 0 and !stk.empty() and stk.top() > 0) {
				// collisions will happen
				bool flag = true; // assume ast will survive the collisions
				while (!stk.empty() and stk.top() > 0) {
					if (abs(ast) > stk.top()) {
						stk.pop();
					} else if (abs(ast) < stk.top()) {
						// ast will be destroyed
						flag = false;
						break;
					} else {
						// abs(ast) == stk.top()
						// ast and stk.top() are both destroyed
						stk.pop();
						flag = false;
						break;
					}
				}
				if (flag) {
					// ast has survived all the collisions
					stk.push(ast);
				}
			} else {
				stk.push(ast);
			}
		}

		vector<int> ans;
		while (!stk.empty()) {
			ans.push_back(stk.top());
			stk.pop();
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};