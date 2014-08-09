/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	//使用递归，结果超时。。。。
	/*int numDecodings(string s) {
	if (s.length() <= 1) return s.length();

	int begin_of_one = numDecodings(s.substr(1));
	int begin_of_two = 0;
	if (s.length() > 1 && s[0] < '3' && s[1] < '7') begin_of_two = numDecodings(s.substr(2));
	return begin_of_one + begin_of_two;
	}*/
	int numDecodings(string s) {
		if (s.empty()) return 0;

		vector<int> dp(s.length() + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < s.length(); i++) {
			dp[i + 1] = (s[i] == '0' ? 0 : dp[i]) + ((i - 1) >= 0 && s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) <= 26 ? dp[i - 1] : 0);
		}
		return dp[s.length()];
	}
};

class Solution {
public:
	int check(char one) {
		return (one >= '1' && one <= '9') ? 1 : 0;
	}
	int check(char one, char two) {
		return (one == '1' || (one == '2' && two <= '6')) ? 1 : 0;
	}

	int numDecodings(string s) {
		if (s.empty()) return 0;
		if (s.length() == 1) return check(s[0]);

		vector<int> dp(s.length(), 0); // dp[i] 表示： 字符串 s[0..i]可以被译码的方法数
		dp[0] = check(s[0]);
		dp[1] = (check(s[0]) & check(s[1])) + check(s[0], s[1]);
		for (int i = 2; i < s.length(); i++) {
			if (check(s[i])) dp[i] += dp[i - 1];
			if (check(s[i], s[i - 1])) dp[i] += dp[i - 2];
		}
		return dp[s.length() - 1];
	}
};