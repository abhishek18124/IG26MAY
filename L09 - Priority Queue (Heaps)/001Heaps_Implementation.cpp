/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class minHeap {

	vector<int> v; // internal representation of minHeap

public:

	// time : O(logn)

	void push(int val) {
		v.push_back(val);
		int childIdx = v.size() - 1;
		int parentIdx = (childIdx - 1) / 2;

		while (childIdx != 0 and v[childIdx] < v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx = (childIdx - 1) / 2;
		}
	}

	void heapify(int i) {

		// fix the minHeap prop. at the ith index

		while (true) {

			int minIdx = i;
			int leftChildIdx = 2 * i + 1;
			if (leftChildIdx < (int)v.size() and v[leftChildIdx] < v[minIdx]) {
				minIdx = leftChildIdx;
			}

			int rightChildIdx = 2 * i + 2;
			if (rightChildIdx < (int)v.size() and v[rightChildIdx] < v[minIdx]) {
				minIdx = rightChildIdx;
			}

			if (minIdx == i) {
				break;
			}

			swap(v[i], v[minIdx]);

		}

	}

	void pop() {
		swap(v[0], v[v.size() - 1]);
		v.pop_back();
		heapify(0);

	}

	int top() {
		return v[0]; // time : O(1)
	}

	int size() {
		return v.size(); // time : O(1)
	}

	bool empty() {
		return v.empty(); // time : O(1)
	}

};

int main() {

	minHeap m;

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl;

	while (!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}`

	cout << endl;

	cout << m.size() << endl;

	return 0;
}



