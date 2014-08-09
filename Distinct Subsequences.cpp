/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence 
of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

解题思路：
使用动态规划：设dp[i][j]表示S的前i个字符和T的前j个字符中的解。

if (S[i - 1] == T[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; //意思是：如果当前S[i]==T[j]，那么当前这个字母既可以保留
                                                                      //也可以抛弃，所以变换方法等于保留这个字母的变换方法加上
																	  //不用这个字母的变换方法。

else dp[i][j] = dp[i-1][j]; //如果当前字符不等，那么就只能抛弃当前这个字符
*/
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int numDistinct(string S, string T) {
		int rows = S.length(), cols = T.length();
		vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
		for (int i = 0; i < rows; i++) {
			dp[i][0] = 1; // if T is empty, every S has 1 match
		}

		for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= cols; j++) {
				if (S[i - 1] == T[j - 1]) {
					// have two situation
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[rows][cols];
	}
};