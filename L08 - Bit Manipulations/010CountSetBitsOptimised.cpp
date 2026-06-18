#include<iostream>

using namespace std;

int main() {

	int n = 20;
	cout << __builtin_popcount(n) << endl;
	cout << __builtin_popcountll(n) << endl;

	int cnt = 0; // to track the no. of set bits in 'n'

	while (n != 0) {

		// clear the rightmost set bit of n
		n = n & (n - 1);
		cnt++;

	}

	cout << cnt << endl;


	return 0;
}