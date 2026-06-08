#include<iostream>
#include<vector>
#include<map>

using namespace std;

// time : O(nlogn)
// space: O(n) due to freqMap

bool isDuplicatePresent(vector<int> v) {

	map<int, int> freqMap;
	for (int x : v) {
		freqMap[x]++;
		if (freqMap[x] > 1) {
			// duplicate found
			return true;
		}
	}

	// for (pair<int, int> p : freqMap) {
	// 	int element = p.first;
	// 	int freq = p.second;
	// 	cout << element << " : " << freq << endl;
	// }

	return false; // no duplicates found

}

int main() {

	vector<int> v = {10, 20, 30};

	if (isDuplicatePresent(v)) {
		cout << "duplicate found\n";
	} else {
		cout << "duplicate not found\n";
	}

	return 0;
}