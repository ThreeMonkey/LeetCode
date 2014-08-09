/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

解题思路：

　　方法一：利用深搜， 复杂度太高，导致超时

  　方法二：利用dp来做， dp[i][j] 表示s[i..j]可以被成功分割，则 dp[i][j] = dp[i][k] && dp[k+1][j] { i <= k <j}

	方法三：同Word Break II , 利用DP来做。

此处采用方法二，复杂度为O（n^2)，方法三的空间复杂度会更低，代码如下：
*/
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		int n = s.length();
		vector<vector<bool>> in_dict(n, vector<bool>(n, false));// in_dict[j..i] means: s[j..i] can be beaked
		//init
		for (int i = 0; i < n; i++) {
			if (dict.count(s.substr(i, 1))) in_dict[i][i] = true;
		}

		for (int len = 2; len <= n; len++) {
			for (int start = 0; start <= n - len; start++) {
				string str = s.substr(start, len);
				if (dict.count(str)) in_dict[start][start + len - 1] = true;
				for (int i = start; i < start + len - 1; i++) {
					if (in_dict[start][i] && in_dict[i + 1][start + len - 1]) {
						in_dict[start][start + len - 1] = true;
						break;
					}
				}
			}
		}
		return in_dict[0][n - 1];
	}
};