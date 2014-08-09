/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

思路：
先统计 T 中各字符都有多少个，然后两个下标一前(i)一后(j)在 S 上跑， 当 i 跑到把 T 中字符都包含的位置时候，让 j 追到
第一个包含 T 的字符的地方，更新结果，去掉 j 这个位置字符的统计，让 i 继续跑，如此反复。
*/
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	string minWindow(string S, string T) {
		vector<int> cnt(256, 0), need(256, 0);
		int sum = 0, len = 0x7fffffff;
		//统计T
		for (int i = 0; i < T.length(); i++) {
			need[T[i]] += 1;
		}

		string ans;
		// i is fast pointer; j is slow pointer
		for (int i = 0, j = 0; i < S.length(); j++) {
			while (i < S.length() && sum < T.length()) {
				if (cnt[S[i]] < need[S[i]]) {
					sum++;
				}
				cnt[S[i]] ++;
				i++;
			}
			while (sum == T.length() && j < S.length()) {
				cnt[S[j]] --;
				if (cnt[S[j]] < need[S[j]]) {
					break;
				}
				j++;
			}

			if (sum < T.length()) break;

			if (i - j < len) {
				ans = S.substr(j, i - j), len = i - j;
			}
			sum--;
		}
		return ans;
	}
};