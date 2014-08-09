/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//
//class Solution {
//public:
//	string expand(string s, int cl, int cr) {
//		int l = cl, r = cr;
//		int n = s.length();
//		while (l >= 0 && r <= n - 1 && s[l] == s[r]) {
//			l--;
//			r++;
//		}
//		return s.substr(l + 1, r - l - 1);
//	}
//	string longestPalindrome(string s) {
//		string ans;
//		if (s.size() == 0) return ans;
//		if (s.size() == 1) return s;
//
//		for (int center = 0; center < s.size(); center++) {
//			string odd = expand(s, center, center);
//			string even = expand(s, center, center + 1);
//			if (odd.size() > even.size()) {
//				if (odd.size() > ans.size()) {
//					ans = odd;
//				}
//			}
//			else {
//				if (even.size() > ans.size()) {
//					ans = even;
//				}
//			}
//		}
//
//		return ans;
//	}
//};

// see http://www.felix021.com/blog/read.php?2040
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 0) return "";
		if (s.size() == 1) return s;

		string T = preProcess(s);
		vector<int> p(T.length());  //P[i] 来记录以字符S[i]为中心的最长回文子串向左/右扩张的长度
		                            //（包括S[i]，也就是把该回文串“对折”以后的长度）
		int id = 0, mx = 0;
		
		for (int i = 1; i < T.length(); i++) {
			p[i] = (mx > i) ? min(p[2 * id - i], mx - i) : 1;
			while (T[i + p[i]] == T[i - p[i]]) p[i]++;
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
		}

		// 找p[] 中的最大值
		int max_len = 0, center = 0;
		for (int i = 1; i < p.size(); i++) {
			if (p[i]> max_len) {
				max_len = p[i];
				center = i;
			}
		}
		return s.substr((center - max_len) / 2, max_len - 1); // T = 2 * s + 2; s = (T-2)/2; Tstart = center - (len-1) + 1
		// Sstart = (center - len)/2
	}
private:
	string preProcess(string s) {
		string ret = "^";
		for (int i = 0; i < s.length; i++) {
			ret += ("#" + s[i]);
		}
		ret += "#$";
		return ret;
	}
};

