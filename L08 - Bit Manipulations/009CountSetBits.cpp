#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n = 2;
	int cnt = 0; // to track the no. of set bits in 'n'

	// time : logn

	while (n != 0) {
		int zerothBit = n & 1;
		if (zerothBit == 1) {
			cnt++;
		}

		// cnt = cnt + (n&1);
		n = n >> 1;
	}

	cout << cnt << endl;

	return 0;
}