#include<iostream>

using namespace std;

// time : O(n)
// space: O(n) due to function call stack

int f(int n) {

	// base case
	if (n == 0) {
		// f(0) : find 0!
		return 1;
	}

	// recursive case

	// f(n) : find n!

	// 1. ask your friend to find n-1!

	int A = f(n - 1);

	// 2. build the final answer using result you got back from your friend

	return n * A;

}

int main() {

	int n = 6;

	cout << f(n) << endl;

	return 0;
}