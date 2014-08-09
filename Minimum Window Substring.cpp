/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

˼·��
��ͳ�� T �и��ַ����ж��ٸ���Ȼ�������±�һǰ(i)һ��(j)�� S ���ܣ� �� i �ܵ��� T ���ַ���������λ��ʱ���� j ׷��
��һ������ T ���ַ��ĵط������½����ȥ�� j ���λ���ַ���ͳ�ƣ��� i �����ܣ���˷�����
*/
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	string minWindow(string S, string T) {
		vector<int> cnt(256, 0), need(256, 0);
		int sum = 0, len = 0x7fffffff;
		//ͳ��T
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