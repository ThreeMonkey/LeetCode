/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	Solution() {
		dict['1'] = { "" };
		dict['2'] = { "a", "b", "c" };
		dict['3'] = { "d", "e", "f" };
		dict['4'] = { "g", "h", "i" };
		dict['5'] = { "j", "k", "l" };
		dict['6'] = { "m", "n", "o" };
		dict['7'] = { "p", "q", "r", "s" };
		dict['8'] = { "t", "u", "v" };
		dict['9'] = { "w", "x", "y", "z" };
	}
	map<char, vector<string>> dict;
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		if (digits.size() == 0) {
			ans.push_back("");
			return ans;
		}
		if (digits.size() == 1) {
			vector<string> tmp = dict[digits[0]];
			for (int i = 0; i < tmp.size(); i++) {
				ans.push_back(tmp[i]);
			}
			return ans;
		}
		int len = digits.length();
		int mid = len >> 1;
		vector<string> left = letterCombinations(digits.substr(0, mid));
		vector<string> right = letterCombinations(digits.substr(mid, len));
		for (int i = 0; i < left.size(); i++) {
			for (int j = 0; j < right.size(); j++) {
				ans.push_back(left[i] + right[j]);
			}
		}
		return ans;
	}
};


// solution 2
class Solution {
public:
	const vector<string> v = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> ans;
	string tmp;
	void DFS(int cur, string d)
	{
		if (cur == d.length())
		{
			ans.push_back(tmp);
			return;
		}
		for (int i = 0; i < v[d[cur] - '0'].length(); i++)
		{
			tmp[cur] = v[d[cur] - '0'][i];
			DFS(cur + 1, d);
		}
	}
	vector<string> letterCombinations(string digits) {
		tmp.resize(digits.length());
		DFS(0, digits);
		return ans;
	}
};