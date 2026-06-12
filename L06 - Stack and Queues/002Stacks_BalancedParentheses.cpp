class Solution {
public:
	// time : O(n)
	// space: O(n) due to stk
	bool isValid(string s) {
		stack<char> stk;
		for (char ch : s) {
			switch (ch) {
			case '(': stk.push(ch); break;
			case '{': stk.push(ch); break;
			case '[': stk.push(ch); break;
			case ')': if (stk.empty() || stk.top() != '(') return false; else stk.pop(); break;
			case '}': if (stk.empty() || stk.top() != '{') return false; else stk.pop(); break;
			case ']': if (stk.empty() || stk.top() != '[') return false; else stk.pop(); break;
			}
		}
		return stk.empty();
	}
};
