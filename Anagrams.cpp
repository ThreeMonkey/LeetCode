/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		map<string, int> dict;
		for (int i = 0; i < strs.size(); i++) {
			string tmp = strs[i];
			//���������ַ�������
			sort(tmp.begin(), tmp.end());
			if (dict.find(tmp) != dict.end()) dict[tmp] += 1;
			else dict[tmp] = 1;
		}
		vector<string> ans;
		for (int i = 0; i < strs.size(); i++) {
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			if (dict[tmp] > 1) { //��ΪAnagrams�� �������ans����
				ans.push_back(strs[i]);
			}
		}
		return ans;
	}
};