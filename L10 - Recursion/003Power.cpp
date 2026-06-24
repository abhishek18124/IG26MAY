#include<iostream>

using namespace std;
// time : O(y)
// space: O(y)
int f(int x, int y) {

	// base case

	if (y == 0) {
		// find pow(x, 0)
		return 1;
	}

	// recursive case

	// f(x, y) : find pow(x, y)

	// 1. ask your friend to find pow(x, y-1)

	int A = f(x, y - 1);

	// 2. use the answer from your friend to build the final answer

	return x * A;

}

int main() {

	int x = 3;
	int y = 4;

	cout << f(x, y) << endl;

	return 0;
}