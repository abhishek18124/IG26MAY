
#include<iostream>
#include<queue>

using namespace std;

string reorganise(string str) {

    int freqMap[26] = {0};
    for (char ch : str) {
        freqMap[ch - 'a']++;
    }

    priority_queue<pair<int, char>> maxHeap;
    for (int i = 0; i < 26; i++) {
        if (freqMap[i] > 0) {
            maxHeap.push({freqMap[i], i + 'a'});
        }
    }

    // while (!maxHeap.empty()) {
    //     pair<int, char> p = maxHeap.top();
    //     cout << p.first << " " << p.second << endl;
    //     maxHeap.pop();
    // }

    string ans = "";

    while (!maxHeap.empty()) {

        if (maxHeap.size() == 1) {
            pair<int, char> maxPair = maxHeap.top();
            maxHeap.pop();
            if (maxPair.first == 1) {
                ans += maxPair.second;
            } else {
                ans = "";
            }
        } else {
            // maxHeap.size() >= 2
            pair<int, char> fMaxPair = maxHeap.top();
            maxHeap.pop();

            pair<int, char> sMaxPair = maxHeap.top();
            maxHeap.pop();

            ans += fMaxPair.second;
            fMaxPair.first--;

            ans += sMaxPair.second;
            sMaxPair.first--;

            if (fMaxPair.first > 0) {
                maxHeap.push(fMaxPair);
            }

            if (sMaxPair.first > 0) {
                maxHeap.push(sMaxPair);
            }

        }


    }

    return ans;

}

int main() {

    string str = "aaabca";

    cout << reorganise(str) << endl;

    return 0;
}