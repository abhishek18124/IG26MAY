#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> a = {10, 30, 50, 70};
	vector<int> b = {20, 40, 60};

	int n = (int)a.size();
	int m = (int)b.size();

	vector<int> c(n + m);

	int i = 0; // to iterate over a[]
	int j = 0; // to iterate over b[]
	int k = 0; // to iterate over c[]

	while (i <= n - 1 and j <= m - 1) {
		if (a[i] <= b[j]) {
			c[k] = a[i];
			i++;
			k++;
		} else {
			c[k] = b[j];
			j++;
			k++;
		}
	}

	while (i <= n - 1) {
		c[k] = a[i];
		i++;
		k++;
	}

	while (j <= m - 1) {
		c[k] = b[j];
		j++;
		k++;
	}

	// time : O(n+m)

	for (int x : c) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}