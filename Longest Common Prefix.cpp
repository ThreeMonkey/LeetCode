/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string ans;
		if (strs.size() == 0) return ans;
		if (strs.size() == 1) return strs[0];

		string shortest_str = strs[0];
		for (int i = 0; i < strs.size(); i++) {
			if (strs[i].size() < shortest_str.size()) {
				shortest_str = strs[i];
			}
		}

		for (int i = 0; i < shortest_str.size(); i++) {
			for (int j = 0; j < strs.size(); j++) {
				if (strs[j][i] != shortest_str[i]) {
					return ans;
				}
			}
			ans += shortest_str[i];
		}
		return ans;
	}
};