#include<iostream>

using namespace std;
// time : O(logy)
// space: O(logy)
int f(int x, int y) {

	// base case

	if (y == 0) {
		// find pow(x, 0)
		return 1;
	}

	// recurseive case

	// f(x, y) : find pow(x, y)

	// 1. ask your friend to find pow(x, y/2)

	int A = f(x, y / 2);
	if (y % 2 == 0) {
		return A * A;
	} else {
		return A * A * x;
	}

}

int main() {

	int x = 3;
	int y = 4;

	cout << f(x, y) << endl;

	return 0;
}