#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> f(vector<int> A) {

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


int main() {

	vector<int> A = {2, 5, 1, 3, 6, 4, 0};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}