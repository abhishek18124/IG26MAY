/*

    There are given n ropes of different lengths, we need to connect these ropes into one rope.
    The cost to connect two ropes is equal to the sum of their lengths. We need to connect the
    ropes with minimum cost.

    Example :

    Input : {4, 3, 2, 6}
    Output: 29

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

    vector<int> ropeLengths = {4, 3, 2, 6};

    // priority_queue<int, vector<int>, greater<int>> minHeap;
    // for (int rope : ropeLengths) {
    //     minHeap.push(rope);
    // }

    priority_queue<int, vector<int>, greater<int>> minHeap(
                ropeLengths.begin(),
                ropeLengths.end());

    int ans = 0; // to track minimized total cost

    while (minHeap.size() > 1) {

        int fS = minHeap.top(); minHeap.pop();
        int sS = minHeap.top(); minHeap.pop();

        int mergeCost = fS + sS;
        ans += mergeCost;

        minHeap.push(mergeCost);

    }

    cout << ans << endl;

    // time : O(nlogn)
    // space: O(n) due to minHeap

    return 0;
}