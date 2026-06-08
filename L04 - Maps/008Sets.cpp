/*

	https://cplusplus.com/reference/set/set/?kw=set
	https://cplusplus.com/reference/set/multiset/?kw=multiset

	> insert/erase/find is logarithmic i.e. O(logn)
	> values are inserted in the sorted order
	> set contains only distinct values
	> multiset allows duplicate values

*/

#include<iostream>
#include<set>

using namespace std;

int main() {

	set<int> s;

	cout << s.size() << endl;

	s.insert(30);
	s.insert(10);
	s.insert(20);
	s.insert(10); // ignore

	cout << s.size() << endl;

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.erase(30);

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	int key = 100;

	if (s.find(key) != s.end()) {
		cout << key << " found" << endl;
	} else {
		cout << key << " not found" << endl;
	}

	if (s.count(key)) {
		cout << key << " found" << endl;
	} else {
		cout << key << " not found" << endl;
	}

	return 0;
}