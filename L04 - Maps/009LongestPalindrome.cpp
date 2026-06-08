#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {

	string str = "abccccdd";

	set<char> s;
	int ans = 0;

	for (char ch : str) {
		if (s.find(ch) == s.end()) {
			// ch is not in set<>
			s.insert(ch);
		} else {
			// ch is already in set<>
			s.erase(ch);
			ans += 2;
		}
	}

	if (!s.empty()) {
		ans++;
	}

	cout << ans << endl;

	return 0;
}