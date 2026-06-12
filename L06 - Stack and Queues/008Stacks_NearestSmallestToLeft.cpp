#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> f(vector<int> A) {

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

int main() {

	vector<int> A = {0, 3, 5, 4, 1, 6, 2};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}