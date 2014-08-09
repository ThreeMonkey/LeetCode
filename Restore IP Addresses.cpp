/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		if (s.empty() || s.length() > 12) return ans;

		dfs(s, "", 0, ans);
		return ans;
	}
	void dfs(string s, string left_part, int cur, vector<string> &ans) {
		if (cur == 3 && isValid(s)) {
			// record answear
			ans.push_back(left_part + s);
			return;
		}
		for (int i = 1; i < 4 && i < s.length(); i++) {
			string substr = s.substr(0, i);
			if (isValid(substr)) {
				dfs(s.substr(i), left_part + substr + ".", cur + 1, ans);
			}
		}
	}
	bool isValid(string str) {
		if (str[0] == '0') return str == "0";
		int num = stoi(str);
		return (num >0 && num <= 255);
	}
};