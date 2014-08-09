/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
["aa","b"],
["a","a","b"]
]
解题思路：
　　因为要返回所有的回文分割，深搜是一种很自然的想法。
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isPalindrome(string str) {
		for (int i = 0, j = str.length() - 1; i <= j; i++, j--) {
			if (str[i] != str[j]) {
				return false;
			}
		}
		return true;
	}
	void search(string s, vector<string> cur_ans, vector<vector<string>> &ans) {
		if (s.empty()) {
			ans.push_back(cur_ans);
		}
		else {
			for (int len = 1; len <= s.length(); len++) {
				string str = s.substr(0, len);
				if (isPalindrome(str)) {
					cur_ans.push_back(str);
					search(s.substr(len), cur_ans, ans);
					cur_ans.pop_back();
				}
			}

		}
	}
	vector<vector<string>> partition(string s) {
		vector<string> cur_ans;
		vector<vector<string>> ans;
		search(s, cur_ans, ans);
		return ans;
	}
};