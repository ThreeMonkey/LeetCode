/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	bool match(char a, char b) {
		return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
	}

	bool isValid(string s) {
		stack<char> stk;
		for (int i = 0; i < s.size(); i++) {
			if (stk.empty() || (!match(stk.top(), s[i]))) {
				stk.push(s[i]);
			}
			else {
				stk.pop();
			}
		}
		return stk.empty();
	}
};