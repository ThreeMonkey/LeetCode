/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		if (s.length() == 0) {
			return 0;
		}
		int ans = 0;
		map<char, int> dic;
		dic['I'] = 1, dic['V'] = 5, dic['X'] = 10, dic['L'] = 50, dic['C'] = 100, dic['D'] = 500, dic['M'] = 1000;

		char first = s[0];
		for (int i = 1; i < s.length(); i++) {
			if (dic[s[i]] <= dic[first]) {
				ans += dic[first];
			}
			else {
				ans -= dic[first];
			}
			first = s[i];
		}
		return ans + dic[first];
	}
};