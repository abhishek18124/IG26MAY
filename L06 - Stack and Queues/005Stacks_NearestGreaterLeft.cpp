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

	for (int i = 0; i < n; i++) {

		// find the nearest greater element to the left
		// of A[i] with the help of the monotonic stack

		while (!stk.empty() and stk.top() <= A[i]) {
			stk.pop();
		}

		if (stk.empty()) {
			// there is no greater element to the left of A[i]
			ans.push_back(-1);
		} else {
			ans.push_back(stk.top());
		}

		stk.push(A[i]);

	}


	return ans;
}

int main() {

	vector<int> A = {5, 2, 0, 4, 1, 3, 6};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}