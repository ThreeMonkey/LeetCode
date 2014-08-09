/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

great
/    \
gr    eat
/ \    /  \
g   r  e   at
/ \
a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

rgeat
/    \
rg    eat
/ \    /  \
r   g  e   at
/ \
a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

  rgtae
 /    \
rg    tae
/ \    /  \
r   g  ta  e
/ \
t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		int s1_len = s1.length(), s2_len = s2.length();
		if (s1_len != s2_len) return false;
		if (s1_len == 0) return true;
		if (s1_len == 1) return s1[0] == s2[0];

		//ºı…Ÿµ›πÈ¥Œ ˝
		string s1_tmp = s1, s2_tmp = s2;
		sort(s1_tmp.begin(), s1_tmp.end());
		sort(s2_tmp.begin(), s2_tmp.end());
		if (s1_tmp != s2_tmp) return false;

		bool ans = false;
		for (int i = 1; i < s1_len && !ans; i++) {
			string s11 = s1.substr(0, i);
			string s12 = s1.substr(i);
			string s21 = s2.substr(0, i);
			string s22 = s2.substr(i);
			ans = isScramble(s11, s21) && isScramble(s12, s22);
			if (!ans) {
				string s31 = s2.substr(0, s1_len - i);
				string s32 = s2.substr(s1_len - i);
				ans = isScramble(s11, s32) && isScramble(s12, s31);
			}
		}
		return ans;
	}
};