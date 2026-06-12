#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// time : O(n)
// space: O(n) due to monotonic stack

vector<int> f(vector<int> A) {

	int n = (int)A.size();

	stack<int> stk; // monotonic stack
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest greater element to the right
		// of A[i] with the help of the monotonic stack

		while (!stk.empty() and stk.top() <= A[i]) {
			stk.pop();
		}

		if (stk.empty()) {
			// there is no greater element to the right of A[i]
			ans.push_back(-1);
		} else {
			ans.push_back(stk.top());
		}

		stk.push(A[i]);

	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}