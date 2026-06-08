#include<iostream>
#include<vector>

using namespace std;

// time : n + n + 26 = 2n + 26 ~ O(n)
// space: 26 + 26 ~ O(1)

bool isAnagram(string s1, string s2) {

	// 1. build a freqMap for s1

	vector<int> f1(26, 0);
	for (char ch : s1) { // n
		int idx = ch - 'a';
		f1[idx]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << f1[i] << " ";
	}
	cout << endl;

	// 2. build a freqMap for s2
	vector<int> f2(26, 0);
	for (char ch : s2) { // n
		f2[ch - 'a']++;
	}


	for (int i = 0; i < 26; i++) {
		cout << f2[i] << " ";
	}
	cout << endl;

	// 3. compare the freqMaps
	for (int i = 0; i < 26; i++) { // 26
		if (f1[i] != f2[i]) {
			// s1 and s2 cannot be anagrams
			return false;
		}
	}

	// s1 and s2 are anagrams
	return true;

}

int main() {

	string s1 = "state";
	string s2 = "taste";

	if (isAnagram(s1, s2)) {
		cout << "anagrams" << endl;
	} else {
		cout << "not anagrams" << endl;
	}

	return 0;

}