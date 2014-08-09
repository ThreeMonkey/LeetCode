/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <string>
#include <map>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		map<int, string> dic;

		dic[1] = "I", dic[4] = "IV", dic[5] = "V", dic[9] = "IX", dic[10] = "X", dic[40] = "XL", dic[50] = "L", dic[90] = "XC", dic[100] = "C", dic[400] = "CD", dic[500] = 'D', dic[900] = "CM", dic[1000] = "M";

		string ans = "";
		while (num) {
			if (num >= 1000) {
				ans += dic[1000];
				num -= 1000;
			}
			else if (num >= 900) {
				ans += dic[900];
				num -= 900;
			}
			else if (num >= 500) {
				ans += dic[500];
				num -= 500;
			}
			else if (num >= 400) {
				ans += dic[400];
				num -= 400;
			}
			else if (num >= 100) {
				ans += dic[100];
				num -= 100;
			}
			else if (num >= 90) {
				ans += dic[90];
				num -= 90;
			}
			else if (num >= 50) {
				ans += dic[50];
				num -= 50;
			}
			else if (num >= 40) {
				ans += dic[40];
				num -= 40;
			}
			else if (num >= 10) {
				ans += dic[10];
				num -= 10;
			}
			else if (num >= 9) {
				ans += dic[9];
				num -= 9;
			}
			else if (num >= 5) {
				ans += dic[5];
				num -= 5;
			}
			else if (num >= 4) {
				ans += dic[4];
				num -= 4;
			}
			else if (num >= 1) {
				ans += dic[1];
				num -= 1;
			}
		}
		return ans;
	}
};