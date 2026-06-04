#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b in the sorted output otherwise return false
bool cmp(string a, string b) {
	// if (a.size() > b.size()) {
	// 	return true;
	// } else {
	// 	return false;
	// }
	return a.size() < b.size();
}

int main() {

	// vector<int> arr = {20, 30, 10, 40, 50};

	// // sort(arr.begin(), arr.end());

	// sort(arr.rbegin(), arr.rend());

	// for (int i = 0; i < (int)arr.size(); i++) {
	// 	cout << arr[i] << " ";
	// }

	// cout << endl;

	vector<string> names = {"tushti",
	                        "himanshi",
	                        "ananshi",
	                        "isha",
	                        "komal"
	                       };

	// sort(names.begin(), names.end());
	// sort(names.rbegin(), names.rend());

	sort(names.begin(), names.end(), cmp);

	for (string& name : names) {
		cout << name << " ";
	}

	cout << endl;


	return 0;
}