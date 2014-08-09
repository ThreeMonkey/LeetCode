/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

����˼·��
���ö�̬�滮��⡣

cutdp[i] ��ʾǰ i ���ַ���С�и�Ρ�

paldp[i][j] == true ��ʾ i ~ j �ǻ��ġ�

��ö�� i �� i ֮ǰ������ j �Ĺ����о͵õ��� paldp[j][i] �����л����жϣ������� i + 1��paldp[j][i + 1]���� s[j]��s[i + 1]��paldp[j + 1][i]
��O(1)�жϡ�

cutdp[i]Ϊ���� j (j < i)����paldp[j + 1][i] == true�� cutdp[j] + 1����Сֵ��ע��һ�±߽硣
*/
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		vector<vector<int>> paldp(s.length(), vector<int>(s.length())); // paldp[j][i] ��ʾ s[j..i]Ϊpalidrome
		vector<int> cutdp(s.length()); // ��ʾǰ i ���ַ���С�и��
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