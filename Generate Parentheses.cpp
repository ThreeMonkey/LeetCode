/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> ans;
	string cur_ans;
	void dfs(int left, int right, int n) {
		if (left == right && left == n) {
			ans.push_back(cur_ans);
			return;
		}
		else {
			if (left < n) {
				cur_ans[left + right] = '(';
				dfs(left + 1, right, n);
				cur_ans[left + right] = ' ';
			}

			if (left > right) { // ø…“‘º””“¿®∫≈
				cur_ans[left + right] = ')';
				dfs(left, right + 1, n);
				cur_ans[left + right] = ' ';
			}
		}
	}

	vector<string> generateParenthesis(int n) {
		cur_ans.resize(n << 1);
		dfs(0, 0, n);
		return ans;
	}
};