#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> f(vector<int> A) {

	int n = (int)A.size();

	stack<int> stk; // monotonic stack of indices
	vector<int> ans;

	for (int i = 0; i < n; i++) {

		// find the span on the ith day

		// span on ith day = i - index of the nearest greater element to the left of A[i]

		// find the index of nearest greater element to the left
		// of A[i] with the help of the monotonic stack

		while (!stk.empty() and A[stk.top()] <= A[i]) {
			stk.pop();
		}

		int j;

		if (stk.empty()) {
			// there is no greater element to the left of A[i]
			j = -1;
		} else {
			j = stk.top();
		}

		ans.push_back(i - j);

		stk.push(i);

	}


	return ans;
}

int main() {

	vector<int> A = {100, 80, 60, 70, 60, 75, 85};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}