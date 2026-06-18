#include<iostream>

using namespace std;

int main() {

	int a = 25;
	int b = 19;

	cout << "a&b : " << (a & b) << endl;
	cout << "a|b : " << (a | b) << endl;
	cout << "a^b : " << (a ^ b) << endl;
	cout << "~a  : " << (~a)  << endl;

	int x = 0;

	cout << ~x << endl;

	return 0;
}