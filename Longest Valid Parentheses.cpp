/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> stk;  //store unmatched '(''s pos
		int ans = 0;
		int last_left = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				stk.push(i);
			}
			else {
				if (!stk.empty()) {
					stk.pop();
					if (!stk.empty()) {
						ans = max(ans, i - stk.top());
					}
					else {
						ans = max(ans, i - last_left + 1);
					}
				}
				else {
					last_left = i + 1;
				}
			}
		}
		return ans;
	}
};