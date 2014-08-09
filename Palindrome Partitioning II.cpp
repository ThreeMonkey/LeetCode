/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

解题思路：
采用动态规划求解。

cutdp[i] 表示前 i 个字符最小切割几次。

paldp[i][j] == true 表示 i ~ j 是回文。

在枚举 i 和 i 之前的所有 j 的过程中就得到了 paldp[j][i] 的所有回文判断，而对于 i + 1，paldp[j][i + 1]可由 s[j]、s[i + 1]、paldp[j + 1][i]
在O(1)判断。

cutdp[i]为所有 j (j < i)，当paldp[j + 1][i] == true的 cutdp[j] + 1的最小值。注意一下边界。
*/
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		vector<vector<int>> paldp(s.length(), vector<int>(s.length())); // paldp[j][i] 表示 s[j..i]为palidrome
		vector<int> cutdp(s.length()); // 表示前 i 个字符最小切割几次
		for (int i = 0; i < s.length(); i++) {
			cutdp[i] = 0x7fffffff;
			for (int j = i; j >= 0; j--) {
				if (s[j] == s[i] && (j + 1 >= i - 1 || paldp[j + 1][i - 1])) {
					paldp[j][i] = true;
					cutdp[i] = min(cutdp[i], (j > 0 ? cutdp[j - 1] + 1 : 0));
				}
				else {
					paldp[j][i] = false;
				}
			}
		}
		return cutdp[s.length() - 1];
	}
};