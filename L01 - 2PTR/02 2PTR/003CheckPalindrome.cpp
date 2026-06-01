#include<iostream>

using namespace std;

// time : n/2.const ~ O(n)

bool isPalindrome(const string& s) {
	int n = (int)s.size();
	int i = 0;
	int j = n - 1;

	while (i < j) {
		if (s[i] != s[j]) {
			// s is not a palindrome
			return false;
		}
		i++;
		j--;
	}

	// s is a palindrome
	return true;

}

int main() {

	string s = "abcba";

	if (isPalindrome(s)) {
		cout << "palindrome" << endl;
	} else {
		cout << "not palindrome" << endl;
	}

	return 0;
}