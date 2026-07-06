#include<iostream>

using namespace std;

class ListNode {

public:
	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

int main() {

	ListNode* n = new ListNode(10);
	cout << n->val << endl;

	ListNode* n2 = new ListNode(20);
	cout << n2->val << endl;

	n->next = n2;
	// n2->next = n;

	return 0;
}