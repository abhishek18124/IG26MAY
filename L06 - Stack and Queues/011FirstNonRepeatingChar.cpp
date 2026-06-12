#include<iostream>
#include<queue>
#include<map>

using namespace std;

int main() {

	char ch;
	queue<char> q;

	map<char, int> freqMap;

	while (true) {

		cin >> ch;

		if (ch == '.') break;

		freqMap[ch]++;
		if (freqMap[ch] == 1) {
			q.push(ch);
		}

		while (!q.empty() and freqMap[q.front()] > 1) {
			q.pop();
		}

		if (q.empty()) {
			cout << -1;
		} else {
			cout << q.front();
		}

	}

	return 0;
}