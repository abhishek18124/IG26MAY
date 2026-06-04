/*
		https://cplusplus.com/reference/utility/pair/?kw=pair

		This 'pair' class couples together a pair of values, which maybe of different
		types (T1 and T2).The individual values of a pair can be accessed through its
		public members first and second.
*/

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b
// otherwise return false

bool cmp(pair<string, int> a, pair<string, int> b) {
	// if (a.second < b.second) {
	// 	return true; // we are sorting in inc. order based on age so when aAge < bAge we want a to be ordered before b
	// } else {
	// 	return false;
	// }

	return a.second < b.second;
}

int main() {

	pair<int, int> p1;
	p1.first = 10;
	p1.second = 20;

	// cout << p1.first << " " << p1.second << endl;

	pair<string, int> p2;
	p2.first = "komal";
	p2.second = 19;

	// cout << p2.first << " " << p2.second << endl;

	pair<char, char> p3;
	p3.first = 'A';
	p3.second = 'B';

	// cout << p3.first << " " << p3.second << endl;

	pair<string, int> p4 = {"india", 1947};

	// cout << p4.first << " " << p4.second << endl;

	vector<pair<string, int>> v;

	v.push_back({"komal", 19});
	v.push_back({"ananshi", 18});
	v.push_back({"himanshi", 17});
	v.push_back({"drishti", 21});
	v.push_back({"bhakti", 20});

	for (pair<string, int> p : v) {
		string name = p.first;
		int age = p.second;
		cout << name << " " << age << endl;
	}

	cout << endl;

	for (auto [name, age] : v) {
		cout << name << " " << age << endl;
	}

	cout << endl;

	// sort(v.begin(), v.end());
	// sort(v.rbegin(), v.rend());
	sort(v.begin(), v.end(), cmp);

	// when you sort a vector of pair
	// by default sorting is done on the 1st member of the pair

	for (pair<string, int> p : v) {
		string name = p.first;
		int age = p.second;
		cout << name << " " << age << endl;
	}

	return 0;
}