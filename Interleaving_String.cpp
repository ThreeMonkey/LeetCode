/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

设状态f[i][j]，表示s1[0,i] 和s2[0,j]，匹配s3[0, i+j]。如果s1 的最后一个字符等
于s3 的最后一个字符，则f[i][j]=f[i-1][j]；如果s2 的最后一个字符等于s3 的最后一个字符，
则f[i][j]=f[i][j-1]。因此状态转移方程如下：
f[i][j] = (s1[i - 1] == s3 [i + j - 1] && f[i - 1][j]) || (s2[j - 1] == s3 [i + j - 1] && f[i][j - 1]);

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length()) return false;

		vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));

		for (int i = 0; i <= s1.length(); i++) {
			for (int j = 0; j <= s2.length(); j++) {
				if (i == 0 && j == 0) dp[i][j] = true; //空字串 为true;
				dp[i][j] = dp[i][j] || (i > 0 && s3[i + j - 1] == s1[i - 1] && dp[i - 1][j]);
				dp[i][j] = dp[i][j] || (j > 0 && s3[i + j - 1] == s2[j - 1] && dp[i][j - 1]);
			}
		}
		return dp[s1.length()][s2.length()];
	}
};